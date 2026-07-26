/*
Program Name: Strings - Basics, Initialization, and Finding Length


1. CHARACTER REPRESENTATION & ASCII CODES:
----------------------------------------------------------------------------------------------------
   - Computers store characters as integers using ASCII (American Standard Code for Information Interchange).
   - Key ASCII Ranges:
     * 'A' to 'Z'  -->  65 to 90
     * 'a' to 'z'  -->  97 to 122
     * '0' to '9'  -->  48 to 57
     * Difference between 'a' and 'A': 97 - 65 = 32.

2. STRING DEFINITION & NULL CHARACTER (\0):
----------------------------------------------------------------------------------------------------
   - A string in C/C++ is an array of characters terminated by a special character called the 
     Null Character (`'\0'`).
   - ASCII value of `'\0'` is 0.
   - Purpose of `'\0'`: Marks the end of a string in memory so algorithms know where the text stops.

3. FINDING LENGTH OF A STRING:
----------------------------------------------------------------------------------------------------
   - Logic: Iterate through the character array using a loop starting from index 0 until `str[i] == '\0'`.
   - Time Complexity: O(n) (where 'n' is the actual length of the string before `\0`).
   - Space Complexity: O(1).
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringOps {
private:
    char name[100]; // Fixed character array buffer

public:
    // Constructor
    StringOps(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            name[i] = input[i];
            i++;
        }
        name[i] = '\0'; // Add null terminator
    }

    // Display string
    void Display() {
        cout << "String Content: " << name << endl;
    }

    // 1. Calculate length manually using Null Character termination
    int GetLength() {
        int count = 0;
        for (int i = 0; name[i] != '\0'; i++) {
            count++;
        }
        return count;
    }
};

int main() {
    cout << "--- String Operations: Basics & Length Calculation ---" << endl;

    // Creating String instance with a character array
    StringOps str("Welcome To Data Structures");

    str.Display();
    cout << "Calculated Length of String: " << str.GetLength() << " characters" << endl;

    return 0;
}