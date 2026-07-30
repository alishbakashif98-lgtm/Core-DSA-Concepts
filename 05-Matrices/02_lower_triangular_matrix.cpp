/*
Program Name: Special Matrices - Lower Triangular Matrix (Row-Major Mapping)


1. MATHEMATICAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Matrix M (n x n) is LOWER TRIANGULAR if:
     M[i][j] != 0  when i >= j  (Row index >= Column index)
     M[i][j] == 0  when i < j   (Above main diagonal)

2. INDEX MAPPING FORMULA (Row-Major Order):
----------------------------------------------------------------------------------------------------
   - Total Non-Zero Elements = n * (n + 1) / 2
   - Formula for (i, j) in 1D Array = [i * (i - 1) / 2] + (j - 1)  (1-based indexing)

3. STEP-BY-STEP ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1 [Initialization]: Allocate 1D array of size `n * (n + 1) / 2` on Heap.
   - Step 2 [Set Operation]: Check `i >= j`. If true, compute index and store `A[index] = x`.
   - Step 3 [Get Operation]: Check `i >= j`. If true, return `A[index]`. Else return `0`.
   - Step 4 [Display Operation]: Loop through grid; if `i >= j` print `A[index]`, else print `0`.

4. TIME COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Set(i, j, x) -> O(1)
   - Get(i, j)    -> O(1)
   - Display()    -> O(n^2)
====================================================================================================
*/

#include <iostream>
using namespace std;

class LowerTriangularMatrix {
private:
    int n;      // Matrix Dimension (n x n)
    int *A;     // Pointer to dynamic 1D Array for non-zero elements

public:
    // Constructor: Allocates 1D array of size n*(n+1)/2 on Heap
    LowerTriangularMatrix(int n) {
        this->n = n;
        int totalNonZeros = n * (n + 1) / 2;
        A = new int[totalNonZeros];
    }

    // Set element at M[i][j] using Row-Major formula (1-based indexing)
    void Set(int i, int j, int x) {
        if (i >= j) {
            int index = (i * (i - 1) / 2) + (j - 1); // Row-Major Indexing
            A[index] = x;
        }
    }

    // Get element at M[i][j] (1-based indexing)
    int Get(int i, int j) {
        if (i >= j) {
            int index = (i * (i - 1) / 2) + (j - 1);
            return A[index];
        }
        return 0; // Elements above diagonal (i < j) are always 0
    }

    // Display the full 2D Matrix format
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    int index = (i * (i - 1) / 2) + (j - 1);
                    cout << A[index] << " "; // Print non-zero element
                } else {
                    cout << "0 ";            // Print zero for upper region
                }
            }
            cout << endl;
        }
    }

    // Destructor: Deallocates heap memory
    ~LowerTriangularMatrix() {
        delete[] A;
    }
};

int main() {
    cout << "--- Lower Triangular Matrix (Row-Major) ---" << endl;

    int dim = 4;
    LowerTriangularMatrix lm(dim);

    // Set values for lower triangle
    for (int i = 1; i <= dim; i++) {
        for (int j = 1; j <= dim; j++) {
            if (i >= j) {
                lm.Set(i, j, i * 10 + j); // Example values: 11, 21, 22, 31...
            }
        }
    }

    // Display the matrix output
    cout << "\nMatrix Output:" << endl;
    lm.Display();

    // Retrieve specific elements
    cout << "\nElement at (3,2): " << lm.Get(3, 2) << endl;
    cout << "Element at (1,4): " << lm.Get(1, 4) << endl;

    return 0;
}