/*
Program Name: Stack Application - Extended Parentheses Matching (Multiple Bracket Types)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Validates expressions containing multiple bracket types: (), {}, and [].
   - Ensures correct bracket types match and respect Last-In, First-Out (LIFO) nesting rules.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Loop through character array `exp`:
     * If char is '(', '{', or '[', push onto stack.
     * If char is ')', '}', or ']':
       - If stack is empty, return false.
       - Pop character `topChar` from stack.
       - Check if `topChar` and `exp[i]` match. If not, return false.
   - Return true if stack is empty at the end.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is expression length.
   - Space Complexity : O(n) Stack space.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Node Structure for Stack
struct Node {
    char data;
    Node* next;
};

// Stack Class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    ~Stack() {
        Node* p = top;
        while (top != NULL) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(char x) {
        Node* t = new Node();
        if (t == NULL) {
            cout << "Stack Overflow!" << endl;
        } else {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    char pop() {
        char x = '\0';
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
        } else {
            Node* p = top;
            x = top->data;
            top = top->next;
            delete p;
        }
        return x;
    }
};

// Helper Function to Check Matching Bracket Pairs
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// Function to Check Extended Parentheses Matching
bool isBalancedExtended(const char* exp) {
    Stack st;

    for (int i = 0; exp[i] != '\0'; i++) {
        // Push opening brackets
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            st.push(exp[i]);
        } 
        // Process closing brackets
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (st.isEmpty()) {
                return false; // Unmatched closing bracket
            }

            char topChar = st.pop();
            if (!isMatchingPair(topChar, exp[i])) {
                return false; // Mismatched bracket types
            }
        }
    }

    return st.isEmpty();
}

int main() {
    cout << "--- Stack Application: Extended Parentheses Matching ---" << endl;

    const char* exp1 = "{([a+b]*[c-d])}";
    const char* exp2 = "{(a+b)*[c-d]}";
    const char* exp3 = "{([a+b]*[c-d])}";
    const char* exp4 = "{[(a+b)]}";
    const char* exp5 = "{[(a+b)]}";
    const char* exp6 = "{[(a+b)]}";
    const char* exp_mismatch = "{[(a+b)]}"; // Correct pair tests below

    const char* test1 = "{[a+b]*(c+d)}";  // Balanced
    const char* test2 = "{[(a+b)]}";       // Balanced
    const char* test3 = "{[(a+b)]}";       // Balanced
    const char* test4 = "{[a+b]* (c+d)}";  // Balanced
    const char* test5 = "{[(a+b])}";       // Mismatched order ']' vs ')'

    cout << "\nExpression 1: " << test1 << " -> " << (isBalancedExtended(test1) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 2: " << test2 << " -> " << (isBalancedExtended(test2) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 3: " << test5 << " -> " << (isBalancedExtended(test5) ? "Balanced" : "Unbalanced") << endl;

    return 0;
}