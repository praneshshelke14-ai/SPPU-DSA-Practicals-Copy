# Practical 6 – Balanced Parentheses Using Stack

## Aim
Check whether an expression is well-parenthesized using a stack.

## Objectives
- Understand the stack data structure.
- Implement push and pop logic.
- Verify matching `()`, `[]` and `{}` delimiters.

## Problem statement
Syntax errors can occur when delimiters such as parentheses, square brackets and braces are unbalanced. Use a stack to check whether an expression is well-parenthesized.

## Requirements
C++ compiler (`g++`), strings, arrays and stack operations.

## Theory
A **stack** is a linear data structure that follows LIFO (Last In, First Out). The last item pushed is the first item popped. Common operations are `push`, `pop` and `peek/top`.

For balanced delimiters, every closing delimiter must match the most recent unmatched opening delimiter. Therefore, a stack is suitable for remembering opening symbols.

## Algorithm
1. Initialize an empty stack.
2. Scan the expression from left to right.
3. When `(`, `[` or `{` is found, push it onto the stack.
4. When a closing delimiter is found, check that the stack is not empty.
5. Check that the top opening delimiter matches the closing delimiter.
6. If it does not match, report invalid expression.
7. Otherwise pop the opening delimiter.
8. At the end, the expression is balanced only if the stack is empty.

## Sample tests
| Expression | Expected result |
|---|---|
| `{a+[b*(c+d)]}` | Well parenthesized |
| `([)]` | Not well parenthesized |
| `((a+b)` | Not well parenthesized |
| `a+b)` | Not well parenthesized |
| `a+(b*c)` | Well parenthesized |

## Complexity
- Time: O(n), because each character is processed once.
- Space: O(n) in the worst case, when all characters are opening delimiters.

## Corrections to the uploaded version
The uploaded program pushed opening delimiters and popped for every closing delimiter, but it did not verify that the delimiter types matched. It could also pop an empty stack and its stack-full check used the wrong boundary. The prepared program checks underflow, overflow and matching delimiter types.

## Important viva questions
1. **What is a stack?** A linear data structure that follows LIFO.
2. **What is LIFO?** Last In, First Out.
3. **What is push?** Inserting an element at the top of a stack.
4. **What is pop?** Removing the top element.
5. **What is stack underflow?** Attempting to pop from an empty stack.
6. **What is stack overflow?** Attempting to push when a fixed-size stack is full.
7. **Why use a stack for parentheses?** The most recent opening delimiter must be matched first.
8. **What is the complexity?** O(n) time and O(n) worst-case auxiliary space.

## Conclusion
A stack-based delimiter checker was implemented. It identifies unmatched delimiters, unmatched closing symbols and mismatched bracket types.

## Compile and run
```bash
g++ parenthesis_checker.cpp -o parenthesis_checker
./parenthesis_checker
```
