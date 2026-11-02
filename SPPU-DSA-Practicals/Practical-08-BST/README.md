# Practical 8 – Binary Search Tree Operations

## Aim
Construct a Binary Search Tree (BST) and perform insertion, longest-path/height calculation, minimum-value search, left-right pointer swapping and searching.

## Objectives
- Understand tree nodes and recursive operations.
- Implement BST insertion and searching.
- Find the height and minimum value.
- Mirror a tree by swapping left and right pointers.
- Perform inorder traversal.

## Problem statement
Starting with an empty BST, insert the given values and then support: insert a node; find the number of nodes in the longest path from root; find the minimum value; swap left and right pointers at every node; and search for a value.

## Requirements
C compiler (`gcc`), structures, pointers, dynamic memory allocation and recursion.

## Theory
A **binary tree** is a tree in which each node has at most two children, called left and right. A **Binary Search Tree** follows an ordering rule: in a normal BST, values in the left subtree are smaller than the node and values in the right subtree are larger. This program ignores duplicate values.

**Inorder traversal** visits left subtree, root and right subtree. In a normal BST, this produces ascending order. The **height measured in nodes** is one plus the maximum height of the left and right subtrees; an empty tree has height zero.

## Algorithm
1. Create a root pointer initialized to `NULL`.
2. Insert each input value by comparing it with the current node and recursively moving left or right.
3. For height, recursively calculate left and right heights and return `1 + max(left, right)`.
4. In a normal BST, find the minimum by repeatedly following left pointers.
5. Mirror the tree by swapping the left and right pointers at every node recursively.
6. Search by comparing the key with the current node and following the correct subtree.
7. Display inorder traversal.

## Sample test
Initial values: `50 30 70 20 40 60 80`.
- Inorder before mirror: `20 30 40 50 60 70 80`.
- Height in nodes: `3`.
- Minimum before mirror: `20`.
- Search `60`: found.
- After mirror, inorder: `80 70 60 50 40 30 20`.

## Complexity
Let h be tree height and n the number of nodes.
- Insert: O(h); average O(log n) for a reasonably balanced tree, worst O(n) for a skewed tree.
- Search: O(h); average O(log n), worst O(n).
- Minimum: O(h); average O(log n), worst O(n).
- Height calculation: O(n).
- Mirroring: O(n).
- Inorder traversal: O(n).

## Corrections and implementation notes
The uploaded C program's ordinary BST search assumes the original ordering. After swapping every node's left and right pointers, the tree is mirrored and the ordinary comparison direction is reversed. This version tracks whether the tree is mirrored so that minimum, insertion and search continue to work after the swap. The tree is freed before program exit.

## Important viva questions
1. **What is a tree?** A non-linear hierarchical data structure made of nodes and edges.
2. **What is a BST?** A binary tree with an ordering rule for left and right subtrees.
3. **What is the root?** The topmost node of a tree.
4. **What is a leaf node?** A node with no children.
5. **What is inorder traversal?** Left, Root, Right.
6. **What does inorder traversal produce in a normal BST?** Values in ascending order.
7. **What is the height used in this program?** The number of nodes on the longest root-to-leaf path.
8. **What is a skewed tree?** A tree where nodes mostly form a chain on one side.
9. **What is the worst-case search time in a BST?** O(n).
10. **What happens after mirroring a BST?** The left/right ordering is reversed; ordinary BST comparisons must be reversed too.

## Conclusion
A BST was implemented with insertion, height, minimum, mirroring, searching and inorder traversal operations.

## Compile and run
```bash
gcc binary_search_tree.c -o binary_search_tree
./binary_search_tree
```
