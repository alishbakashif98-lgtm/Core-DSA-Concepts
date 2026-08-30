## Outputs of AVL-Trees

## avl_tree_rotations.cpp
```
--- AVL Tree Self-Balancing Insertions ---
Inserting keys: 10 20 30 25 28 27 5 

AVL In-order [Val(Height)]: 5(H:1) 10(H:2) 20(H:1) 25(H:3) 27(H:1) 28(H:2) 30(H:1) 
Balanced Root Node: 25 (Tree Height: 3)
```

---

## avl_tree_deletion.cpp
```
--- AVL Tree Node Deletion & Self-Rebalancing ---
Initial Tree:
AVL In-order [Val(Height)]: 5(H:1) 10(H:2) 20(H:1) 25(H:3) 27(H:1) 28(H:2) 30(H:1) 
Root: 25 (Tree Height: 3)

Deleting 28...
AVL In-order [Val(Height)]: 5(H:1) 10(H:2) 20(H:1) 25(H:3) 27(H:1) 30(H:2) 
Root: 25 (Tree Height: 3)

Deleting Root Node (25)...
AVL In-order [Val(Height)]: 5(H:1) 10(H:2) 20(H:1) 27(H:3) 30(H:1) 
Root: 27 (Tree Height: 3)
```

---