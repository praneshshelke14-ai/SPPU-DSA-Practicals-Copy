# Practical 2 – Sorting Algorithms

## Aim
Store first-year student percentages in an array, sort floating-point values in ascending order and display the top five scores.

## Objectives
- Understand sorting of floating-point values.
- Implement Bubble Sort and Selection Sort as required by the practical statement.
- Review Insertion Sort and Shell Sort, which are also present in the uploaded program.
- Display the highest five values.

## Problem statement
Store student percentages and sort them in ascending order using sorting functions. The uploaded code contains Bubble, Selection, Insertion and Shell Sort; the prepared source retains all four and adds top-five display.

## Requirements
C++ compiler (`g++`), arrays/vectors, loops, functions and swapping.

## Theory
Sorting arranges data in a chosen order. Here, percentages are arranged in ascending order.

- **Bubble Sort:** compares adjacent values and swaps them when they are in the wrong order. Large values move toward the end on each pass.
- **Selection Sort:** selects the smallest remaining element and places it at the current position.
- **Insertion Sort:** inserts each next element into its correct position in the already-sorted left portion.
- **Shell Sort:** performs insertion-sort-like passes over elements separated by a decreasing gap.

## Algorithm (general)
1. Read the number of students and their percentages.
2. Select a sorting method from the menu.
3. Apply the selected sorting algorithm to arrange percentages in ascending order.
4. Display the sorted list.
5. Traverse the list from the last element backward and display up to five highest scores.

## Sample test
Input: `6` percentages: `78.5 65 91 82.5 74 88` and choice `1`.
Expected sorted list: `65.00 74.00 78.50 82.50 88.00 91.00`.
Top five: `91.00, 88.00, 82.50, 78.50, 74.00`.

## Complexity
| Algorithm | Best | Average | Worst | Extra space |
|---|---:|---:|---:|---:|
| Bubble Sort (with early stop) | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Shell Sort | Depends on gap sequence | Depends | Commonly O(n²) for this simple sequence | O(1) |

## Corrections made to the uploaded version
- The original Bubble Sort temporary variable was `int`, which could truncate decimal percentages; it is now `float`.
- The Insertion Sort boundary check now tests `j >= 0` before accessing `a[j]`.
- A proper invalid-choice path and top-five display were added.
- The uploaded menu repeated sorting on an already-mutated array; this program runs one selected method on the entered input.

## Important viva questions
1. **What is sorting?** Arranging data in ascending or descending order.
2. **What is Bubble Sort?** Repeatedly compares and swaps adjacent out-of-order elements.
3. **What is Selection Sort?** Repeatedly selects the minimum element from the unsorted part.
4. **Which sort is stable in its usual implementation?** Bubble Sort and Insertion Sort are stable; standard Selection Sort is not stable.
5. **Why use `float` for percentages?** Percentages may contain decimal values.
6. **What is the worst-case complexity of Bubble Sort?** O(n²).
7. **What does the gap mean in Shell Sort?** The distance between elements compared in a pass.
8. **How are top five scores displayed?** After ascending sort, read values from the end in reverse order.

## Conclusion
The sorting methods were implemented for floating-point percentages, and the highest five scores are displayed after sorting.

## Compile and run
```bash
g++ sorting.cpp -o sorting
./sorting
```
