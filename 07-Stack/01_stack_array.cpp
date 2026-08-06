/*
Program Name: Stack - Implementation using Array


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Stack is a linear LIFO (Last In, First Out) data structure.
   - Array implementation uses a fixed-capacity dynamic array with a `top` index variable tracking 
     the uppermost element.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Push Operation:
     * Check if `top == size - 1` (Stack Overflow).
     * Else, increment `top` and store element at `S[top]`.
   - Pop Operation:
     * Check if `top == -1` (Stack Underflow).
     * Else, extract `x = S[top]`, decrement `top`, and return `x`.
   - Peek Operation:
     * Target index = `top - pos + 1`.
     * If target index < 0 or > top, position is invalid.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for Push, Pop, Peek, isEmpty, and isFull.
   - Space Complexity : O(n) Array allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Stack Class Definition using Array
struct Stack {
    int size;
    int top;
    int* S;
};

// Function to Create/Initialize Stack
void create(Stack* st, int size) {
    st->size = size;
    st->top = -1;
    st->S = new int[st->size];
}

// Function to Display Stack Elements
void display(Stack st) {
    if (st.top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack (Top to Bottom): ";
    for (int i = st.top; i >= 0; i--) {
        cout << st.S[i] << " ";
    }
    cout << endl;
}

// Function to Check if Stack is Empty
bool isEmpty(Stack st) {
    return st.top == -1;
}

// Function to Check if Stack is Full
bool isFull(Stack st) {
    return st.top == st.size - 1;
}

// Function to Push Element onto Stack
void push(Stack* st, int x) {
    if (isFull(*st)) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        st->top++;
        st->S[st->top] = x;
    }
}

// Function to Pop Element from Stack
int pop(Stack* st) {
    int x = -1;
    if (isEmpty(*st)) {
        cout << "Stack Underflow!" << endl;
    } else {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

// Function to Peek Element at a Given Position (1-based from top)
int peek(Stack st, int pos) {
    int index = st.top - pos + 1;
    if (index < 0 || index > st.top) {
        cout << "Invalid Position!" << endl;
        return -1;
    }
    return st.S[index];
}

// Function to Get Top Element of Stack
int stackTop(Stack st) {
    if (isEmpty(st)) return -1;
    return st.S[st.top];
}

int main() {
    cout << "--- Stack Implementation using Array ---" << endl;

    Stack st;
    create(&st, 5);

    // Push operations
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    // Overflow test
    push(&st, 60);

    // Peek operations
    cout << "\nElement at position 1 (Top) : " << peek(st, 1) << endl;
    cout << "Element at position 3        : " << peek(st, 3) << endl;
    cout << "Current Top Element         : " << stackTop(st) << endl;

    // Pop operations
    cout << "\nPopped element: " << pop(&st) << endl;
    cout << "Popped element: " << pop(&st) << endl;

    display(st);

    // Cleanup dynamic allocation
    delete[] st.S;

    return 0;
}