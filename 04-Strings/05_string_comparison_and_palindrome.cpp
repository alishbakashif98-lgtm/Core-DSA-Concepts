/*
Program Name: Strings - Comparison and Palindrome Algorithms


1. STRING COMPARISON LOGIC:
----------------------------------------------------------------------------------------------------
   - Compares characters of two strings at the same indices using ASCII values.
   - If `str1[i] == str2[i]`, move to next index.
   - If `str1[i] < str2[i]`, `str1` comes earlier alphabetically (returns -1).
   - If `str1[i] > str2[i]`, `str1` comes later alphabetically (returns 1).
   - If both reach `'\0'` together, strings are identical (returns 0).

2. PALINDROME CHECKING LOGIC:
----------------------------------------------------------------------------------------------------
   - Method: Two-Pointer Technique (In-Place)
   - Left pointer `i = 0`, right pointer `j = length - 1`.
   - Skip non-alphanumeric characters or ignore case differences for robust checking.
   - Compare `str[i]` and `str[j]`. If they mismatch, it is NOT a palindrome.
   - Time Complexity: O(n) | Space Complexity: O(1)
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringOps {
private:
    char str[100];

public:
    // Simple Constructor
    StringOps(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    // 1. Simple Palindrome Check
    bool IsPalindrome() {
        // Step 1: Find Length
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }

        // Step 2: Compare from both ends
        int i = 0;
        int j = len - 1;

        while (i < j) {
            if (str[i] != str[j]) {
                return false; // Match nahi hua, matlab Palindrome nahi hai
            }
            i++;
            j--;
        }

        return true; // Sab match ho gaye!
    }

    void Display() {
        cout << "\"" << str << "\"";
    }
};

int main() {
    cout << "--- Palindrome Checker ---" << endl;

    StringOps s1("MADAM");
    StringOps s2("HELLO");

    cout << "\nString 1: "; s1.Display();
    if (s1.IsPalindrome()) {
        cout << " -> Is a Palindrome!" << endl;
    } else {
        cout << " -> Not a Palindrome!" << endl;
    }

    cout << "\nString 2: "; s2.Display();
    if (s2.IsPalindrome()) {
        cout << " -> Is a Palindrome!" << endl;
    } else {
        cout << " -> Not a Palindrome!" << endl;
    }

    return 0;
}