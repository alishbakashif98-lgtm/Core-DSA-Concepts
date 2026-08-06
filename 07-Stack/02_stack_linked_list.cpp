/*
Program Name: Stack - Implementation using Linked List


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A dynamic LIFO stack implementation using a Singly Linked List.
   - The `head` pointer acts as the `top` of the stack so push and pop operations run in O(1) time.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Push Operation:
     * Allocate dynamic memory for new node `t`.
     * If `t == NULL`, heap memory is full (Stack Overflow).
     * Else, `t->data = x; t->next = top; top = t;`
   - Pop Operation:
     * If `top == NULL` (Stack Underflow).
     * Else, save `p = top`, `x = top->data`, update `top = top->next`, `delete p`.
   - Peek Operation:
     * Traverse `p = top` for `pos - 1` steps. If `p != NULL`, return `p->data`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for Push, Pop, stackTop, and isEmpty. O(k) for Peek at position k.
   - Space Complexity : O(n) Dynamic node allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;
};

// Stack Class Definition using Linked List
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

    // Function to Check if Stack is Empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to Check if Stack is Full (Heap Exhaustion)
    bool isFull() {
        Node* t = new Node();
        bool full = (t == NULL);
        delete t;
        return full;
    }

    // Function to Push Element onto Stack
    void push(int x) {
        Node* t = new Node();
        if (t == NULL) {
            cout << "Stack Overflow!" << endl;
        } else {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    // Function to Pop Element from Stack
    int pop() {
        int x = -1;
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

    // Function to Peek Element at a Position (1-based from top)
    int peek(int pos) {
        if (isEmpty()) return -1;

        Node* p = top;
        for (int i = 0; p != NULL && i < pos - 1; i++) {
            p = p->next;
        }

        if (p != NULL) {
            return p->data;
        }
        return -1;
    }

    // Function to Get Top Element
    int stackTop() {
        if (isEmpty()) return -1;
        return top->data;
    }

    // Function to Display Stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node* p = top;
        cout << "Stack (Top to Bottom): ";
        while (p != NULL) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "--- Stack Implementation using Linked List ---" << endl;

    Stack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();

    // Peek operations
    cout << "\nTop Element               : " << st.stackTop() << endl;
    cout << "Element at position 1 (Top): " << st.peek(1) << endl;
    cout << "Element at position 3       : " << st.peek(3) << endl;

    // Pop elements
    cout << "\nPopped element: " << st.pop() << endl;
    cout << "Popped element: " << st.pop() << endl;

    st.display();

    return 0;
}