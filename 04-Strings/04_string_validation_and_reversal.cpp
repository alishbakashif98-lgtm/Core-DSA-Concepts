/*
Program Name: Strings - Validation and In-Place Reversal Algorithms


1. STRING VALIDATION LOGIC:
----------------------------------------------------------------------------------------------------
   - Rule: A valid string/username contains ONLY alphanumeric characters (A-Z, a-z, 0-9).
   - If any special character or punctuation is found, the string is INVALID.

2. STRING REVERSAL ALGORITHMS:
----------------------------------------------------------------------------------------------------
   - Method 1 (Auxiliary Array): Copy characters in reverse order into a separate array.
     * Time Complexity: O(n) | Space Complexity: O(n)
   - Method 2 (In-Place Two-Pointer Swapping):
     * Set left pointer `i = 0` and right pointer `j = length - 1`.
     * Swap `str[i]` and `str[j]` while incrementing `i` and decrementing `j`.
     * Time Complexity: O(n) | Space Complexity: O(1) [OPTIMAL]
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringReversal {
private:
    char str[100];

    // Helper swap function
    void Swap(char *x, char *y) {
        char temp = *x;
        *x = *y;
        *y = temp;
    }

public:
    // Constructor
    StringReversal(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    void Display() {
        cout << "Current String: \"" << str << "\"" << endl;
    }

    // 1. Validate String (Only letters and numbers allowed)
    bool IsValid() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (!(str[i] >= 'a' && str[i] <= 'z') &&
                !(str[i] >= 'A' && str[i] <= 'Z') &&
                !(str[i] >= '0' && str[i] <= '9')) {
                return false; // Found invalid special character
            }
        }
        return true;
    }

    // 2. Reverse In-Place using Two-Pointer Swapping
    void ReverseInPlace() {
        // Calculate length
        int len = 0;
        while (str[len] != '\0') len++;

        int i = 0;
        int j = len - 1;

        while (i < j) {
            Swap(&str[i], &str[j]);
            i++;
            j--;
        }
    }
};

int main() {
    cout << "--- String Operations: Validation & Reversal Showcase ---" << endl;

    // Test 1: Validation
    StringReversal s1("Ani321");
    StringReversal s2("Ani?321#");

    cout << "\n[Validation Test 1]: "; s1.Display();
    cout << "Result: " << (s1.IsValid() ? "Valid String (Alphanumeric)" : "Invalid String") << endl;

    cout << "\n[Validation Test 2]: "; s2.Display();
    cout << "Result: " << (s2.IsValid() ? "Valid String (Alphanumeric)" : "Invalid String") << endl;

    // Test 2: In-Place Reversal
    StringReversal s3("Python & C++ Data Structures");
    cout << "\n[Reversal Test] Before Reversal: "; s3.Display();
    s3.ReverseInPlace();
    cout << "After In-Place Reversal: "; s3.Display();

    return 0;
}