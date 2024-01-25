//You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

//On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
//However, you can buy it then immediately sell it on the same day.

//Find and return the maximum profit you can achieve.

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/


// Uses DP with bottom up approach with time complexity of O(n) and space complexity of O(1)
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{

    //as we cannot sell on the first day, hence, setting the initial value to a large negative number;
    int currentHolding = INT_MIN;
    int currentNotHolding = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        //initializing two variables that keep track of the previous holdings
        int previousHolding = currentHolding;
        int previousNotHolding = currentNotHolding;

        //either you can hold the previous holding or buy a new stock today
        currentHolding = max(previousHolding, previousNotHolding - prices[i]);

        //either you can hold on to the previous stock that you were not holding, or sell stock today if you found a better stock
        currentNotHolding = max(previousNotHolding, previousHolding + prices[i]);

    }
    return currentNotHolding;
}

int main()
{
    vector<int> v={7,1,5,3,6,4};//output should be 7
    cout<<"max profit: "<<maxProfit(v);
    
    return 0;
}