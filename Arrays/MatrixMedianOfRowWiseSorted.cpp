#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int matMed(int matrix[][MAX], int r, int c)
{
    int min = matrix[0][0], max = matrix[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        if (matrix[i][0] < min)
            min = matrix[i][0];

        if (matrix[i][c - 1] > max)
            max = matrix[i][c - 1];
    }

    int medPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;

        for (int i = 0; i < r; ++i)
            midPos += upper_bound(matrix[i], matrix[i] + c, mid) - matrix[i]; //index of first greater element
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    int r = 3, c = 5;
    int matrix[][MAX] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    cout << "Median is: " << matMed(matrix, r, c) << endl;
    return 0;
}
