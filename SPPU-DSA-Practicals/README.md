# SPPU SE AI & DS – Data Structures Practicals

This repository contains nine practical folders prepared from the practical files shared in the conversation. It is organised for study, compilation and access through GitHub.

## Practical index

| No. | Folder | Main topic | Source file |
|---|---|---|---|
| 1 | Practical-01-Searching | Linear and Binary Search | `linear_search.cpp`, `binary_search.c` |
| 2 | Practical-02-Sorting | Bubble, Selection, Insertion and Shell Sort | `sorting.cpp` |
| 3 | Practical-03-Hashing | Telephone directory and collision handling | `telephone_directory.cpp` |
| 4 | Practical-04-Set-Operations | Vanilla/Butterscotch set operations using linked lists | `set_operations.cpp` |
| 5 | Practical-05-Doubly-Linked-List | Cinemax seat booking | `cinemax_booking.cpp` |
| 6 | Practical-06-Stack | Balanced parentheses | `parenthesis_checker.cpp` |
| 7 | Practical-07-Queue | Pizza parlour circular queue | `pizza_parlour.cpp` |
| 8 | Practical-08-BST | Binary Search Tree operations | `binary_search_tree.c` |
| 9 | Practical-09-Graph-Connectivity | Flight network graph, DFS, BFS and connectivity | `graph_connectivity.cpp` |

Each practical folder contains a README with aim, objectives, problem statement, requirements, theory, algorithm, sample test, complexity, viva questions, conclusion and compile commands.

## Compile on Windows

Install a C/C++ compiler such as MinGW-w64 (GCC/G++) and make sure `gcc` and `g++` are available in the terminal PATH. Open PowerShell or the VS Code terminal inside the required practical folder.

Examples:

```powershell
g++ .\linear_search.cpp -o .\linear_search.exe
.\linear_search.exe

gcc .\binary_search.c -o .\binary_search.exe
.\binary_search.exe
```

For other practicals, use the file name shown in the table and compile C++ files with `g++` and C files with `gcc`.

## Important note about the prepared code

The source documents were reviewed. Some uploaded programs contained incomplete requirements or coding issues. The source files in this archive are cleaned-up study versions that preserve the practical's purpose and add checks needed for reliable execution. The practical-specific README files explicitly list the important changes. Keep your original reference documents in `Reference-Documents` for comparison.

Examples of changes include: decimal-safe sorting and top-five display in Practical 2; all three probing strategies and safe deletion in Practical 3; bracket-type validation in Practical 6; using all five circular-queue slots in Practical 7; and handling BST search after mirroring in Practical 8.

## Practical 9 notes

The Group E graph practical has now been added using the uploaded flight-path assignment. It uses an adjacency matrix, DFS and BFS. The uploaded source treats routes as undirected by mirroring each matrix value. The prepared version also prints an explicit connected/not-connected result. See the Practical 9 README for its assumptions and sample tests.

## Reference documents

Original DOCX/PDF files that were available in the upload directory are copied into `Reference-Documents`. The Practical 3 DOCX was reviewed from extracted attachment text but its binary was not available in the working directory; a note is included in the reference folder.

## Not included

The Group E graph connectivity practical is included. The alternative minimum-cost spanning tree assignment and the Group F mini-project were not supplied, so they are not included.
