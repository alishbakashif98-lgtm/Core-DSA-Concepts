/*
Program Name: Stack Application - Advanced Infix to Postfix (Parentheses & Associativity)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Complete Infix to Postfix converter handling operator precedence, right-to-left associativity 
     for exponentiation (^), and explicit grouping with parentheses ().

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Loop through `infix` expression:
     * If operand, append to `postfix`.
     * If operator/bracket:
       - Compare `outStackPrecedence(infix[i])` with `inStackPrecedence(stackTop())`.
       - If Out-Stack > In-Stack: Push operator onto stack.
       - If Out-Stack < In-Stack: Pop operator from stack to `postfix`.
       - If Out-Stack == In-Stack: Pop '(' matching bracket and discard ')'.
   - Pop remaining operators to `postfix`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(n) Linear scan.
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
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') {
        return false;
    }
    return true;
}

// Function for Out-Stack Precedence
int outStackPrecedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 3;
    if (x == '^') return 6;
    if (x == '(') return 7;
    if (x == ')') return 0;
    return -1;
}

// Function for In-Stack Precedence
int inStackPrecedence(char x) {
    if (x == '+' || x == '-') return 2;
    if (x == '*' || x == '/') return 4;
    if (x == '^') return 5;
    if (x == '(') return 0;
    return -1;
}

// Advanced Infix to Postfix Conversion
char* infixToPostfixAdvanced(const char* infix) {
    Stack st;
    int len = strlen(infix);
    char* postfix = new char[len + 1];

    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            if (st.isEmpty() || outStackPrecedence(infix[i]) > inStackPrecedence(st.stackTop())) {
                st.push(infix[i++]);
            } else if (outStackPrecedence(infix[i]) < inStackPrecedence(st.stackTop())) {
                postfix[j++] = st.pop();
            } else { // Matching parentheses case: outStack == inStack
                st.pop(); // Discard '(' from stack
                i++;      // Skip ')' from infix
            }
        }
    }

    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    cout << "--- Stack Application: Advanced Infix to Postfix ---" << endl;

    const char* infix1 = "((a+b)*c)-d^e^f";
    const char* infix2 = "a+b*(c^d-e)^(f+g*h)-i";

    char* postfix1 = infixToPostfixAdvanced(infix1);
    char* postfix2 = infixToPostfixAdvanced(infix2);

    cout << "\nInfix 1  : " << infix1 << endl;
    cout << "Postfix 1: " << postfix1 << endl;

    cout << "\nInfix 2  : " << infix2 << endl;
    cout << "Postfix 2: " << postfix2 << endl;

    delete[] postfix1;
    delete[] postfix2;

    return 0;
}