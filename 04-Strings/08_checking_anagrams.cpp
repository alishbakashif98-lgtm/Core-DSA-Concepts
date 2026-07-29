/*
Program Name: Strings - Checking if Two Strings are Anagrams


1. ANAGRAM DEFINITION:
----------------------------------------------------------------------------------------------------
   - Two strings are Anagrams if they contain the exact same characters in equal frequencies,
     regardless of order (e.g., "verbose" & "observe", "silent" & "listen").

2. HASH TABLE / COUNTING ALGORITHM:
----------------------------------------------------------------------------------------------------
   - Step 1: Check length. If lengths differ, return false immediately.
   - Step 2: Traverse first string and increment frequency array `H[str1[i] - 'a']++`.
   - Step 3: Traverse second string and decrement frequency array `H[str2[i] - 'a']--`.
     * If `H[str2[i] - 'a'] < 0`, second string has extra/unmatched letters -> NOT an Anagram!
   - Step 4: If traversal finishes cleanly, the strings are ANAGRAMS!

3. TIME & SPACE COMPLEXITY:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n) (Single linear pass)
   - Space Complexity: O(1) (Fixed 26-element integer hash table)
====================================================================================================
*/

#include <iostream>
using namespace std;

class AnagramChecker {
public:
    // Function to check if two strings are anagrams
    static bool IsAnagram(const char str1[], const char str2[]) {
        int H[26] = {0}; // Hash array for 'a' to 'z'

        // 1. Calculate lengths of both strings
        int len1 = 0, len2 = 0;
        while (str1[len1] != '\0') len1++;
        while (str2[len2] != '\0') len2++;

        // If lengths don't match, they cannot be anagrams
        if (len1 != len2) return false;

        // 2. Increment counts for str1
        for (int i = 0; str1[i] != '\0'; i++) {
            char ch = str1[i];
            if (ch >= 'A' && ch <= 'Z') ch += 32; // Lowercase conversion
            if (ch >= 'a' && ch <= 'z') {
                H[ch - 'a']++;
            }
        }

        // 3. Decrement counts for str2
        for (int i = 0; str2[i] != '\0'; i++) {
            char ch = str2[i];
            if (ch >= 'A' && ch <= 'Z') ch += 32; // Lowercase conversion
            if (ch >= 'a' && ch <= 'z') {
                H[ch - 'a']--;

                // If count goes negative, str2 has more of character 'ch' than str1
                if (H[ch - 'a'] < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    cout << "--- String Operations: Anagram Verification ---" << endl;

    // Test Case 1: Valid Anagram
    const char s1[] = "verbose";
    const char s2[] = "observe";

    cout << "\n[Test 1] Comparing: \"" << s1 << "\" and \"" << s2 << "\"" << endl;
    if (AnagramChecker::IsAnagram(s1, s2)) {
        cout << "Result: Both strings ARE Anagrams!" << endl;
    } else {
        cout << "Result: Strings are NOT Anagrams!" << endl;
    }

    // Test Case 2: Invalid Anagram
    const char s3[] = "apple";
    const char s4[] = "apply";

    cout << "\n[Test 2] Comparing: \"" << s3 << "\" and \"" << s4 << "\"" << endl;
    if (AnagramChecker::IsAnagram(s3, s4)) {
        cout << "Result: Both strings ARE Anagrams!" << endl;
    } else {
        cout << "Result: Strings are NOT Anagrams!" << endl;
    }

    return 0;
}