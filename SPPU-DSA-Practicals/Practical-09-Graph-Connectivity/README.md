# Practical 09 – Graph Connectivity using DFS and BFS

## Aim
Represent flight paths between cities as a graph using an adjacency matrix and check whether the graph is connected.

## Problem statement (from the uploaded practical)
There are flight paths between cities. If there is a flight between city A and city B, there is an edge between the cities. The edge cost may represent flight time or fuel used. Represent the cities as vertices and flight paths as edges. Use an adjacency list or adjacency matrix and check whether the graph is connected.

## Objectives
- Represent cities as vertices and direct flights as edges.
- Store the graph using an adjacency matrix.
- Traverse the graph using Depth First Search (DFS).
- Traverse the graph using Breadth First Search (BFS).
- Decide whether every vertex is reachable from the selected starting vertex.

## Requirements
- Language: C++
- Compiler: G++ (C++11 or later)
- Header files: `<iostream>`, `<vector>`, `<queue>`, and `<string>`

## Theory
A **graph** is a non-linear data structure made of vertices (nodes) and edges (connections). In this practical, a city/airport is a vertex and a direct flight is an edge. The edge value can store a cost, time, or fuel value.

An **adjacency matrix** is a two-dimensional array `adj[i][j]`. A non-zero value means an edge exists between vertices `i` and `j`; zero means there is no direct edge. The uploaded practical stores each entered value in both `adj[i][j]` and `adj[j][i]`, so this implementation treats routes as an **undirected graph**.

**DFS** explores one path deeply before backtracking. It is commonly implemented with recursion or a stack.

**BFS** visits vertices level by level. It uses a queue.

An undirected graph is **connected** when every vertex can be reached from every other vertex. It is enough to start one traversal from any vertex and check whether all vertices were visited.

## Algorithm
1. Read the number of cities and validate it.
2. Read the name/code of each city.
3. Create an `n × n` adjacency matrix and initialise every entry to zero.
4. For each pair of different cities, read the route value. Enter zero when no direct flight exists.
5. Store the value symmetrically in both matrix positions.
6. Display the adjacency matrix.
7. Read a valid starting vertex index.
8. Apply DFS from the starting vertex and display the traversal.
9. Apply BFS from the same starting vertex and display the traversal.
10. Run a traversal with a fresh visited array. If all vertices are visited, report that the graph is connected; otherwise report that it is not connected.

## Flow of the program
`Input cities → Build adjacency matrix → Display matrix → Read start vertex → DFS → BFS → Check all vertices visited → Print connectivity result`

## Sample test 1 – Connected graph
Input (city pairs are prompted in this order):

```text
4
PNQ
BOM
DEL
MAA
150
0
0
1150
0
1750
0
```

The first number is the number of cities. The next four values are city codes. The six route values correspond to PNQ-BOM, PNQ-DEL, PNQ-MAA, BOM-DEL, BOM-MAA, and DEL-MAA. Enter starting vertex `0` when prompted.

Expected traversals for this chain-shaped graph:

```text
DFS traversal: PNQ BOM DEL MAA
BFS traversal: PNQ BOM DEL MAA
Connectivity: The graph is connected.
```

## Sample test 2 – Disconnected graph
Use four cities and give all three route values involving `MAA` as zero, while keeping `PNQ-BOM` and `BOM-DEL` non-zero. Start at vertex `0`.

Expected result:

```text
Connectivity: The graph is not connected.
```

## Complexity
Let `V` be the number of vertices (cities).

- Adjacency matrix storage: `O(V²)` space.
- Building and displaying the matrix: `O(V²)` time.
- DFS with an adjacency matrix: `O(V²)` time.
- BFS with an adjacency matrix: `O(V²)` time.
- Connectivity check with an adjacency matrix: `O(V²)` time.
- Traversal auxiliary space: `O(V)` for the visited array and queue/recursion stack (excluding the matrix).

## Important code explanation
- `adj[i][j]`: route value from city `i` to city `j`.
- `adj[i][j] != 0`: a direct edge exists.
- `visited[i]`: prevents visiting the same city more than once.
- `dfs(...)`: recursively visits an unvisited adjacent city.
- `queue<int> q`: stores the next vertices to visit in BFS order.
- `q.front()`: reads the oldest queued vertex.
- `q.pop()`: removes the oldest queued vertex.
- `isConnected(...)`: uses a fresh visited array and checks whether every city was reached.

## Viva questions and answers

1. **What is a graph?**  A graph is a non-linear data structure consisting of vertices and edges.
2. **What do vertices and edges represent here?**  Vertices represent cities/airports; edges represent direct flights.
3. **What is an adjacency matrix?**  A two-dimensional matrix in which an entry indicates whether an edge exists (and may store its weight).
4. **What does zero mean in this program?**  There is no direct flight between that pair of cities.
5. **What is DFS?**  Depth First Search explores an unvisited neighbour deeply before backtracking.
6. **Which data structure is used by BFS?**  A queue.
7. **Which data structure/technique is used by this DFS?**  Recursion, which uses the call stack.
8. **When is an undirected graph connected?**  When every vertex is reachable from every other vertex.
9. **Why is the visited array required?**  To avoid repeatedly visiting vertices and to prevent infinite traversal in cyclic graphs.
10. **What is the time complexity of BFS using an adjacency matrix?**  `O(V²)`, because each visited vertex scans a row of the matrix.
11. **What is the space complexity of the adjacency matrix?**  `O(V²)`.
12. **Does the uploaded program treat routes as directed?**  No. It copies each entered value into both `adj[i][j]` and `adj[j][i]`, so it models an undirected graph.

## Notes about the uploaded source
The supplied document (pages 1–3) uses a fixed 50 × 50 global matrix, global DFS visited values, a variable-length local array in BFS, and prints DFS/BFS traversals. It does not explicitly print a connected/not-connected result. The included `graph_connectivity.cpp` keeps the same adjacency-matrix, DFS, BFS, and undirected-route approach, uses standard C++ vectors for portability, validates the input range/start vertex, and adds the explicit connectivity check required by the problem statement.

## Compile and run

Windows PowerShell / VS Code terminal:

```powershell
g++ -std=c++17 graph_connectivity.cpp -o graph_connectivity.exe
.\graph_connectivity.exe
```

Linux / macOS:

```bash
g++ -std=c++17 graph_connectivity.cpp -o graph_connectivity
./graph_connectivity
```

## Conclusion
The flight network was represented using an adjacency matrix. DFS and BFS were performed from the selected starting city, and the graph's connectivity was determined by checking whether all vertices were visited.
