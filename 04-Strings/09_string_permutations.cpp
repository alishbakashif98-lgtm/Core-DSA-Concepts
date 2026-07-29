/*
Program Name: Strings - Finding All Permutations of a String (Backtracking & Swapping)


1. PERMUTATION LOGIC (SWAPPING & BACKTRACKING):
----------------------------------------------------------------------------------------------------
   - Total Permutations for a string of length n = n! (Factorial n).
   - Algorithm:
     * Fix each character at index `l` one by one by swapping it with index `i` (from `l` to `h`).
     * Recursively generate permutations for the remaining substring (`l + 1`).
     * Base Case: When `l == h`, print the current permuted string!
     * Backtrack: Swap `str[l]` and `str[i]` back to restore original state for next iteration.

2. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n * n!) -> Total n! permutations, each taking O(n) to print.
   - Space Complexity: O(n) -> Function call stack depth equals string length n.
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringPermutations {
private:
    char str[100];

    // Helper swap function
    void Swap(char *x, char *y) {
        char temp = *x;
        *x = *y;
        *y = temp;
    }

    // Recursive Permutation Function
    void Permute(char s[], int l, int h, int &count) {
        if (l == h) {
            count++;
            cout << "  " << count << ". " << s << endl;
        } else {
            for (int i = l; i <= h; i++) {
                Swap(&s[l], &s[i]);        // Action: Swap
                Permute(s, l + 1, h, count); // Recursion
                Swap(&s[l], &s[i]);        // Backtrack: Restore
            }
        }
    }

public:
    // Constructor
    StringPermutations(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    void DisplayPermutations() {
        int len = 0;
        while (str[len] != '\0') len++;

        int totalCount = 0;
        cout << "\nGenerating All Permutations for: \"" << str << "\"" << endl;
        Permute(str, 0, len - 1, totalCount);
        cout << "Total Permutations Generated: " << totalCount << endl;
    }
};

int main() {
    cout << "--- String Operations: Finding Permutations ---" << endl;

    StringPermutations p1("ABC");
    p1.DisplayPermutations();

    return 0;
}