/*
Program Name: 2D Array Representation Models

Technical Terms & Concepts:
1. Fully Static Row-Column Matrix: Stack-only allocation.
2. Array of Pointers (Partial Dynamic): Row pointers live on Stack, Columns are created in Heap.
3. Double Pointer (Fully Dynamic Matrix): Row pointers and columns both live entirely in the Heap.
*/

#include <iostream>
using namespace std;

int main() {
    // Model 1: Fully Static (Stack)
    int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    
    // Model 2: Partial Dynamic (Array of Pointers on Stack, Blocks on Heap)
    int *B[3];
    B[0] = new int[4]{1,2,3,4};
    B[1] = new int[4]{5,6,7,8};
    B[2] = new int[4]{9,10,11,12};
    
    // Model 3: Fully Dynamic (Double Pointer in Heap)
    int **C;
    C = new int*[3]; // Creating pointer array in heap
    C[0] = new int[4]{1,2,3,4};
    C[1] = new int[4]{5,6,7,8};
    C[2] = new int[4]{9,10,11,12};
    
    cout << "--- 2D Array (Double Pointer Model) Output ---" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    // Cleanup Model 2 & Model 3 Memory
    for(int i=0; i<3; i++) { delete [] B[i]; delete [] C[i]; }
    delete [] C;
    
    return 0;
}