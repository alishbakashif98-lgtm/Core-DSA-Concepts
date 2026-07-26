/*
Program Name: Strings - Counting Vowels, Consonants, Words, and Special Characters


1. VOWELS vs CONSONANTS LOGIC:
----------------------------------------------------------------------------------------------------
   - Vowels: Checks for 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'.
   - Consonants: Any character in ('A'-'Z' or 'a'-'z') that is NOT a vowel.
   - Digits & Symbols: Ignore numbers, punctuation, and spaces when counting letters.

2. ACCURATE WORD COUNTING (HANDLING MULTIPLE SPACES):
----------------------------------------------------------------------------------------------------
   - Simple Space Count: `spaceCount + 1` works ONLY if there are no extra spaces.
   - Robust Word Count Logic: Increment count when `str[i] == ' '` AND `str[i - 1] != ' '`.
   - Also handle trailing spaces correctly.

3. TIME & SPACE COMPLEXITY:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n) for a single linear pass.
   - Space Complexity: O(1).
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringAnalytics {
private:
    char str[200];

    bool IsVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    bool IsAlphabet(char ch) {
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
    }

public:
    // Constructor
    StringAnalytics(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    void Display() {
        cout << "Input String: \"" << str << "\"" << endl;
    }

    // Analyze string and output detailed counts
    void AnalyzeString() {
        int vCount = 0; // Vowels
        int cCount = 0; // Consonants
        int wCount = 0; // Words
        int sCount = 0; // Special characters / symbols

        for (int i = 0; str[i] != '\0'; i++) {
            // 1. Vowels and Consonants
            if (IsVowel(str[i])) {
                vCount++;
            } else if (IsAlphabet(str[i])) {
                cCount++;
            }

            // 2. Words (Checking space transition to handle multi-spaces)
            if (str[i] == ' ' && i > 0 && str[i - 1] != ' ') {
                wCount++;
            }

            // 3. Special Characters (Not letter, not digit, not space)
            if (!IsAlphabet(str[i]) && (str[i] < '0' || str[i] > '9') && str[i] != ' ') {
                sCount++;
            }
        }

        // Account for the last word if string does not end with space
        int len = 0;
        while (str[len] != '\0') len++;
        if (len > 0 && str[len - 1] != ' ') {
            wCount++;
        }

        cout << "\n--- STRING ANALYSIS RESULTS ---" << endl;
        cout << "1. Vowels Count:        " << vCount << endl;
        cout << "2. Consonants Count:    " << cCount << endl;
        cout << "3. Words Count:         " << wCount << endl;
        cout << "4. Special Symbols:     " << sCount << endl;
    }
};

int main() {
    cout << "--- String Operations: Analytics & Counting Showcase ---" << endl;

    StringAnalytics sa("How   are  you  321?  Welcome to C++ DSA!");
    sa.Display();
    sa.AnalyzeString();

    return 0;
}