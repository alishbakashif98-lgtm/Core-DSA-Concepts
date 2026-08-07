## Outputs of Stack

## stack_array.cpp
```
--- Stack Implementation using Array ---
Stack (Top to Bottom): 50 40 30 20 10 
Stack Overflow! Cannot push 60

Element at position 1 (Top) : 50
Element at position 3        : 30
Current Top Element         : 50

Popped element: 50
Popped element: 40
Stack (Top to Bottom): 30 20 10 
```

---

## stack_linked_list.cpp
```
--- Stack Implementation using Linked List ---
Stack (Top to Bottom): 50 -> 40 -> 30 -> 20 -> 10 -> NULL

Top Element               : 50
Element at position 1 (Top): 50
Element at position 3       : 30

Popped element: 50
Popped element: 40
Stack (Top to Bottom): 30 -> 20 -> 10 -> NULL
```

---

## parenthesis_matching.cpp
```
--- Stack Application: Parentheses Matching ---

Expression 1: ((a+b)*(c-d)) -> Balanced
Expression 2: (((a+b)*c) -> Unbalanced
Expression 3: ((a+b)*c)) -> Unbalanced
```

---

## extended_parenthesis_matching.cpp
```
--- Stack Application: Extended Parentheses Matching ---

Expression 1: {[a+b]*(c+d)} -> Balanced
Expression 2: {[(a+b)]} -> Balanced
Expression 3: {[(a+b])} -> Unbalanced
```

---

## infix_to_postfix.cpp
```
--- Stack Application: Infix to Postfix Conversion ---

Infix Expression 1  : a+b*c
Postfix Expression 1: abc*+

Infix Expression 2  : a+b*c-d/e
Postfix Expression 2: abc*+de/-
```

---

## infix_to_postfix_advanced.cpp
```
--- Stack Application: Advanced Infix to Postfix ---

Infix 1  : ((a+b)*c)-d^e^f
Postfix 1: ab+c*def^^-

Infix 2  : a+b*(c^d-e)^(f+g*h)-i
Postfix 2: abcd^e-fgh*+^*+i-
```

---