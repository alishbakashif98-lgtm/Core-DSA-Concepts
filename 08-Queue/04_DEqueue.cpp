/*
Program Name: Queue - Double-Ended Queue (DEQueue) Implementation using Array (Class-based)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - A DEQueue (Double-Ended Queue) is an advanced generalized queue where insertions and deletions
     can be performed from both ends (Front and Rear).

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - enqueueRear: Standard enqueue at `rear++`.
   - dequeueFront: Standard dequeue at `front++`.
   - enqueueFront: Decrements `front--` and inserts element (requires freed space at front).
   - dequeueRear: Removes element at `Q[rear]` and decrements `rear--`.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Time Complexity  : O(1) for all four insertion/deletion operations.
   - Space Complexity : O(n) Array allocation.
====================================================================================================
*/

#include <iostream>
using namespace std;

class DEQueue {
private:
    int size;
    int front;
    int rear;
    int* Q;

public:
    // Constructor
    DEQueue(int size) {
        this->size = size;
        this->front = -1;
        this->rear = -1;
        this->Q = new int[this->size];
    }

    // Destructor
    ~DEQueue() {
        delete[] Q;
    }

    // Check if DEQueue is Empty
    bool isEmpty() {
        return front == rear;
    }

    // Check if Rear is Full
    bool isFullRear() {
        return rear == size - 1;
    }

    // Check if Front is Full (Cannot insert at front)
    bool isFullFront() {
        return front == -1;
    }

    // 1. Insert at Rear End
    void enqueueRear(int x) {
        if (isFullRear()) {
            cout << "DEQueue Overflow at Rear! Cannot insert " << x << endl;
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    // 2. Insert at Front End
    void enqueueFront(int x) {
        if (isFullFront()) {
            cout << "DEQueue Overflow at Front! No space available before front." << endl;
        } else {
            Q[front] = x;
            front--;
        }
    }

    // 3. Delete from Front End
    int dequeueFront() {
        int x = -1;
        if (isEmpty()) {
            cout << "DEQueue Underflow at Front!" << endl;
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    // 4. Delete from Rear End
    int dequeueRear() {
        int x = -1;
        if (isEmpty()) {
            cout << "DEQueue Underflow at Rear!" << endl;
        } else {
            x = Q[rear];
            rear--;
        }
        return x;
    }

    // Display Elements
    void display() {
        if (isEmpty()) {
            cout << "DEQueue is Empty!" << endl;
            return;
        }

        cout << "DEQueue Elements: ";
        for (int i = front + 1; i <= rear; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Double-Ended Queue (DEQueue) Implementation ---" << endl;

    DEQueue dq(6);

    // Standard insertions at rear
    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueRear(30);
    dq.enqueueRear(40);
    dq.display();

    // Deletion from front (creates empty space at front)
    cout << "\nDequeued from Front: " << dq.dequeueFront() << endl;
    cout << "Dequeued from Front: " << dq.dequeueFront() << endl;
    dq.display();

    // Insertion at front using freed space
    cout << "\nEnqueueing 50 and 60 at Front..." << endl;
    dq.enqueueFront(50);
    dq.enqueueFront(60);
    dq.display();

    // Deletion from rear
    cout << "\nDequeued from Rear: " << dq.dequeueRear() << endl;
    dq.display();

    return 0;
}