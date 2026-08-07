/*
Program Name: Stack Application - Evaluation of Postfix Expression


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Evaluates a Postfix (Reverse Polish Notation) expression containing single-digit operands 
     and binary arithmetic operators (+, -, *, /) using an integer LIFO stack.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Loop through `postfix` expression string:
     * If character is operand, convert character digit to integer (`postfix[i] - '0'`) and push to stack.
     * If character is operator (+, -, *, /):
       - Pop `y = stack.pop()` (Second operand).
       - Pop `x = stack.pop()` (First operand).
       - Perform calculation `r = x [op] y`.
       - Push result `r` back onto stack.
   - Return final value from `stack.pop()`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) Single linear pass through the string.
   - Space Complexity : O(n) Stack space for operands.
====================================================================================================
*/

#include <iostream>
#include <cstring>
using namespace std;

// Node Structure for Integer Stack
struct Node {
    int data;
    Node* next;
};

// Integer Stack Class
class IntStack {
private:
    Node* top;

public:
    IntStack() { top = NULL; }

    ~IntStack() {
        Node* p = top;
        while (top != NULL) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() { return top == NULL; }

    void push(int x) {
        Node* t = new Node();
        if (t != NULL) {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* p = top;
        int x = top->data;
        top = top->next;
        delete p;
        return x;
    }
};

// Function to Check if Character is Operand
bool isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return false;
    }
    return true;
}

// Function to Evaluate Postfix Expression
int evaluatePostfix(const char* postfix) {
    IntStack st;
    int x, y, r;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // Step 1: If operand, convert char to int and push
        if (isOperand(postfix[i])) {
            st.push(postfix[i] - '0');
        } 
        // Step 2: If operator, pop 2 operands and calculate
        else {
            y = st.pop(); // Second operand
            x = st.pop(); // First operand

            switch (postfix[i]) {
                case '+': r = x + y; break;
                case '-': r = x - y; break;
                case '*': r = x * y; break;
                case '/': r = x / y; break;
            }

            st.push(r);
        }
    }

    return st.pop();
}

int main() {
    cout << "--- Stack Application: Evaluation of Postfix Expression ---" << endl;

    const char* postfix1 = "35*2+";    // (3 * 5) + 2 = 17
    const char* postfix2 = "234*+5-";  // 2 + (3 * 4) - 5 = 9

    cout << "\nPostfix Expression 1: " << postfix1 << endl;
    cout << "Evaluation Result 1   : " << evaluatePostfix(postfix1) << endl;

    cout << "\nPostfix Expression 2: " << postfix2 << endl;
    cout << "Evaluation Result 2   : " << evaluatePostfix(postfix2) << endl;

    return 0;
}