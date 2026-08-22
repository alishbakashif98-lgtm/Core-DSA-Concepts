/*
Program Name: Queue - Implementation using Array (Class-based)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Queue is a linear FIFO (First In, First Out) data structure.
   - Encapsulated within a C++ class with private members (`size`, `front`, `rear`, `Q`).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Enqueue Operation:
     * Check if `rear == size - 1` (Queue Full).
     * Else, increment `rear` and store element at `Q[rear]`.
   - Dequeue Operation:
     * Check if `front == rear` (Queue Empty).
     * Else, increment `front` and return `Q[front]`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for Enqueue and Dequeue.
   - Space Complexity : O(n) Dynamic Array allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    // Constructor
    Queue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->Q = new int[this->size];
    }

    // Destructor
    ~Queue() {
        delete[] Q;
    }

    // Function to Check if Queue is Empty
    bool isEmpty() {
        return front == rear;
    }

    // Function to Check if Queue is Full
    bool isFull() {
        return rear == size - 1;
    }

    // Function to Enqueue Element
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << x << endl;
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    // Function to Dequeue Element
    int dequeue() {
        int x = -1;
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    // Function to Display Queue Elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front + 1; i <= rear; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Queue Implementation using Array (Class) ---" << endl;

    Queue q(5);

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    // Overflow test
    q.enqueue(60);

    // Dequeue elements
    cout << "\nDequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    q.display();

    return 0;
}