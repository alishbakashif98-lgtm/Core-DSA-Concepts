/*
Program Name: Strings - Finding Duplicates using Hash / Frequency Array


1. HASH ARRAY / FREQUENCY COUNTING METHOD:
----------------------------------------------------------------------------------------------------
   - Create an integer array `H[26]` initialized to 0.
   - Map lowercase characters 'a'..'z' to indices 0..25 by subtracting 97 (ASCII of 'a').
     * Example: 'a' - 97 = 0, 'b' - 97 = 1, 'e' - 97 = 4, etc.
   - Pass 1: Iterate through string and increment `H[str[i] - 97]++`.
   - Pass 2: Iterate through hash array H. If `H[i] > 1`, character `(char)(i + 97)` is a duplicate!

2. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n) (where 'n' is string length)
   - Space Complexity: O(1) (fixed hash size of 26 integers)
====================================================================================================
*/

#include <iostream>
using namespace std;

class DuplicateFinder {
private:
    char str[100];

public:
    // Constructor
    DuplicateFinder(const char input[]) {
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

    // Find duplicates using Frequency / Hash Array
    void FindDuplicates() {
        int H[26] = {0}; // Hash array for 'a' to 'z'

        // Step 1: Fill frequency array
        for (int i = 0; str[i] != '\0'; i++) {
            // Handle lowercase letters
            if (str[i] >= 'a' && str[i] <= 'z') {
                H[str[i] - 97]++;
            }
            // Handle uppercase letters (convert on the fly)
            else if (str[i] >= 'A' && str[i] <= 'Z') {
                H[str[i] - 65]++;
            }
        }

        // Step 2: Print duplicates
        cout << "\nDuplicate Characters Found:" << endl;
        bool found = false;
        for (int i = 0; i < 26; i++) {
            if (H[i] > 1) {
                char ch = i + 97; // Convert index back to character
                cout << "  * Character '" << ch << "' appears " << H[i] << " times." << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "  No duplicate characters found!" << endl;
        }
    }
};

int main() {
    cout << "--- String Operations: Finding Duplicates ---" << endl;

    DuplicateFinder d1("finding");
    cout << "\nInput String 1: "; d1.Display();
    d1.FindDuplicates();

    DuplicateFinder d2("programming");
    cout << "\nInput String 2: "; d2.Display();
    d2.FindDuplicates();

    return 0;
}