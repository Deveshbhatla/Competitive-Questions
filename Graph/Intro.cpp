/*Grraphs using Adjacency matrix and list
A Graph is a data structure that consists of the following two components:
1) A finite set of vertices also called nodes.
2) A finite set of ordered pair of the form (u, v) called as edge. 
    The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(digraph).
    The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. 
    The edges may contain weight/value/cost.
*/

#include <bits/stdc++.h>
using namespace std;
void usingAdjacencyMatrix(int vertices, int edges)
{

    //dynamically declare a graph
    int **graph, v1, v2;
    graph = new int *[vertices];
    //initializing the values of the Adjacency matrix to 0
    for (int i = 0; i < vertices; i++)
    {
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }

    //changing the value of vertex pair to 1
    for (int i = 0; i < edges; i++)
    {
        cout << "\nEnter the vertex pair for edge " << i + 1;
        cout << "\nV(1): ";
        cin >> v1;
        cout << "V(2): ";
        cin >> v2;

        graph[v1 - 1][v2 - 1] = 1;
        graph[v2 - 1][v1 - 1] = 1;
    }

    //Printing the graph
    for (int i = 0; i < vertices; i++)
    {
        cout << setw(3) << "(" << i + 1 << ")";
        for (int j = 0; j < vertices; j++)
        {
            cout << setw(4) << graph[i][j];
        }
        cout << "\n\n";
    }
}

//Using adjacency List
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        cout<<'\n';
    }
}
int main()
{
    int edges, vertices, V1, V2;
    //usingAdjacencyMatrix(5, 5);

     int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
}