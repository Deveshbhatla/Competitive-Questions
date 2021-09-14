#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
}

void DFSUtility(vector<int> adjacent[], int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    //list<int>::iterator i;

    //for (i = adjacent[v].begin(); i != adjacent[v].end(); ++i)
    for (int i : adjacent[v])
        if (!visited[i]) //if(!visited[*i])
            DFSUtility(adjacent, i, visited);
}

void DFS(vector<int> graph[], int sourceVertex)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[sourceVertex];

    for (int i = 0; i < sourceVertex; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtility(graph, sourceVertex, visited);
}

int main()
{
    // Create a graph given in the above diagram
    vector<int> *graph = new vector<int>[4];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    /*
0---1
|  /
| /
|/
2---3
^
start
*/
    cout << "Following is Depth First Traversal starting from vertex 2 \n";
    DFS(graph, 2);

    return 0;
}