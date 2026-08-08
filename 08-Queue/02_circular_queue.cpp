/*
Program Name: Queue - Circular Queue Implementation using Array (Class-based)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Reuses array positions by wrapping index operations using modulo arithmetic (`% size`).
   - Encapsulated within a C++ class to cleanly manage memory lifecycle using RAII.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Enqueue Operation:
     * Check if `(rear + 1) % size == front` (Queue Full).
     * Else, update `rear = (rear + 1) % size` and store element at `Q[rear]`.
   - Dequeue Operation:
     * Check if `front == rear` (Queue Empty).
     * Else, update `front = (front + 1) % size` and return `Q[front]`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for Enqueue and Dequeue.
   - Space Complexity : O(n) Dynamic Array allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    // Constructor
    CircularQueue(int size) {
        this->size = size;
        this->front = 0;
        this->rear = 0;
        this->Q = new int[this->size];
    }

    // Destructor
    ~CircularQueue() {
        delete[] Q;
    }

    // Function to Check if Queue is Empty
    bool isEmpty() {
        return front == rear;
    }

    // Function to Check if Queue is Full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to Enqueue Element
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }

    // Function to Dequeue Element
    int dequeue() {
        int x = -1;
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
        } else {
            front = (front + 1) % size;
            x = Q[front];
        }
        return x;
    }

    // Function to Display Circular Queue Elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";
        int i = (front + 1) % size;
        while (i != (rear + 1) % size) {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Circular Queue Implementation using Array (Class) ---" << endl;

    CircularQueue q(5); // Effective capacity = 4 elements

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    // Overflow test
    q.enqueue(50);

    // Dequeue elements
    cout << "\nDequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    // Enqueue new elements (reusing wrapped positions)
    cout << "\nEnqueueing 50 and 60 (reusing recycled front spaces)..." << endl;
    q.enqueue(50);
    q.enqueue(60);

    q.display();

    return 0;
}