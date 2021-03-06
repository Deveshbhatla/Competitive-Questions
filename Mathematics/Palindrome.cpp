#include <iostream>
#include <limits.h>
using namespace std;

bool isPalindrome(int n)
{
	int reverse = 0;
	int temp = n;

	while(temp != 0)
	{
		int last_digit = temp % 10;
		reverse = reverse * 10 + last_digit;
		temp = temp / 10;//removing last digit from the number
	}	
	return reverse==n;
}
int main() 
{
       	int number = 11211;
    	cout<<isPalindrome(number);
    	return 0;
}