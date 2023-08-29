#include <bits/stdc++.h>
using namespace std;

    int maxProfit(vector<int>& prices) {
        //Brute Force

        // int minPrice=prices[0];
        // int k;
        // int Profit=0;

        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     for(int j =i+1;j<prices.size();j++)
        //     {
        //         if(prices[j]>prices[i]&&Profit<prices[j]-prices[i])
        //         {
        //             Profit=prices[j]-prices[i];
        //         }
        //     }
        // }

        // return Profit;


        int lowestPrice = INT_MAX; // Lowest price
        int finalProfit = 0; 
        int currentProfit = 0; // profit if sold today
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lowestPrice)// if current price is smaller than the lowest price
            { 
                lowestPrice = prices[i]; // update the lowest price 
            }
            currentProfit = prices[i] - lowestPrice; // calculating current profit
            if(finalProfit < currentProfit)// if current is more than our previous final profit
            { 
                finalProfit = currentProfit; // update final profit
            }
        }
        return finalProfit;  

        
    }
    
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}