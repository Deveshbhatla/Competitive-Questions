
#include <bits/stdc++.h>
//#include <vector>
using namespace std;

// Driver Method
int main()
{
    vector<int> v = { 10, 20, 30, 40, 50 };

    // i points to the first element 10
    vector<int>::iterator i = v.begin();//or auto i=v.begin();
    

    // By default next() moves one position ahead
    i = next(i);

    // Prints the value 20
    cout << (*i) << " ";//20

    // Moves i two positions ahead
     i = next(i, 2);

    cout << (*i) << " ";//40

    // Moves back one position Pointing to 30
    i = prev(i);

    cout << (*i) << " ";// 30
    return 0;
}
