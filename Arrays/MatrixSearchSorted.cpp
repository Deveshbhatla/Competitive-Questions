#include <bits/stdc++.h>
using namespace std;

const int R = 4, C = 4;
void searchNaive(int matrix[R][C], int x) //O(n2)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == x)
            {
                cout << "Found at (" << i << ", " << j << ")";

                return;
            }
        }
    }

    cout << "Not Found";
}
/*
1) Begin from top right position
2)if x is equal to that position, print that position
3)if x is smaller that that move left
4) if x is greater that that element move down
*/
void searchEfficient(int matrix[R][C], int x) //(R+C)
{
    int i = 0, j = C - 1;

    while (i < R && j >= 0)
    {
        if (matrix[i][j] == x)
        {
            cout << "Found at (" << i << ", " << j << ")";
            return;
        }
        else if (x < matrix[i][j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "Not Found";
}

int main()
{
    int arr[][C] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 35, 45},
                    {32, 33, 39, 50}};

    int x = 29;
    searchNaive(arr, x);
    cout << "\nusing efficient ";
    searchEfficient(arr, x);
    return 0;
}