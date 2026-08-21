/*
Program Name: Queue - Implementation using Linked List (Class-based)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Implements a dynamic FIFO Queue using Singly Linked List nodes.
   - Eliminates fixed array capacity limits while providing constant-time O(1) operations.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Enqueue Operation:
     * Create a new node `t`. If `t == NULL`, heap memory is full (Queue Overflow).
     * If `front == NULL` (Queue was empty), set `front = rear = t`.
     * Else, link `rear->next = t` and update `rear = t`.
   - Dequeue Operation:
     * Check if `front == NULL` (Queue Underflow).
     * Save data from `front` node, move `front = front->next`, and `delete` the old node.
     * If `front` becomes NULL, reset `rear = NULL`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for Enqueue and Dequeue.
   - Space Complexity : O(n) Dynamic allocation for each node.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node* next;
};

// Queue Class using Linked List
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Destructor
    ~Queue() {
        Node* p = front;
        while (front != NULL) {
            front = front->next;
            delete p;
            p = front;
        }
        rear = NULL;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return front == NULL;
    }

    // Enqueue Operation (Insert at rear)
    void enqueue(int x) {
        Node* t = new Node();
        if (t == NULL) {
            cout << "Queue Overflow! Heap memory is full." << endl;
            return;
        }

        t->data = x;
        t->next = NULL;

        if (isEmpty()) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }

    // Dequeue Operation (Delete from front)
    int dequeue() {
        int x = -1;
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return x;
        }

        Node* p = front;
        x = front->data;
        front = front->next;

        // If queue becomes empty, reset rear to NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete p; // Physically free heap memory
        return x;
    }

    // Display Queue Elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node* p = front;
        cout << "Queue Elements: ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Queue Implementation using Linked List (Class) ---" << endl;

    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    // Dequeue elements
    cout << "\nDequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    // Enqueue more elements
    cout << "\nEnqueueing 50 and 60..." << endl;
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}