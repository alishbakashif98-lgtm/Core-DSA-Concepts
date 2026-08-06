/*
Program Name: Stack Application - Parentheses Matching (Single Type)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Checks if an arithmetic expression has balanced simple parentheses `()` using a LIFO Stack.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Loop through each character of string `exp`:
     * If character == '(', push '(' onto stack.
     * If character == ')':
       - If stack is empty, return false (unbalanced closing bracket).
       - Else, pop '(' from stack.
   - At end of expression string:
     * Return true if stack is empty, else false.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) where n is length of the expression.
   - Space Complexity : O(n) Auxiliary space for stack in worst case.
====================================================================================================
*/

#include <iostream>
#include <cstring>
using namespace std;

// Node Structure for Stack using Linked List
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

// Function to Check Balanced Parentheses
bool isBalanced(const char* exp) {
    Stack st;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            st.push(exp[i]);
        } else if (exp[i] == ')') {
            if (st.isEmpty()) {
                return false; // Closing bracket without opening bracket
            }
            st.pop();
        }
    }

    return st.isEmpty(); // Balanced if stack is clean at the end
}

int main() {
    cout << "--- Stack Application: Parentheses Matching ---" << endl;

    const char* exp1 = "((a+b)*(c-d))";
    const char* exp2 = "(((a+b)*c)";
    const char* exp3 = "((a+b)*c))";

    cout << "\nExpression 1: " << exp1 << " -> " << (isBalanced(exp1) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 2: " << exp2 << " -> " << (isBalanced(exp2) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 3: " << exp3 << " -> " << (isBalanced(exp3) ? "Balanced" : "Unbalanced") << endl;

    return 0;
}