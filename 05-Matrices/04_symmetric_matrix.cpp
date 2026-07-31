/*
Program Name: Special Matrices - Symmetric Matrix (Using Lower Triangular Mapping)


1. MATHEMATICAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Matrix M (n x n) is SYMMETRIC if M[i][j] == M[j][i] for all i, j.
   - The matrix is identical across its main diagonal (Lower Triangle == Upper Triangle).

2. INDEX MAPPING FORMULA:
----------------------------------------------------------------------------------------------------
   - We store ONLY the Lower Triangular elements in a 1D Array of size n * (n + 1) / 2.
   - For Get/Set at (i, j):
     * If i >= j: Use index = [i * (i - 1) / 2] + (j - 1)
     * If i < j : Swap indices -> Use index = [j * (j - 1) / 2] + (i - 1)

3. STEP-BY-STEP ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1 [Initialization]: Allocate 1D dynamic array of size `n * (n + 1) / 2`.
   - Step 2 [Set Operation]: If `i >= j`, store element at mapped lower-triangular index.
   - Step 3 [Get Operation]: If `i >= j`, compute index (i, j). Else compute index (j, i). Return value.
   - Step 4 [Display Operation]: Loop through full grid printing mapped values for all (i, j).

4. TIME COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Set(i, j, x) -> O(1)
   - Get(i, j)    -> O(1)
   - Display()    -> O(n^2)
====================================================================================================
*/

#include <iostream>
using namespace std;

class SymmetricMatrix {
private:
    int n;      // Matrix Dimension (n x n)
    int *A;     // Pointer to dynamic 1D Array storing lower triangular part

public:
    // Constructor: Allocates 1D array of size n*(n+1)/2 on Heap
    SymmetricMatrix(int n) {
        this->n = n;
        int totalNonZeros = n * (n + 1) / 2;
        A = new int[totalNonZeros];
    }

    // Set element at M[i][j] (1-based indexing)
    void Set(int i, int j, int x) {
        // Only store when i >= j to save half the space
        if (i >= j) {
            int index = (i * (i - 1) / 2) + (j - 1);
            A[index] = x;
        } else {
            // If i < j, store it in its symmetric position (j, i)
            int index = (j * (j - 1) / 2) + (i - 1);
            A[index] = x;
        }
    }

    // Get element at M[i][j] (1-based indexing)
    int Get(int i, int j) {
        if (i >= j) {
            int index = (i * (i - 1) / 2) + (j - 1);
            return A[index];
        } else {
            // Mirror reflection: M[i][j] == M[j][i]
            int index = (j * (j - 1) / 2) + (i - 1);
            return A[index];
        }
    }

    // Display the full 2D Symmetric Matrix
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) {
                    int index = (i * (i - 1) / 2) + (j - 1);
                    cout << A[index] << " ";
                } else {
                    int index = (j * (j - 1) / 2) + (i - 1);
                    cout << A[index] << " ";
                }
            }
            cout << endl;
        }
    }

    // Destructor: Deallocates heap memory
    ~SymmetricMatrix() {
        delete[] A;
    }
};

int main() {
    cout << "--- Symmetric Matrix Showcase ---" << endl;

    int dim = 4;
    SymmetricMatrix sm(dim);

    // Set elements for Lower Triangular part
    sm.Set(1, 1, 2);
    sm.Set(2, 1, 3); sm.Set(2, 2, 6);
    sm.Set(3, 1, 4); sm.Set(3, 2, 8); sm.Set(3, 3, 7);
    sm.Set(4, 1, 5); sm.Set(4, 2, 9); sm.Set(4, 3, 1); sm.Set(4, 4, 3);

    // Display Symmetric Matrix Output
    cout << "\nMatrix Output:" << endl;
    sm.Display();

    // Query elements (showing symmetric property M[i][j] == M[j][i])
    cout << "\nElement at (2,1): " << sm.Get(2, 1) << endl;
    cout << "Element at (1,2) [Symmetric Mirror]: " << sm.Get(1, 2) << endl;

    return 0;
}