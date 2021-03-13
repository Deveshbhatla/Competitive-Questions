#include <iostream>
using namespace std;

int main() {
	
	int x = 3, y = 6;
	
	cout<<(x & y)<<endl;   //&   2
	
	cout<<(x | y)<<endl;    //|  7
	
	cout<<(x ^ y)<<endl;    //^  5
	
	int n = 1; //~
	cout<<(~ n)<<endl;//-2 
	n = 5;
	cout<<(~ n)<<endl; //-6

    unsigned int z = 1;
	cout<<(~ z)<<endl;//4294967294
	z = 5;
	cout<<(~ z)<<endl;//4294967290

    int Left_Shift = 3; //Left Shift
	cout<<(Left_Shift << 1)<<endl;//6
	cout<<(Left_Shift << 2)<<endl;//12

	int Right_Shift = 33; //Right Shift
	cout<<(Right_Shift >> 1)<<endl;//16
	cout<<(Right_Shift >> 2)<<endl;//8
	
	return 0;
}
