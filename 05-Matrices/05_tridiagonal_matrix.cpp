/*
Program Name: Special Matrices - Tridiagonal Matrix Implementation


1. MATHEMATICAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Matrix M (n x n) is TRIDIAGONAL if M[i][j] != 0 only when |i - j| <= 1.
   - Non-zero elements exist ONLY on three diagonals:
     * Lower Diagonal (i - j = 1)  -> n - 1 elements
     * Main Diagonal  (i - j = 0)  -> n elements
     * Upper Diagonal (j - i = 1)  -> n - 1 elements

2. INDEX MAPPING FORMULAS (1-based indexing):
----------------------------------------------------------------------------------------------------
   - Size of 1D Dynamic Array = 3n - 2
   - Case 1: Lower Diagonal (i - j == 1): Index = i - 2
   - Case 2: Main Diagonal  (i - j == 0): Index = (n - 1) + (i - 1)
   - Case 3: Upper Diagonal (j - i == 1): Index = (2n - 1) + (i - 1)

3. STEP-BY-STEP ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1 [Initialization]: Allocate 1D array of size `3n - 2` on Heap.
   - Step 2 [Set Operation]: Identify diagonal band using `i - j`, compute index, store value.
   - Step 3 [Get Operation]: If `|i - j| <= 1`, compute index and return value. Else return 0.
   - Step 4 [Display Operation]: Loop through matrix grid printing mapped values for valid bands.

4. TIME COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Set(i, j, x) -> O(1)
   - Get(i, j)    -> O(1)
   - Display()    -> O(n^2)
====================================================================================================
*/

#include <iostream>
using namespace std;

class TridiagonalMatrix {
private:
    int n;      // Matrix Dimension (n x n)
    int *A;     // Dynamic 1D Array of size 3n - 2

public:
    // Constructor: Allocates 1D array of size 3n - 2 on Heap
    TridiagonalMatrix(int n) {
        this->n = n;
        int totalNonZeros = 3 * n - 2;
        A = new int[totalNonZeros];
    }

    // Set element at M[i][j] (1-based indexing)
    void Set(int i, int j, int x) {
        if (i - j == 1) {
            // Lower Diagonal
            A[i - 2] = x;
        } else if (i - j == 0) {
            // Main Diagonal
            A[(n - 1) + (i - 1)] = x;
        } else if (j - i == 1) {
            // Upper Diagonal
            A[(2 * n - 1) + (i - 1)] = x;
        }
    }

    // Get element at M[i][j] (1-based indexing)
    int Get(int i, int j) {
        if (i - j == 1) {
            return A[i - 2];
        } else if (i - j == 0) {
            return A[(n - 1) + (i - 1)];
        } else if (j - i == 1) {
            return A[(2 * n - 1) + (i - 1)];
        }
        return 0; // Off-band elements are strictly 0
    }

    // Display the full 2D Tridiagonal Matrix
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - j == 1) {
                    cout << A[i - 2] << " ";
                } else if (i - j == 0) {
                    cout << A[(n - 1) + (i - 1)] << " ";
                } else if (j - i == 1) {
                    cout << A[(2 * n - 1) + (i - 1)] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Destructor: Deallocates heap memory
    ~TridiagonalMatrix() {
        delete[] A;
    }
};

int main() {
    cout << "--- Tridiagonal Matrix Showcase ---" << endl;

    int dim = 5;
    TridiagonalMatrix tm(dim);

    // Set Main Diagonal elements
    for (int i = 1; i <= dim; i++) tm.Set(i, i, 1);

    // Set Lower Diagonal elements
    for (int i = 2; i <= dim; i++) tm.Set(i, i - 1, 2);

    // Set Upper Diagonal elements
    for (int i = 1; i <= dim - 1; i++) tm.Set(i, i + 1, 3);

    // Display Matrix Output
    cout << "\nMatrix Output:" << endl;
    tm.Display();

    // Query specific elements
    cout << "\nElement at (3,3) [Main]:  " << tm.Get(3, 3) << endl;
    cout << "Element at (4,3) [Lower]: " << tm.Get(4, 3) << endl;
    cout << "Element at (2,3) [Upper]: " << tm.Get(2, 3) << endl;
    cout << "Element at (1,4) [Out]:   " << tm.Get(1, 4) << endl;

    return 0;
}