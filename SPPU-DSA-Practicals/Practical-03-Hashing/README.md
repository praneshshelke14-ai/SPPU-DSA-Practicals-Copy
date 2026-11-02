# Practical 3 – Telephone Directory Using Hashing

## Aim
Create a telephone book database and perform fast record lookup using a hash table with Linear Probing, Quadratic Probing and Double Hashing.

## Objectives
- Understand hash functions and hash tables.
- Understand collisions and collision-resolution techniques.
- Implement create, display, search, update and delete operations.

## Problem statement
Consider a telephone book database of N clients. Store client names and telephone numbers in a hash table and handle collisions using the three methods named in the practical statement.

## Requirements
C++ compiler (`g++`), classes/structures, arrays, strings, functions and hashing.

## Theory
A **hash function** converts a key into an index in a hash table. A **collision** occurs when two different keys map to the same index.

- **Linear Probing:** on collision, check the next slot: `(h(k) + i) % m`.
- **Quadratic Probing:** use a quadratic offset: `(h(k) + i²) % m`.
- **Double Hashing:** use a second hash function to calculate the step size: `(h1(k) + i × h2(k)) % m`.

This program uses the sum of character codes in a name as a simple primary hash key and a table size of 101. The selected collision method is used for the whole run.

## Algorithm
1. Choose Linear Probing, Quadratic Probing or Double Hashing.
2. Initialize all table slots as empty.
3. For insertion, calculate the initial hash index.
4. If occupied by another name, generate the next index using the selected probing method.
5. Store the name and telephone number in an available slot.
6. For search/update/delete, follow the same probe sequence.
7. Display all occupied records when requested.

## Sample test
Select method `1` (Linear Probing). Create `Amit` with telephone `9876543210`, display records, then search for `Amit`.
Expected result: the directory displays Amit and the telephone number; search reports record found.

## Complexity
- Average expected insertion/search/deletion: O(1) when the load factor is low and hashing distributes keys well.
- Worst case: O(n) due to clustering or collisions.
- Display: O(m), where m is the table size.

## Corrections and implementation notes
The uploaded Practical 3 code implemented Linear Probing only, even though the problem statement asks for all three collision-handling techniques. The prepared program adds a method-selection menu and uses the same selected probe sequence for insertion and lookup. It also fixes the uploaded deletion-index mismatch and uses a deleted-slot marker (tombstone), so deleting a record does not prematurely break a later search in the probe chain.

The name-based character-sum hash is intentionally simple for the lab exercise; different names may produce the same hash value, so the probing method remains necessary.

## Important viva questions
1. **What is hashing?** Mapping a key to a table index using a hash function.
2. **What is a collision?** Two keys generating the same hash index.
3. **What is Linear Probing?** Checking the following slots one by one.
4. **What is Quadratic Probing?** Checking positions using quadratic offsets such as i².
5. **What is Double Hashing?** Using a second hash function to determine the probe step.
6. **What is a load factor?** Number of occupied entries divided by table size.
7. **Why is the table size prime here?** A prime size can help probing distribute across the table, especially for double hashing.
8. **Why use a tombstone after deletion?** To preserve the probe chain so records placed later can still be found.

## Conclusion
A telephone directory was implemented using a hash table. Linear Probing, Quadratic Probing and Double Hashing can be selected to resolve collisions, and records can be created, searched, updated and deleted.

## Compile and run
```bash
g++ telephone_directory.cpp -o telephone_directory
./telephone_directory
```
