/*
Program Name: Strings - Changing Case (Upper to Lower, Lower to Upper, Toggle Case)


1. ASCII VALUE MECHANICS FOR CASE CONVERSION:
----------------------------------------------------------------------------------------------------
   - Uppercase ASCII Range: 'A' (65) to 'Z' (90)
   - Lowercase ASCII Range: 'a' (97) to 'z' (122)
   - ASCII Difference: 'a' - 'A' = 32

2. ALGORITHMIC RULES:
----------------------------------------------------------------------------------------------------
   - Lowercase to Uppercase: If 'a' <= str[i] <= 'z', then `str[i] = str[i] - 32`
   - Uppercase to Lowercase: If 'A' <= str[i] <= 'Z', then `str[i] = str[i] + 32`
   - Toggle Case: Check each character and reverse its case individually. Spaces and special 
     characters remain unchanged.

3. TIME & SPACE COMPLEXITY:
----------------------------------------------------------------------------------------------------
   - Time Complexity: O(n) for traversing the string once.
   - Space Complexity: O(1) as transformations occur in-place.
====================================================================================================
*/

#include <iostream>
using namespace std;

class StringCase {
private:
    char str[100];

public:
    // Constructor
    StringCase(const char input[]) {
        int i = 0;
        while (input[i] != '\0') {
            str[i] = input[i];
            i++;
        }
        str[i] = '\0';
    }

    // Display Current String
    void Display() {
        cout << "Current String: " << str << endl;
    }

    // 1. Convert Entire String to Lowercase
    void ToLowerCase() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
    }

    // 2. Convert Entire String to Uppercase
    void ToUpperCase() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
    }

    // 3. Toggle Case (Uppercase -> Lowercase & Lowercase -> Uppercase)
    void ToggleCase() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
    }
};

int main() {
    cout << "--- String Operations: Changing Case Showcase ---" << endl;

    // Test 1: Lowercase Conversion
    StringCase s1("WELCOME TO DATA STRUCTURES");
    cout << "\n[Test 1] Original String: WELCOME TO DATA STRUCTURES" << endl;
    s1.ToLowerCase();
    cout << "Converted to Lowercase: " << endl;
     s1.Display();

    // Test 2: Uppercase Conversion
    StringCase s2("learning algorithms in c++");
    cout << "\n[Test 2] Original String: learning algorithms in c++" << endl;
    s2.ToUpperCase();
    cout << "Converted to Uppercase: "<< endl; 
    s2.Display();

    // Test 3: Toggle Case
    StringCase s3("WeLcOmE To C++ PrOgRaMmInG");
    cout << "\n[Test 3] Original String: WeLcOmE To C++ PrOgRaMmInG" << endl;
    s3.ToggleCase();
    cout << "Toggled Case Output:  "<< endl;
     s3.Display();

    return 0;
}