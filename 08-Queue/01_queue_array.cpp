/*
Program Name: Queue - Implementation using Array


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A Queue is a linear FIFO (First In, First Out) data structure.
   - Array implementation uses two pointers: `front` (for deletion) and `rear` (for insertion).

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
   - Space Complexity : O(n) Array allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Queue Structure
struct Queue {
    int size;
    int front;
    int rear;
    int* Q;
};

// Function to Create Queue
void create(Queue* q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Q = new int[q->size];
}

// Function to Check if Queue is Empty
bool isEmpty(Queue q) {
    return q.front == q.rear;
}

// Function to Check if Queue is Full
bool isFull(Queue q) {
    return q.rear == q.size - 1;
}

// Function to Enqueue (Insert) Element
void enqueue(Queue* q, int x) {
    if (isFull(*q)) {
        cout << "Queue Overflow! Cannot enqueue " << x << endl;
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Function to Dequeue (Delete) Element
int dequeue(Queue* q) {
    int x = -1;
    if (isEmpty(*q)) {
        cout << "Queue Underflow!" << endl;
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Function to Display Queue Elements
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue Elements: ";
    for (int i = q.front + 1; i <= q.rear; i++) {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- Queue Implementation using Array ---" << endl;

    Queue q;
    create(&q, 5);

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(q);

    // Overflow test
    enqueue(&q, 60);

    // Dequeue elements
    cout << "\nDequeued element: " << dequeue(&q) << endl;
    cout << "Dequeued element: " << dequeue(&q) << endl;

    display(q);

    // Cleanup memory
    delete[] q.Q;

    return 0;
}