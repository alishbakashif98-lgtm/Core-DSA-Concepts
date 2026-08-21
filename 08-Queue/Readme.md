## Outputs of Queue

## queue_array.cpp
```
--- Queue Implementation using Array (Class) ---
Queue Elements: 10 20 30 40 50 
Queue Overflow! Cannot enqueue 60

Dequeued element: 10
Dequeued element: 20
Queue Elements: 30 40 50 
```

---

## circular_queue.cpp
```
--- Circular Queue Implementation using Array (Class) ---
Queue Elements: 10 20 30 40 
Queue Overflow! Cannot enqueue 50

Dequeued element: 10
Dequeued element: 20
Queue Elements: 30 40 

Enqueueing 50 and 60 (reusing recycled front spaces)...
Queue Elements: 30 40 50 60 
```

---
## queue_linked_list.cpp
```
--- Queue Implementation using Linked List (Class) ---
Queue Elements: 10 20 30 40 

Dequeued element: 10
Dequeued element: 20
Queue Elements: 30 40 

Enqueueing 50 and 60...
Queue Elements: 30 40 50 60 
```

---

## DEqueue_linked_list.cpp
```
--- Double-Ended Queue (DEQueue) Implementation ---
DEQueue Elements: 10 20 30 40 

Dequeued from Front: 10
Dequeued from Front: 20
DEQueue Elements: 30 40 

Enqueueing 50 and 60 at Front...
DEQueue Elements: 60 50 30 40 

Dequeued from Rear: 40
DEQueue Elements: 60 50 30 
```

---

## priority_queue.cpp
```
--- Priority Queue Implementation (Multiple Levels) ---

--- Priority Queue State ---
Priority 1: A B F 
Priority 2: C E 
Priority 3: D 

--- Dequeue Operations ---
Dequeued: A (Expected 'A' from Priority 1)
Dequeued: B (Expected 'B' from Priority 1)
Dequeued: F (Expected 'F' from Priority 1)
Dequeued: C (Expected 'C' from Priority 2)

--- Priority Queue State ---
Priority 1: [Empty]
Priority 2: E 
Priority 3: D 
```

---
