/*
Program Name: Tower of Hanoi using Recursion

Technical Terms & Concepts:
1. Mathematical Puzzle: Moving 'n' disks from a Source tower to a Destination tower 
   using an Auxiliary (helper) tower.
2. Rules of Engagement: 
   - Only one disk can be moved at a time.
   - A disk can only be placed on top of a larger disk (never a larger disk on a smaller one).
3. Execution Blueprint: It follows a Tree Recursion pattern, taking O(2^n) total operational steps.
*/

#include <iostream>
using namespace std;

// Tower of Hanoi Recursive Function
// Parameters: Number of disks, Source Tower (A), Auxiliary Tower (B), Destination Tower (C)
void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        // Step 1: Move top (n-1) disks from Source (A) to Auxiliary (B) using Destination (C) as helper
        TOH(n - 1, A, C, B);
        
        // Step 2: Move the remaining largest disk directly from Source (A) to Destination (C)
        cout << "Move disk from Tower " << A << " to Tower " << C << endl;
        
        // Step 3: Move the (n-1) disks from Auxiliary (B) to Destination (C) using Source (A) as helper
        TOH(n - 1, B, A, C);
    }
}

int main() {
    int disks = 3; // Setting puzzle for 3 disks
    
    cout << "--- Tower of Hanoi Step-by-Step Moves for " << disks << " Disks ---" << endl;
    cout << "Tower Identifiers: 1 = Source (A), 2 = Helper (B), 3 = Destination (C)\n" << endl;
    
    TOH(disks, 1, 2, 3); // Executing the master recursion plan
    
    return 0;
}