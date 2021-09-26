#include <bits/stdc++.h>
using namespace std;

int minCoins(int coin[], int n, int amount)
{
    sort(coin, coin + n, greater<int>()); // to sort in decreasing order
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (coin[i] <= amount)
        {
            int c = floor(amount / coin[i]); //return largest integer smaller than or equal to amount/coin[i] 57/10=5.7 floor=5
            result = result + c;
            amount = amount - (c * coin[i]); //subtracting 50 from 57
        }
        if (amount == 0)
            break;
    }
    return result;
}
int main()
{
    int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;
    cout << minCoins(coin, n, amount);
}