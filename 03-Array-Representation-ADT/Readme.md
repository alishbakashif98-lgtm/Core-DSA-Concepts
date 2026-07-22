## Outputs of Array-Representation-ADT

## array_representation.cpp
```
--- Stack Array (Static) Elements ---
2 4 6 8 10 

--- Heap Array (Dynamic) Elements ---
3 5 7 9 11
```

---

## increase_array_size.cpp
```
--- Expanded Heap Array Elements ---
2 4 6 8 10 
Array size successfully increased dynamically!
```

---

## 2d_arrays.cpp
```
--- 2D Array (Double Pointer Model) Output ---
1 2 3 4 
5 6 7 8 
9 10 11 12 
```

---

## array_adt_basics.cpp
```
--- Array ADT Basics: Display & Append ---
Elements are: 12 15 25 

Appending 45 to the array...
Elements are: 12 15 25 45 

Appending 70 to the array...
Elements are: 12 15 25 45 70 
```

---

## array_adt_insert.cpp
```
--- Array ADT: Insert Operation Showcase ---
Current Elements: 10 20 30 40 

[Test 1] Inserting 25 at index 2...
Successfully inserted 25 at index 2
Current Elements: 10 20 25 30 40 

[Test 2] Inserting 50 at index 5 (current length)...
Successfully inserted 50 at index 5
Current Elements: 10 20 25 30 40 50 

[Test 3] Attempting to insert 99 at an unreachable index 8...
Insert Error: Invalid Index 8 (Out of bounds)!
Current Elements: 10 20 25 30 40 50 
```

---

## array_adt_delete.cpp
```
--- Array ADT: Easy Delete Showcase ---
Current Array: 10 20 30 40 50 

[Test 1] Deleting element from index 1...
Deleted Value: 20
Current Array: 10 30 40 50 

[Test 2] Deleting the last element (index 3)...
Deleted Value: 50
Current Array: 10 30 40 

[Test 3] Attempting to delete from invalid index -5...
Delete Error: Invalid Index -5!
```

---

## array_adt_linear_search.cpp
```
--- Array ADT: Linear Search Showcase ---
Current Elements: 40 10 20 50 30 
Searching for 20... Found at index: 2

Before Transposition Search: Current Elements: 40 10 20 50 30 
After Transposition (50 moved 1 step ahead): Current Elements: 40 10 50 20 30 

Before Move-To-Head Search: Current Elements: 40 10 20 50 30 
After Move-To-Head (30 jumped to index 0): Current Elements: 30 10 20 50 40 
```

---

## array_adt_binary_search.cpp
```
--- Array ADT: Binary Search Showcase ---
Current Elements: 10 20 30 40 50 

[Iterative] Searching for key 40...
Result: Found at index 3

[Recursive] Searching for key 40...
Result: Found at index 3
```

---

## array_adt_get_set_stats.cpp
```
--- Array ADT: Get, Set, & Statistics Operations ---
Current Elements: 12 45 23 89 34 

[Get] Element at index 3 is: 89
Successfully set index 2 to value 99
Current Elements: 12 45 99 89 34 

--- Array Analytics ---
Maximum Element: 99
Minimum Element: 12
Sum of Elements: 279
Average Value:   55.8
```

---

## array_adt_reverse_shift.cpp
```
--- Array ADT: Reverse & Shift Operations ---

Original Array: Current Elements: 10 20 30 40 50 
After In-Place Reversing: Current Elements: 50 40 30 20 10 
After Auxiliary Reversing: Current Elements: 50 40 30 20 10 

Before Left Shift: Current Elements: 10 20 30 40 50 
After Left Shift (first element removed, 0 added at end): Current Elements: 20 30 40 50 0 
```

---