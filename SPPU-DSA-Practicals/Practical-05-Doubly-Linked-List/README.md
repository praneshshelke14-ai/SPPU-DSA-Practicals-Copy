# Practical 5 – Doubly Linked List for Cinemax Seat Booking

## Aim
Implement a Cinemax ticket-booking system for 10 rows with 7 seats per row using doubly linked lists. Display available seats, book seats and cancel bookings.

## Objectives
- Understand doubly linked-list nodes and links.
- Maintain previous and next pointers.
- Use an array of head pointers, one for each row.
- Implement seat booking and cancellation with customer-ID validation.

## Problem statement
Maintain the free-seat information for 10 rows, each containing 7 seats. Display current/available seats, book a seat and cancel a booking.

## Requirements
C++ compiler (`g++`), classes, structures, pointers, strings and linked lists.

## Theory
A **doubly linked list** contains nodes with data and two links: `prev` points to the previous node and `next` points to the next node. It allows traversal in both directions. The program uses an array of 10 head pointers; each head points to the first seat node in that row.

Each seat node stores its seat number, booking status and customer ID. The prepared program uses a normal (non-circular) doubly linked list per row, matching the manual's array-of-row-heads design.

## Algorithm
1. Create an array of 10 head pointers.
2. For each row, create 7 seat nodes and link each node's `prev` and `next` pointers.
3. Mark the example pre-bookings as occupied.
4. To display, traverse every row list and print each seat's status.
5. To book, validate row and seat, check the seat is free, then store the customer ID and mark it booked.
6. To cancel, validate row and seat, check that it is booked and verify the customer ID.
7. Mark the seat available after successful cancellation.

## Sample test
- Choose display status: row 1 seat 3 and row 4 seat 6 are shown as booked initially.
- Choose book seat; enter row `2`, seat `4`, customer ID `STU101`.
- Choose cancel; enter row `2`, seat `4`, ID `STU101`.
Expected result: booking succeeds, then cancellation succeeds.

## Complexity
- Finding a seat within a row: O(7), effectively constant for this fixed-size example.
- Displaying all seats: O(ROWS × SEATS_PER_ROW), which is O(70) here.
- Booking/cancelling: O(SEATS_PER_ROW) to locate the node, then O(1) to update it.
- Storage: O(ROWS × SEATS_PER_ROW).

## Corrections and implementation notes
The uploaded version used one circular doubly linked list containing all 70 seats, while the written practical asks for an array of head pointers, one per row. This prepared version uses the row-wise array-of-heads structure and completes the available-seat display. It validates both row and seat bounds and releases allocated nodes when the object is destroyed.

## Important viva questions
1. **What is a doubly linked list?** A linked list in which each node has previous and next pointers.
2. **What is the use of `prev`?** It points to the preceding node.
3. **Why use an array of head pointers?** To maintain a separate list for each theatre row.
4. **What is a head pointer?** A pointer to the first node of a list.
5. **How is a seat booked?** Check it is free, then set its booking status and store the customer ID.
6. **Why verify the customer ID during cancellation?** To prevent cancellation by someone with a different ID.
7. **What is the difference between singly and doubly linked lists?** A singly list has only `next`; a doubly list has `prev` and `next`.
8. **What is the advantage of a doubly linked list?** Traversal can proceed in both directions.

## Conclusion
A theatre seat-booking system was implemented with a separate doubly linked list for each row. The program supports status display, booking, availability listing and cancellation.

## Compile and run
```bash
g++ cinemax_booking.cpp -o cinemax_booking
./cinemax_booking
```
