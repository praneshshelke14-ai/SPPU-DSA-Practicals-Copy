# Practical 1 – Searching Algorithms

## Aim
Store student roll numbers and search for a particular roll number using Linear Search and Binary Search.

## Objectives
- Understand array traversal and searching.
- Implement Linear Search for unsorted data.
- Implement Binary Search for sorted data.
- Compare their time complexities.

## Problem statement
(a) Store roll numbers in random order and determine whether a student attended the training program using Linear Search. (b) Store roll numbers in sorted order and perform the same task using Binary Search.

## Requirements
- Language: C++ for Linear Search; C for Binary Search.
- Compiler: `g++` and `gcc` (or an equivalent IDE/compiler).
- Concepts: arrays, loops, functions, conditions.

## Theory
An array stores elements of the same data type in indexed, contiguous memory locations. Searching is the process of locating a required value.

**Linear Search** checks each element from the beginning until the key is found or the array ends. It works even when values are not sorted.

**Binary Search** compares the key with the middle element of a sorted array. It discards the half that cannot contain the key and repeats the process. The input must be sorted.

## Algorithms
### Linear Search
1. Read `n`, the roll numbers and the key.
2. Set `i = 0`.
3. Compare `arr[i]` with the key.
4. If equal, return the position.
5. Otherwise increment `i` and repeat until `i == n`.
6. If no match is found, return `-1`.

### Binary Search
1. Read `n`, sorted roll numbers and the key.
2. Set `low = 0` and `high = n - 1`.
3. While `low <= high`, calculate `mid = low + (high - low) / 2`.
4. If `arr[mid] == key`, return the position.
5. If key is greater, set `low = mid + 1`; otherwise set `high = mid - 1`.
6. If the range becomes empty, report not found.

## Sample test
Linear Search input: `5` and roll numbers `23 11 45 18 32`, key `18`.
Expected result: student attended; position 4 in the array.

Binary Search input: `5` and sorted roll numbers `11 18 23 32 45`, key `18`.
Expected result: student attended; position 2 in the array.

## Complexity
| Algorithm | Best | Average | Worst | Requirement |
|---|---:|---:|---:|---|
| Linear Search | O(1) | O(n) | O(n) | Sorted or unsorted data |
| Binary Search | O(1) | O(log n) | O(log n) | Sorted data |

## Important viva questions
1. **What is searching?** Finding the location of a required element in a collection.
2. **Does Linear Search require sorted data?** No.
3. **Does Binary Search require sorted data?** Yes.
4. **Why is Binary Search faster for large sorted arrays?** It halves the remaining search range at each comparison.
5. **What does `-1` indicate in these functions?** The key was not found.
6. **What is the time complexity of Linear Search?** O(n) in the average and worst cases.
7. **What is the time complexity of Binary Search?** O(log n) in the average and worst cases.
8. **What is `mid`?** The middle index of the current search range.

## Conclusion
Linear Search and Binary Search were implemented. Linear Search is suitable for unsorted data, while Binary Search is more efficient for sorted data.

## Compile and run
```bash
g++ linear_search.cpp -o linear_search
./linear_search

gcc binary_search.c -o binary_search
./binary_search
```
On Windows, run the generated `.exe` files instead of `./...`.
