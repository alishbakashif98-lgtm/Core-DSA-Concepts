/*
Program Name: Queue - Priority Queue Implementation using Multiple Queues (Class-based)


1. CONCEPTUAL DEFINITION:
----------------------------------------------------------------------------------------------------
   - Implements a multi-level Priority Queue using an array of FIFO queues.
   - Elements with higher priority numbers are served before lower priority elements.
   - Elements with identical priorities follow standard FIFO order.

2. ALGORITHMIC FLOW:
----------------------------------------------------------------------------------------------------
   - Enqueue: Insert element into the specific queue matching its priority level.
   - Dequeue: Scan from highest priority queue down to lowest; dequeue from the first non-empty queue.

3. COMPLEXITY ANALYSIS:
----------------------------------------------------------------------------------------------------
   - Enqueue Complexity : O(1) Direct insertion into specific priority level.
   - Dequeue Complexity : O(k) where k is the number of priority levels.
====================================================================================================
*/

#include <iostream>
using namespace std;

// Node for dynamic linked queue
struct Node {
    char data;
    Node* next;
};

// Base Queue Class
class ElementQueue {
private:
    Node* front;
    Node* rear;

public:
    ElementQueue() {
        front = NULL;
        rear = NULL;
    }

    ~ElementQueue() {
        Node* p = front;
        while (front != NULL) {
            front = front->next;
            delete p;
            p = front;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insert(char x) {
        Node* t = new Node();
        if (t == NULL) return;
        t->data = x;
        t->next = NULL;

        if (isEmpty()) {
            front = rear = t;
        } else {
            rear->next = t;
            rear = t;
        }
    }

    char remove() {
        if (isEmpty()) return '\0';

        Node* p = front;
        char x = front->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete p;
        return x;
    }

    void printQueue() {
        Node* p = front;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

// Priority Queue Manager Class
class PriorityQueue {
private:
    int totalPriorities;
    ElementQueue* qArray;

public:
    PriorityQueue(int totalLevels) {
        totalPriorities = totalLevels;
        qArray = new ElementQueue[totalPriorities];
    }

    ~PriorityQueue() {
        delete[] qArray;
    }

    // Insert element based on priority (1-indexed: 1 = Highest)
    void enqueue(char x, int priority) {
        if (priority >= 1 && priority <= totalPriorities) {
            qArray[priority - 1].insert(x);
        } else {
            cout << "Invalid Priority Level: " << priority << endl;
        }
    }

    // Dequeue highest priority element available
    char dequeue() {
        for (int i = 0; i < totalPriorities; i++) {
            if (!qArray[i].isEmpty()) {
                return qArray[i].remove();
            }
        }
        cout << "Priority Queue Underflow!" << endl;
        return '\0';
    }

    // Display all priority queues
    void display() {
        cout << "\n--- Priority Queue State ---" << endl;
        for (int i = 0; i < totalPriorities; i++) {
            cout << "Priority " << (i + 1) << ": ";
            if (qArray[i].isEmpty()) {
                cout << "[Empty]";
            } else {
                qArray[i].printQueue();
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "--- Priority Queue Implementation (Multiple Levels) ---" << endl;

    PriorityQueue pq(3); // 3 Priority Levels: 1 (Highest), 2 (Medium), 3 (Lowest)

    // Inserting elements with different priorities
    pq.enqueue('A', 1);
    pq.enqueue('B', 1);
    pq.enqueue('C', 2);
    pq.enqueue('D', 3);
    pq.enqueue('E', 2);
    pq.enqueue('F', 1);

    pq.display();

    // Dequeue according to priority order
    cout << "\n--- Dequeue Operations ---" << endl;
    cout << "Dequeued: " << pq.dequeue() << " (Expected 'A' from Priority 1)" << endl;
    cout << "Dequeued: " << pq.dequeue() << " (Expected 'B' from Priority 1)" << endl;
    cout << "Dequeued: " << pq.dequeue() << " (Expected 'F' from Priority 1)" << endl;
    cout << "Dequeued: " << pq.dequeue() << " (Expected 'C' from Priority 2)" << endl;

    pq.display();

    return 0;
}