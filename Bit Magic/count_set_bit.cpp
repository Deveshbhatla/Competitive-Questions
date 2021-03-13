#include <iostream>
using namespace std;
int count_set_bit(int n) //Naive Solution O(total bit length)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 != 0) //to check if last bit is set. Same as if(n&1==1)
            count++;
        n = n / 2; //To remove last bit. Same as n>>1;
    }
    return count;
}
int countSetBits_Brian_and_Kerningham_algorithm(int n)//O(Number of set bits)
{
    int count = 0;
    while (n) //same as while(n>0)
    {
        n= n&(n - 1); //if you subtract 1 from a binary number, all the bits to left of first set bit becomes 1 and set bit becomes 0.
        //eg: 100011000-1=100010111. The and of two numbers become 100010000, last set bit is removed.
        count++;
    }
    return count;
}

//O(1) solution
  int table[256];
	
	// recursive function to count set bits 
	void initialize() 
    { 
      // To initially generate the table algorithmically:
      table[0] = 0;
      for (int i = 0; i < 256; i++)
      {
          table[i] = (i & 1) + table[i / 2];
      }
	} 
	
	int countSetBits_Tabular(int n)
	{
	    return table[n & 0xff] + 
        table[(n >> 8) & 0xff] + 
        table[(n >> 16) & 0xff] + 
        table[n >> 24]; 
	}

int main()
{
    int n = 5;
    cout << count_set_bit(n);
    cout<<countSetBits_Brian_and_Kerningham_algorithm(n);

    initialize();
    cout<<countSetBits_Tabular(n);
    return 0;
}
