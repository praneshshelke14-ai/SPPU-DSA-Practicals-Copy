# Practical 7 – Pizza Parlour Using Circular Queue

## Aim
Simulate a pizza parlour that accepts a maximum of M orders and serves them in first-come, first-served order using a queue.

## Objectives
- Understand the FIFO principle.
- Implement enqueue and dequeue operations.
- Use a circular array to reuse freed positions.
- Detect queue-full and queue-empty conditions.

## Problem statement
A pizza parlour accepts a limited number of orders. Orders are served on a first-come, first-served basis. Implement functions to add and remove orders.

## Requirements
C++ compiler (`g++`), arrays, classes, loops and modular arithmetic.

## Theory
A **queue** is a linear data structure that follows FIFO (First In, First Out). The first element inserted is the first one removed. Insertion is called enqueue and deletion is called dequeue.

A **circular queue** connects the final array position back to position zero. This allows unused positions created by dequeue operations to be reused. This program uses a `count` variable, so all five array positions can be occupied.

## Algorithm
### Add order (enqueue)
1. If `count == MAX_ORDERS`, report queue full.
2. Update `rear = (rear + 1) % MAX_ORDERS`.
3. Store the order ID at rear.
4. Increment count.

### Serve order (dequeue)
1. If count is zero, report queue empty.
2. Display the order at front.
3. Update `front = (front + 1) % MAX_ORDERS`.
4. Decrement count.
5. If count becomes zero, reset front and rear.

## Sample test
Choose Accept Order three times, then Display. Expected pending IDs: `1 2 3`. Choose Serve Order once; expected served ID: `1`. Display again; expected pending IDs: `2 3`.

## Complexity
- Enqueue: O(1).
- Dequeue: O(1).
- Display: O(n), where n is the current number of orders.
- Space: O(M), where M is maximum queue capacity.

## Corrections and implementation notes
The uploaded program used a circular queue but reserved one position to distinguish full from empty. With `MAX = 5`, that implementation could hold only four orders. This prepared program tracks the number of stored orders, so all five slots can be used. It also removes `<windows.h>` and `Sleep()`, making the code portable across common C++ compilers.

## Important viva questions
1. **What is a queue?** A linear data structure that follows FIFO.
2. **What is FIFO?** First In, First Out.
3. **What is enqueue?** Inserting an element at the rear.
4. **What is dequeue?** Removing an element from the front.
5. **Why use a circular queue?** To reuse positions freed by deletions.
6. **What is queue overflow?** Trying to insert into a full queue.
7. **What is queue underflow?** Trying to delete from an empty queue.
8. **What is the time complexity of enqueue and dequeue?** O(1).

## Conclusion
A circular queue was implemented to accept, serve and display pizza orders in FIFO order, with full and empty conditions handled.

## Compile and run
```bash
g++ pizza_parlour.cpp -o pizza_parlour
./pizza_parlour
```
