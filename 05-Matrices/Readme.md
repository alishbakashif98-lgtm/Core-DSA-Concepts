## Outputs of Matrices

## diagonal_matrix.cpp
```
--- Diagonal Matrix ---

Matrix Output:
5 0 0 0 
0 8 0 0 
0 0 3 0 
0 0 0 9 

Element at (2,2): 8
Element at (1,3): 0
```

---

## lower_triangular_matrix.cpp
```
--- Lower Triangular Matrix (Row-Major) ---

Matrix Output:
11 0 0 0 
21 22 0 0 
31 32 33 0 
41 42 43 44 

Element at (3,2): 32
Element at (1,4): 0
```

---

## upper_triangular_matrix.cpp
```
--- Upper Triangular Matrix (Row-Major) ---

Matrix Output:
11 12 13 14 
0 22 23 24 
0 0 33 34 
0 0 0 44 

Element at (1,3): 13
Element at (3,1): 0
```

---

## symmetric_matrix.cpp
```
--- Symmetric Matrix Showcase ---

Matrix Output:
2 3 4 5 
3 6 8 9 
4 8 7 1 
5 9 1 3 

Element at (2,1): 3
Element at (1,2) [Symmetric Mirror]: 3
```

---

## tridiagonal_matrix.cpp
```
--- Tridiagonal Matrix Showcase ---

Matrix Output:
1 3 0 0 0 
2 1 3 0 0 
0 2 1 3 0 
0 0 2 1 3 
0 0 0 2 1 

Element at (3,3) [Main]:  1
Element at (4,3) [Lower]: 2
Element at (2,3) [Upper]: 3
Element at (1,4) [Out]:   0
```

---

## sparse_matrix.cpp
```
--- Sparse Matrix Representation & Addition ---

Matrix 1 Output:
0 0 0 0 0 
0 10 0 0 0 
0 0 0 20 0 
0 0 0 0 0 
0 0 0 0 30 

Matrix 2 Output:
0 0 5 0 0 
0 0 0 0 0 
0 0 0 15 0 
0 25 0 0 0 
0 0 0 0 0 

Sum Matrix Output (s1 + s2):
0 0 5 0 0 
0 10 0 0 0 
0 0 0 35 0 
0 25 0 0 0 
0 0 0 0 30 
```

---