#include <bits/stdc++.h>
using namespace std;
const int row = 4, col = 4;
void PrintSnakePatterm(int a[row][col])
{
    for (int i = 0; i < row; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < col; j++)
                cout << a[i][j] << " ";
        }
        else
        {
            for (int j = col - 1; j >= 0; j--)
                cout << a[i][j] << " ";
        }
    }
}
int main()
{
    int arr[row][col] = {{1, 2, 3, 4},
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};

    PrintSnakePatterm(arr);
}