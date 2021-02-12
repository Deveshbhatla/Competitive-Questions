#include <forward_list>
#include <iostream>
using namespace std;

int main()
{

    // Initialising a forward list
    forward_list<int> l = {/*front*/ 1, 2, 3 };    
    l.push_front(4);   
    l.push_front(5);
    // Popping out elements from list i.e. 3
    l.pop_front();
   
    for (int x : l)
        cout << x << " ";

//Assign function
 forward_list<int> l1;

    // Assigning values to the list
    l1.assign({ 10, 20, 30, 10 });

    forward_list<int> l2;

    // Assigning one list to another
    l2.assign(l1.begin(), l1.end());

    l1.assign(5, 10);// it will assign a list value 10, 5 times
    cout<<'\n';
    for (int x : l1)
        cout << x << " ";
    cout<<'\n';

    for (auto it = l2.begin(); it != l2.end(); it++)
        cout << (*it) << " ";

    return 0;
}
