#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> *adjacent, int u, int v)
{
    adjacent[u].push_back(v); //add v to u's list
}

bool isCyclicUtility(vector<int> adjacent[], int v, bool visited[], bool *recursionStack)
{
     if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recursionStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for(i = adjacent[v].begin(); i != adjacent[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtility(adjacent,*i, visited, recursionStack) )
                return true;
            else if (recursionStack[*i])
                return true;
        }
    }
    recursionStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
bool isCyclic(vector<int> adjacent[],int Vertices)
{
    bool *visited = new bool[Vertices];
    bool *recStack = new bool[Vertices];
    for (int i = 0; i < Vertices; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < Vertices; i++)
        if (isCyclicUtility(adjacent,i, visited, recStack))
            return true;

    return false;
}

int main()
{
    // Create a graph given in the above diagram
    vector<int> *graph = new vector<int>[4];
    addEdge(graph,0, 1);
    addEdge(graph,0, 2);
    addEdge(graph,1, 2);
    addEdge(graph,2, 0);
    addEdge(graph,2, 3);
    addEdge(graph,3, 3);

    if(isCyclic(graph,4))
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
