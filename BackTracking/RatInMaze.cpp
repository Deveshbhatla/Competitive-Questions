#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
bool solveMazeRecursive(int maze[N][N], int x, int y, int solution[N][N]); 
  
void printSolution(int solution[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            cout<<solution[i][j]; 
        cout<<'\n';
    } 
} 
  
bool isSafe(int maze[N][N], int i, int j) 
{  
    return ( i < N && j < N && maze[i][j] == 1);
} 
 
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } 
                    }; 
  
    if (solveMazeRecursive(maze, 0, 0, sol) == false) 
    { 
        cout<<"Solution doesn't exist"; 
        return false; 
    } 
    printSolution(sol); 
    return true; 
} 

bool solveMazeRecursive( int maze[N][N], int i, int j, int solution[N][N]) 
{ 
    if ( i == N - 1 && j == N - 1 && maze[i][j] == 1) 
    { 
        solution[i][j] = 1; 
        return true; 
    } 
  
    if (isSafe(maze, i, j) == true) 
    { 
        solution[i][j] = 1; 
  
        if (solveMazeRecursive(maze, i + 1, j, solution) == true) 
            return true; 
  
        if (solveMazeRecursive(maze, i, j + 1, solution) == true) 
            return true; 
  
        solution[i][j] = 0; 
    } 

    return false; 
}

int main() 
{	
	int maze[N][N] = 
    { 
    { 1, 0, 0, 0 }, 
    { 1, 1, 0, 1 }, 
    { 0, 1, 0, 0 }, 
    { 1, 1, 1, 1 } 
    }; 
  
    solveMaze(maze);    
    return 0;  
	
}