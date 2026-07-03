## Outputs of Essential-Concepts

## arrays_basics.cpp
```
Element at index 0: 2
Element at index 2: 6

--- Printing all elements using for loop ---
2 4 6 8 10 

--- Printing using For-Each loop (C++11) ---
2 4 6 8 10 

Total size of array A in memory: 20 bytes
```

---

## structures_basics.cpp
```
Initial Length: 10
Initial Breadth: 5

--- After Modifying Values ---
New Length: 15
New Breadth: 8

Total size of structure r1: 8 bytes
```

---

## pointers_basics.cpp
```
Value of a: 10
Address of a (&a): 0x61ff0c
Value stored in pointer p (Address of a): 0x61ff0c
Address of pointer p itself (&p): 0x61ff08

--- Dereferencing the Pointer ---
Value pointed by p (*p): 10

--- After Modifying Value via Pointer ---
New value of a: 20
Value pointed by p (*p): 20
```

---

## reference_basics.cpp
```
Value of a: 10
Value of r: 10
Address of a: 0x61ff08
Address of r: 0x61ff08

--- Modifying value through Reference ---
New value of a: 25
New value of r: 25
```

---

## pointer_to_structure.cpp
```
Using Object (Dot Operator):
Length: 10
Breadth: 5

Using Pointer (Arrow Operator):
Length via Pointer: 10
Breadth via Pointer: 5

--- After Modifying via Pointer ---
New Length: 20
New Breadth: 15
```

---

## functions_basics.cpp
```
Value of a: 10
Value of b: 20
Sum (Result from function): 30
```

---

## parameter_passing.cpp
```
--- Initial Values ---
a = 10, b = 20

--- After swapByValue ---
a = 10, b = 20 (No change)

--- After swapByAddress ---
a = 20, b = 10 (Values Swapped!)

--- After swapByReference ---
a = 20, b = 10 (Values Swapped!)
```

---

## array_as_parameter.cpp
```
--- Test 1: Passing Static Array ---
Printing elements inside function: 2 4 6 8 10 

--- Test 2: Returning Array from Function ---
Printing dynamic array elements in main: 10 20 30 40 50 
```

---

## struct_as_parameter.cpp
```
--- Initial Value in main ---
Original Length: 10, Breadth: 5

--- Testing Pass by Value ---
Inside changeLengthValue (Copy): 20
Value in main after function call: 10 (Unchanged)

--- Testing Pass by Address ---
Inside changeLengthAddress (Original): 30
Value in main after function call: 30 (Changed!)

--- Testing Pass by Reference ---
Inside changeLengthReference (Original): 50
Value in main after function call: 50 (Changed!)
```

---

## struct_and_functions.cpp
```
--- Initializing Rectangle ---
Length: 10, Breadth: 5
Area of Rectangle: 50

--- Modifying Length via Function ---
New Length: 15
New Area of Rectangle: 75
```

---

## classes_and_constructors
```
--- Creating Object & Automatic Initialization via Constructor ---
Initial Area: 50

--- Modifying Data via Member Function ---
New Length: 15
New Area: 75

```

---