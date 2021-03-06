#include <iostream>
#include <limits.h>
using namespace std;

 int countTrailingZeros(int n) //Efficient
{
	int result = 0;
	for(int i=5; i<=n; i=i*5)
	{
		result = result + (n / i);
	}
	return result;
}
int main() 
{
    int number = 251;
    cout<<countTrailingZeros(number);
    return 0;
}