//Indexing starts from 1
//For indexing starting from 0, return(((n>>k)&1)==1);
#include <iostream> 
using namespace std; 
void isKthBitSet_LeftShift(int n, int k) 
{ 
	if (n&(1<<(k - 1))!=0) 
		cout << "set"; 
	else
		cout << "not set"; 
} 

void isKthBitSet_RightShift(int n,int k)
{
    if((n>>k-1)&1==1)
        cout<<"set";
    else
        cout<<"not set";

    
}
int main() 
{ 
	int n = 39, k = 5; 
	isKthBitSet_LeftShift(n, k); 
    isKthBitSet_RightShift(n,k);
	return 0; 
} 
