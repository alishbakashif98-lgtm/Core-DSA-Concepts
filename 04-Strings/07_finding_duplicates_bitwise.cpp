/*
Program Name: Strings - Finding Duplicates using Bitwise Operations (Bitmasking)


1. BITMASKING MECHANICS:
----------------------------------------------------------------------------------------------------
   - An integer `H` (32 bits) acts as 32 individual true/false flags.
   - For character `ch`: Calculate shift amount `k = ch - 'a'`.
   - Create bitmask `x = 1 << k` (1 shifted left by `k` positions).

2. OPERATIONS:
----------------------------------------------------------------------------------------------------
   - Check if bit is ON (Masking with Bitwise AND): `(x & H) > 0`
     * If true -> Character is a DUPLICATE!
   - Turn bit ON (Merging with Bitwise OR): `H = x | H`
     * Sets the k-th bit to 1.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n)
   - Space Complexity: O(1) [Uses only 1 integer variable, zero extra arrays!]
====================================================================================================
*/

#include <iostream>
using namespace std;

class BitwiseDuplicateFinder {
private:
    char str[100];

public:
    // Constructor
    BitwiseDuplicateFinder(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    void Display() {
        cout << "\"" << str << "\"" << endl;
    }

    // Find duplicates using Bitwise Operations
    void FindDuplicatesBitwise() {
        int H = 0; // 32-bit integer used as bitset (all bits 0 initially)
        int x = 0; // Mask variable

        cout << "\nDuplicate Characters Found (Bitwise Method):" << endl;
        bool found = false;

        for (int i = 0; str[i] != '\0'; i++) {
            // Handle lowercase characters
            char ch = str[i];
            if (ch >= 'A' && ch <= 'Z') ch = ch + 32; // Convert to lowercase

            if (ch >= 'a' && ch <= 'z') {
                x = 1;
                x = x << (ch - 97); // Left shift 1 by (ch - 97) bits

                // Check if the bit is already set (Bitwise AND)
                if ((x & H) > 0) {
                    cout << "  * Duplicate found: '" << ch << "'" << endl;
                    found = true;
                } else {
                    // Set the bit to 1 (Bitwise OR)
                    H = x | H;
                }
            }
        }

        if (!found) {
            cout << "  No duplicates found!" << endl;
        }
    }
};

int main() {
    cout << "--- String Operations: Finding Duplicates (Bitwise) ---" << endl;

    BitwiseDuplicateFinder b1("finding");
    cout << "\nInput String 1: "; b1.Display();
    b1.FindDuplicatesBitwise();

    BitwiseDuplicateFinder b2("datastructures");
    cout << "\nInput String 2: "; b2.Display();
    b2.FindDuplicatesBitwise();

    return 0;
}