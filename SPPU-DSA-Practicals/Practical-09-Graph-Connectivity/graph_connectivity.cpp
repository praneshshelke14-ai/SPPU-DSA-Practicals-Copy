#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Practical 9: Check graph connectivity using an adjacency matrix,
// Depth First Search (DFS), and Breadth First Search (BFS).

void dfs(int vertex,
         const vector<vector<int>>& adj,
         const vector<string>& cities,
         vector<bool>& visited)
{
    visited[vertex] = true;
    cout << cities[vertex] << " ";

    for (int i = 0; i < static_cast<int>(cities.size()); i++)
    {
        // A non-zero entry represents a direct flight/edge.
        if (adj[vertex][i] != 0 && !visited[i])
            dfs(i, adj, cities, visited);
    }
}

void bfs(int start,
         const vector<vector<int>>& adj,
         const vector<string>& cities)
{
    vector<bool> visited(cities.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << cities[vertex] << " ";

        for (int i = 0; i < static_cast<int>(cities.size()); i++)
        {
            if (adj[vertex][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

bool isConnected(int start, const vector<vector<int>>& adj)
{
    int n = static_cast<int>(adj.size());
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (bool reached : visited)
    {
        if (!reached)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter number of cities (1-50): ";
    cin >> n;

    if (n < 1 || n > 50)
    {
        cout << "Invalid number of cities. Enter a value from 1 to 50.\n";
        return 1;
    }

    vector<string> cities(n);
    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (airport code/name, no spaces): ";
        cin >> cities[i];
    }

    cout << "\nEnter the cost/time/fuel value between each pair of cities.\n";
    cout << "Enter 0 if there is no direct flight.\n";

    // This follows the uploaded practical: routes are treated as undirected,
    // so the entered value is stored in both directions.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Value between " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj[i][j];

            if (adj[i][j] < 0)
            {
                cout << "Negative values are not accepted.\n";
                return 1;
            }
            adj[j][i] = adj[i][j];
        }
    }

    cout << "\nAdjacency Matrix (0 means no direct flight):\n\t";
    for (const string& city : cities)
        cout << city << "\t";
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << cities[i] << "\t";
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << "\t";
        cout << "\n";
    }

    int start;
    cout << "\nEnter starting vertex index (0 to " << n - 1 << "): ";
    cin >> start;

    if (start < 0 || start >= n)
    {
        cout << "Invalid starting vertex.\n";
        return 1;
    }

    vector<bool> visited(n, false);
    cout << "\nDFS traversal: ";
    dfs(start, adj, cities, visited);

    cout << "\nBFS traversal: ";
    bfs(start, adj, cities);

    cout << "\n\nConnectivity: ";
    if (isConnected(start, adj))
        cout << "The graph is connected.\n";
    else
        cout << "The graph is not connected.\n";

    return 0;
}
