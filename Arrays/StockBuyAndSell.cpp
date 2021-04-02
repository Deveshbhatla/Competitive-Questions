#include <iostream>
#include <cmath>
using namespace std;

int maxProfitNaive(int price[], int start, int end)
{
	if(end <= start)
		return 0;

	int profit = 0;

	for(int i = start; i < end; i++)
	{
		for(int j = i + 1; j <= end; j++)
		{
			if(price[j] > price[i])
			{
                //Call the fuction recursively for the prices before i and after j and add to the current profit
				int currentProfit = price[j] - price[i]+ maxProfitNaive(price, start, i - 1) + maxProfitNaive(price, j + 1, end);

				profit = max(profit, currentProfit);
			}
		}
	}
	return profit;
}

int maxProfitEfficient(int price[],int n)//O(n)
{
    int profit = 0;
	for(int i = 1; i < n; i++)
	{
		if(price[i] > price[i - 1])
			profit += price[i] - price[i -1];
	}
	return profit;
}
int main()
{
    int arr[] = {1, 5, 3, 8, 12}, n = 5;
    cout<<maxProfitNaive(arr, 0, n - 1)<<" ";
    cout<<maxProfitEfficient(arr,n);
    return 0;
}