#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void BFS(vector<int> graph[], int V)
{
    //Initialize a boolean array to keep track of visited vertices 0-6
    bool visited[V + 1];

    // Mark all vertices not-visited initially
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a Queue to perform BFS
    queue<int> q;

    // Our source vertex is vertex number 1
    int source = 1;

    // Mark Source as visited and Push to queue
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        // Pop element from the front of the queue and print it
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse the nodes adjacent to the currently poped element and push those elements to the
        // queue which are not already visited
        for (int i = 0; i < graph[node].size(); i++)//or for(int i :graph[node])
        {
            if (visited[graph[node][i]] == false)
            {
                // Mark it visited
                visited[graph[node][i]] = true;
                // Push it to the Queue
                q.push(graph[node][i]);
            }
        }
    }
}

// Driver code
int main()
{
    int vertices  = 6;
    vector<int> adj[vertices  + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    BFS(adj, vertices);

    return 0;
}