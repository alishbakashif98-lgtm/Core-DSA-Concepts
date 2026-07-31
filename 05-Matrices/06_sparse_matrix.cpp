/*
Program Name: Special Matrices - Sparse Matrix Representation and Addition


1. SPARSE MATRIX DEFINITION:
----------------------------------------------------------------------------------------------------
   - A matrix containing a majority of zero elements.
   - Coordinate List (3-Column) Representation stores triplets: (row, col, value).

2. ADDITION ALGORITHM (Two-Pointer Technique):
----------------------------------------------------------------------------------------------------
   - Both matrices must have the exact same dimensions (m x n).
   - Traverse non-zero element arrays using pointers `i` and `j`.
   - Compare positions using row-major ordering:
     * If pos(s1[i]) < pos(s2[j]) -> Copy s1[i] to sum matrix.
     * If pos(s2[j]) < pos(s1[i]) -> Copy s2[j] to sum matrix.
     * If pos(s1[i]) == pos(s2[j]) -> Add values: sum.ele[k].x = s1[i].x + s2[j].x.

3. TIME & SPACE COMPLEXITY:
----------------------------------------------------------------------------------------------------
   - Time Complexity for Addition: O(num1 + num2) linear time pass.
   - Space Complexity: O(num1 + num2) to store non-zero sum elements.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Structure to hold individual non-zero element coordinates
struct Element {
    int i; // Row index
    int j; // Column index
    int x; // Value
};

class Sparse {
private:
    int m;          // Total rows
    int n;          // Total columns
    int num;        // Number of non-zero elements
    Element *ele;   // Dynamic array of non-zero elements

public:
    // Constructor
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }

    // Set element at specific index in non-zero array
    void SetElement(int index, int r, int c, int val) {
        if (index >= 0 && index < num) {
            ele[index].i = r;
            ele[index].j = c;
            ele[index].x = val;
        }
    }

    // Display Sparse Matrix in full 2D layout
    void Display() {
        int k = 0; // Pointer for non-zero array
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (k < num && ele[k].i == i && ele[k].j == j) {
                    cout << ele[k++].x << " "; // Print non-zero element
                } else {
                    cout << "0 ";              // Print zero
                }
            }
            cout << endl;
        }
    }

    // Function to add two Sparse Matrices
    Sparse Add(const Sparse &s) {
        // Condition: Dimensions must match
        if (m != s.m || n != s.n) {
            cout << "Dimensions do not match for addition!" << endl;
            return Sparse(0, 0, 0);
        }

        // Maximum possible non-zero elements in result
        Sparse *sum = new Sparse(m, n, num + s.num);

        int i = 0, j = 0, k = 0;

        while (i < num && j < s.num) {
            if (ele[i].i < s.ele[j].i) {
                sum->ele[k++] = ele[i++];
            } else if (ele[i].i > s.ele[j].i) {
                sum->ele[k++] = s.ele[j++];
            } else { // Same Row
                if (ele[i].j < s.ele[j].j) {
                    sum->ele[k++] = ele[i++];
                } else if (ele[i].j > s.ele[j].j) {
                    sum->ele[k++] = s.ele[j++];
                } else { // Same Row and Same Column -> Add values
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
                }
            }
        }

        // Copy remaining elements of first matrix
        for (; i < num; i++) sum->ele[k++] = ele[i];

        // Copy remaining elements of second matrix
        for (; j < s.num; j++) sum->ele[k++] = s.ele[j];

        sum->num = k; // Actual count of non-zero elements in sum matrix
        return *sum;
    }

    // Destructor
    ~Sparse() {
        delete[] ele;
    }
};

int main() {
    cout << "--- Sparse Matrix Representation & Addition ---" << endl;

    // Create First Sparse Matrix (5x5, 3 non-zero elements)
    Sparse s1(5, 5, 3);
    s1.SetElement(0, 2, 2, 10);
    s1.SetElement(1, 3, 4, 20);
    s1.SetElement(2, 5, 5, 30);

    // Create Second Sparse Matrix (5x5, 3 non-zero elements)
    Sparse s2(5, 5, 3);
    s2.SetElement(0, 1, 3, 5);
    s2.SetElement(1, 3, 4, 15);
    s2.SetElement(2, 4, 2, 25);

    cout << "\nMatrix 1 Output:" << endl;
    s1.Display();

    cout << "\nMatrix 2 Output:" << endl;
    s2.Display();

    // Add Matrices
    Sparse sum = s1.Add(s2);

    cout << "\nSum Matrix Output (s1 + s2):" << endl;
    sum.Display();

    return 0;
}