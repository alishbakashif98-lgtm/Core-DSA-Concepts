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

## sorted_array_operations.cpp
```
--- Array ADT: Sorted Operations & Rearrangement ---

[Test 1] Original Sorted Array: Current Elements: 10 20 35 45 60 
Successfully inserted 30 in sorted order.
Current Elements: 10 20 30 35 45 60 

[Test 2] Checking IsSorted Status...
Checking current array: Current Elements: 10 20 30 35 45 60 
Is Sorted? Yes (True)
Checking unsorted array: Current Elements: 10 50 20 40 30 
Is Sorted? No (False)

[Test 3] Rearranging Positives & Negatives...
Before Rearranging: Current Elements: -6 3 -8 10 5 -2 7 
After Rearranging (Negatives on left, Positives on right): Current Elements: -6 -2 -8 10 5 3 7 
```

---

## merge_sorted_arrays.cpp
```
--- Array ADT: Merging Two Sorted Arrays ---
Array 1: Current Elements: 3 8 16 20 25 
Array 2: Current Elements: 4 10 12 22 23 

Merging both sorted arrays into Array 3...
Merged Array 3: Current Elements: 3 4 8 10 12 16 20 22 23 25 
```

---

## array_set_operations.cpp
```
--- Array ADT: Set Operations (Sorted Arrays) ---
Array 1 (A): Current Elements: 2 6 10 15 25 
Array 2 (B): Current Elements: 3 6 15 20 30 

[1] Set Union (A U B):
Current Elements: 2 3 6 10 15 20 25 30 

[2] Set Intersection (A N B):
Current Elements: 6 15 

[3] Set Difference (A - B):
Current Elements: 2 10 25 
```

---

## array_adt_missing_elements.cpp
```
--- Array ADT: Finding Missing Elements Showcase ---

[Case 1] First N Natural Numbers Missing Item: 5

[Case 2] Sorted Array Single Missing Item: 11

[Case 3] Sorted Array Multiple Items: Missing elements: 8 10 13 14 

[Case 4] Unsorted Array Multiple Items (Hashing): Missing elements: 5 8 
```

---

## array_adt_duplicates_and_pairs.cpp
```
--- Array ADT: Duplicates & Target Sum Pairs Showcase ---

[Test 1] Sorted Array Duplicates:
Duplicates in Sorted Array: 
  Element 8 appears 2 times.
  Element 15 appears 3 times.

[Test 2] Unsorted Array Duplicates (Hashing):
Duplicates in Unsorted Array (Hashing): 
  Element 6 appears 3 times.
  Element 8 appears 2 times.

[Test 3] Target Sum Pairs K = 10 (Unsorted Array):
Pairs with Sum 10 (Unsorted Hashing): 
  Pair Found: (7, 3)
  Pair Found: (2, 8)

[Test 4] Target Sum Pairs K = 10 (Sorted Array):
Pairs with Sum 10 (Sorted Two-Pointer): 
  Pair Found: (1, 9)
  Pair Found: (4, 6)
```

---

## array_adt_menu_driver.cpp
```
==================================================
      ARRAY ADT: INTERACTIVE MENU DRIVER          
==================================================
[System]: Array initialized with 10 elements: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}

---------------- MENU OPTIONS ----------------
1. Display Elements      2. Append Element
3. Insert at Index       4. Delete from Index
5. Linear Search         6. Binary Search
7. Get Value at Index    8. Set Value at Index
9. Find Max & Min       10. Sum & Average
11. Reverse Array        0. Exit
----------------------------------------------
Enter your choice: 6
Enter key to search (Binary - Sorted Array): 50
[Found] Element located at index 4

---------------- MENU OPTIONS ----------------
1. Display Elements      2. Append Element
3. Insert at Index       4. Delete from Index
5. Linear Search         6. Binary Search
7. Get Value at Index    8. Set Value at Index
9. Find Max & Min       10. Sum & Average
11. Reverse Array        0. Exit
----------------------------------------------
Enter your choice: 7
Enter index: 8
Value at index 8 is 90

---------------- MENU OPTIONS ----------------
1. Display Elements      2. Append Element
3. Insert at Index       4. Delete from Index
5. Linear Search         6. Binary Search
7. Get Value at Index    8. Set Value at Index
9. Find Max & Min       10. Sum & Average
11. Reverse Array        0. Exit
----------------------------------------------
Enter your choice: 0

Exiting Array ADT Application. Goodbye!
```

---



