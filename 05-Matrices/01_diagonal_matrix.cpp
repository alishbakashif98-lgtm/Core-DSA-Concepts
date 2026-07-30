/*
Program Name: Special Matrices - Diagonal Matrix Implementation (Comprehensive C++ Class)


1. MATHEMATICAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Matrix M of dimension (n x n) is called a DIAGONAL MATRIX if and only if:
     M[i][j] = 0   when i != j
     M[i][j] = k   when i == j (where k can be any non-zero or zero integer)


2. INDEX MAPPING FORMULA (1-Based to 0-Based Indexing):
----------------------------------------------------------------------------------------------------
   - User inputs 1-based indices (i, j) where 1 <= i, j <= n.
   - If i == j: Access index in 1D Array = (i - 1).
   - If i != j: Return 0 directly without searching memory.

3. STEP-BY-STEP ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Step 1 [Initialization]: Dynamically allocate 1D integer array `A` of size `n`.
   - Step 2 [Set Operation]: 
     * Input: row (i), column (j), value (x).
     * Check condition `i == j`.
     * If true, store `x` at `A[i - 1]`.
     * If false, ignore/reject storing (since off-diagonal elements must remain zero).
   - Step 3 [Get Operation]:
     * Input: row (i), column (j).
     * Check condition `i == j`.
     * If true, return `A[i - 1]`.
     * If false, immediately return `0`.
   - Step 4 [Display Operation]:
     * Run nested loops: `i` from 1 to `n`, `j` from 1 to `n`.
     * If `i == j`, print `A[i - 1]`.
     * Else, print `0`.

5. TIME COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Set(i, j, x) -> O(1) [Direct mathematical index access]
   - Get(i, j)    -> O(1) [Direct mathematical index access]
   - Display()    -> O(n^2) [Must print n x n grid to console]
====================================================================================================
*/

#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int n;      // Matrix Dimension (n x n)
    int *A;     // Pointer to dynamic 1D Array for diagonal elements

public:
    // Constructor: Allocates 1D array of size 'n' on Heap
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }

    // Set element at M[i][j] (1-based indexing)
    void Set(int i, int j, int x) {
        // Only main diagonal elements (i == j) are stored
        if (i == j) {
            A[i - 1] = x; // Maps 1-based index (i) to 0-based array index (i - 1)
        }
    }

    // Get element at M[i][j] (1-based indexing)
    int Get(int i, int j) {
        if (i == j) {
            return A[i - 1]; // Return diagonal element
        }
        return 0; // Off-diagonal elements are always 0
    }

    // Display the full 2D Matrix format
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    cout << A[i - 1] << " "; // Print diagonal element
                } else {
                    cout << "0 ";            // Print zero for off-diagonal
                }
            }
            cout << endl;
        }
    }

    // Destructor: Deallocates heap memory to prevent memory leaks
    ~DiagonalMatrix() {
        delete[] A;
    }
};

int main() {
    cout << "--- Diagonal Matrix ---" << endl;

    // Create a 4x4 Diagonal Matrix
    DiagonalMatrix dm(4);

    // Set diagonal values
    dm.Set(1, 1, 5);
    dm.Set(2, 2, 8);
    dm.Set(3, 3, 3);
    dm.Set(4, 4, 9);

    // Display the matrix output
    cout << "\nMatrix Output:" << endl;
    dm.Display();

    // Retrieve specific elements
    cout << "\nElement at (2,2): " << dm.Get(2, 2) << endl;
    cout << "Element at (1,3): " << dm.Get(1, 3) << endl;

    return 0;
}