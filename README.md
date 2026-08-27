# Core-DSA-Concepts
A well-organized repository containing fundamental to advanced Data Structures and Algorithms implemented in C and C++. This repository follows a structured learning path based on Master Classes.

## 📂 Repository Structure & Sections

### 📁 [01-Essential-Concepts](./01-Essential-Concepts/)
This section covers the absolute prerequisites required for DSA before diving into core structures. It includes foundational implementations of arrays (memory layouts), user-defined structures, pointer manipulation, memory management, reference mechanics, parameter passing methods (value, address, reference), and modern C++ features like classes, constructors, and template classes (generics).

### 📁 [02-Recursion](./02-Recursion/)
This section focuses entirely on understanding the mechanics of recursive processes and algorithmic optimization. It includes implementations of core recursion types (tail, head, tree, indirect, nested), mathematical models for sum, factorial, and optimized power functions, as well as advanced strategies like Horner's Rule and Memoization to optimize runtime execution and manage the call stack efficiently.

### 📂 [03-Array-Representation-ADT](./03-Array-Representation-ADT/)

This section focuses on the deep core mechanics of array representations and modern Abstract Data Type (ADT) design in C++. It covers 1D and multi-dimensional dynamic memory allocations, contiguous vs pointer-based matrix layouts, fundamental operations (insertion, deletion, search optimizations), sorted array manipulations, mathematical set operations, hashing-based search strategies, and a complete interactive menu-driven console application.

### 📂 [04-Strings](./04-Strings/)

This section covers fundamental and advanced string manipulation algorithms in C++. It explores character array representations, length calculation, case conversions (uppercase, lowercase, toggle), analytics (vowel, consonant, and word counting), in-place string reversal, validation, lexicographical comparisons, palindrome verification, duplicate detection via hash arrays and bitmasking, anagram checking, and string permutations using recursive backtracking.

### 📁 [05-Matrices](./05-Matrices/)
This section covers special square matrix representations (Diagonal, Lower/Upper Triangular, Symmetric, Tridiagonal) and Sparse Matrices using 1D/2D dynamic array optimizations in $O(1)$ space/access time, along with polynomial representation and addition.

### 📁 [06-LinkedList](./06-LinkedList/)
This section covers linear dynamic data structures in C++, including Singly, Circular, and Doubly Linked Lists. It explores node creation, dynamic memory management, iterative and recursive traversals, node insertion, deletion, sorted verification, duplicate removal, in-place reversal using sliding pointers, sorted list merging, Floyd's cycle detection algorithm, single-pass middle element discovery using slow and fast pointers, and stack-based intersection point detection for Y-shaped linked list structures.

### 📁 [07-Stack](./07-Stack/)

This section covers the LIFO (Last-In, First-Out) linear data structure in C++. It explores stack operations (`push`, `pop`, `peek`, `stackTop`, `isEmpty`, `isFull`) using both contiguous dynamic arrays and Singly Linked Lists. Additionally, it features practical applications including single and extended bracket parentheses matching, operator precedence-based Infix to Postfix conversions (with support for parentheses and right-associative exponentiation), and single-pass evaluation of postfix expressions using an operand stack.

### 📁 [08-Queue](./08-Queue/)

This section covers the FIFO (First-In, First-Out) linear data structure in C++ using Object-Oriented Programming (OOP) principles. It includes linear array queues with two-pointer tracking (`front`, `rear`), space-efficient circular queues via modulo indexing arithmetic, dynamic linked list-based queues, double-ended queues (DEQueue) for bidirectional operations, and multi-level priority queues backed by an array of queues.

### 📁 [09-Trees](./09-Trees/)

This section covers hierarchical tree data structures implemented in C++ using Object-Oriented Programming (OOP). It includes dynamic level-order binary tree generation using custom pointer queues, recursive and stack-based iterative traversals (Pre-order, In-order, Post-order, Level-order BFS), structural tree analytics (node counting, tree height, leaf/internal nodes, node sum), and complete tree reconstruction from traversal sequences (Preorder + Inorder).

### 📁 [10-Binary-Search-Trees](./10-Binary-Search-Trees/)

This section covers Binary Search Trees (BST) implemented in C++ using Object-Oriented Programming (OOP). It includes dynamic node insertion, recursive/iterative search algorithms, height-balanced recursive node deletion with in-order predecessor/successor replacements, and $O(n)$ stack-based tree reconstruction directly from preorder traversal sequences.