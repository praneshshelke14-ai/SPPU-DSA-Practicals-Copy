# Practical 4 – Set Operations Using Linked Lists

## Aim
Store the roll numbers of students who like Vanilla and Butterscotch ice cream in linked lists and calculate intersection, symmetric difference and the number who like neither flavour.

## Objectives
- Create and traverse singly linked lists.
- Avoid duplicate roll numbers in each set.
- Compute common and exclusive elements.
- Apply union cardinality to calculate the number of students who like neither flavour.

## Problem statement
Set A contains students who like Vanilla and set B contains students who like Butterscotch. Display students who like both, students who like either but not both, and the count of students who like neither.

## Requirements
C++ compiler (`g++`), structures, pointers, dynamic memory allocation and linked-list traversal.

## Theory
A **singly linked list** consists of nodes. Each node contains data and a pointer to the next node. Unlike an array, nodes need not be stored in contiguous memory.

For sets A and B:
- **Intersection (A ∩ B):** elements present in both sets.
- **Union (A ∪ B):** elements present in at least one set.
- **Symmetric difference:** elements present in A or B, but not in both.
- **Neither:** total class strength − number of elements in the union.

The uploaded document creates linked lists and then transfers values into STL `set` containers. This prepared program performs the set operations directly by traversing linked lists, keeping the implementation centred on the linked-list practical.

## Algorithm
1. Read the roll numbers for set A and create a linked list.
2. Read the roll numbers for set B and create another linked list.
3. For each node in A, search B; matching roll numbers form the intersection.
4. Add A elements not present in B to the symmetric difference.
5. Add B elements not present in A to the symmetric difference.
6. Copy unique elements from A and B into the union list.
7. Read total class strength and calculate `neither = total - union_count`.
8. Display results and free allocated nodes.

## Sample test
A = `{1, 2, 3, 4}`; B = `{3, 4, 5}`; total students = `7`.
- Both: `3 4`
- Either but not both: `1 2 5`
- At least one: `1 2 3 4 5`
- Neither: `7 - 5 = 2`

## Complexity
If lists contain a and b unique elements, the straightforward membership checks take O(a × b) time in the worst case. Building result lists can add further traversal costs. Auxiliary storage is O(a + b) for the result lists.

## Important viva questions
1. **What is a linked list?** A dynamic linear structure made of nodes connected by pointers.
2. **What does a node contain?** Data and a link to the next node.
3. **What is intersection?** Elements common to both sets.
4. **What is union?** All distinct elements from both sets.
5. **What is symmetric difference?** Elements in exactly one of the two sets.
6. **How do you calculate neither?** Total class strength minus the union size.
7. **Why avoid duplicates?** A mathematical set contains each element at most once.
8. **Why free nodes?** To release dynamically allocated memory and avoid memory leaks.

## Conclusion
Singly linked lists were used to store the two student sets and calculate intersection, symmetric difference, union and the number of students who like neither flavour.

## Compile and run
```bash
g++ set_operations.cpp -o set_operations
./set_operations
```
