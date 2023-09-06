//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
//https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
        if(n < 0) //if exponent is negative, inverse the number, and take absolute of the exponent
        {
            x = 1 / x;
            n = abs(n);
        }

        double result = 1;
        double current_product = x;

        while(n > 0) 
        {
            if(n % 2 == 1) //for odd powers, multiply the result by current product. This is done to avoid extra multiplications, and update the result
            {
                result = result * current_product;
            }
            //On Each iteration square the current_product
            current_product = current_product * current_product;
            n = n / 2;
        }

        return result;

        
    }

int main()
{
    int x=2;
    int n=10;
    cout<<myPow(x,n);

    return 0;
}