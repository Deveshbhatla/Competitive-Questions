//GCD is also known as Highest common factor(HCF)
#include<bits/stdc++.h>
using namespace std;

 int gcd(int a, int b)//Euclidean Algorithm
{
	while(a!=b)
	{
		if(a > b)
			a = a - b;
		else
			b = b - a; 
	}
	return a;
}

 int gcd_Efficient(int a, int b)//optimised Euclidean Algorithm
{
	if(b==0)
		return a;

	return gcd(b, a % b);
}


int lcm(int a, int b)
{
    return (a * b) / gcd_Efficient(a, b);
}

int main() 
{
    int a = 12, b = 15;
    
    cout<<gcd(a, b)<<'\n';
    cout<<gcd_Efficient(a,b)<<'\n';

    cout<<"LCM is: "<<lcm(a,b);
    return 0;
}