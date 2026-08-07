/*
Program Name: Stack Application - Infix to Postfix Conversion


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Converts standard human-readable Infix expressions (Operand Operator Operand) into 
     Postfix / Reverse Polish Notation (Operand Operand Operator) using operator precedence stack rules.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Loop through `infix` string:
     * If character is operand, append directly to `postfix`.
     * If character is operator:
       - Compare `precedence(infix[i])` with `precedence(stackTop())`.
       - While `precedence(infix[i]) <= precedence(stackTop())`, pop from stack to `postfix`.
       - Push current operator onto stack.
   - Pop all remaining operators from stack to `postfix`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) Linear scan through expression.
   - Space Complexity : O(n) Dynamic allocation for result and stack.
====================================================================================================
*/

#include <iostream>
#include <cstring>
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
    Stack() { top = NULL; }

    ~Stack() {
        Node* p = top;
        while (top != NULL) {
            top = top->next;
            delete p;
            p = top;
        }
    }

    bool isEmpty() { return top == NULL; }

    void push(char x) {
        Node* t = new Node();
        if (t != NULL) {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    char pop() {
        if (isEmpty()) return '\0';
        Node* p = top;
        char x = top->data;
        top = top->next;
        delete p;
        return x;
    }

    char stackTop() {
        if (isEmpty()) return '\0';
        return top->data;
    }
};

// Function to Check if Character is Operand
bool isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')') {
        return false;
    }
    return true;
}

// Function to Return Operator Precedence
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Function to Convert Infix to Postfix
char* infixToPostfix(const char* infix) {
    Stack st;
    int len = strlen(infix);
    char* postfix = new char[len + 1];

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        // Step 1: If Operand, add to Postfix
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } 
        // Step 2: If Operator, compare precedence
        else {
            if (precedence(infix[i]) > precedence(st.stackTop())) {
                st.push(infix[i++]);
            } else {
                postfix[j++] = st.pop();
            }
        }
    }

    // Step 3: Pop remaining operators
    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    cout << "--- Stack Application: Infix to Postfix Conversion ---" << endl;

    const char* infix1 = "a+b*c";
    const char* infix2 = "a+b*c-d/e";

    char* postfix1 = infixToPostfix(infix1);
    char* postfix2 = infixToPostfix(infix2);

    cout << "\nInfix Expression 1  : " << infix1 << endl;
    cout << "Postfix Expression 1: " << postfix1 << endl;

    cout << "\nInfix Expression 2  : " << infix2 << endl;
    cout << "Postfix Expression 2: " << postfix2 << endl;

    delete[] postfix1;
    delete[] postfix2;

    return 0;
}