#include <bits/stdc++.h>
using namespace std;
int countDigits(int x)//O(result)
{
	int result = 0;
	while(x > 0)
	{
			x = x / 10;
			result++;
	}	
	return result;
}
int countDigitsEfficient(int N) //O(1)
{ 
    int k;
    k = floor(log10(N) + 1);
    return k;
}
int main() {
    
    	int number = 789;
    	
    	cout<<countDigits(number);
    	cout<<countDigitsEfficient(number);
    	return 0;
}
