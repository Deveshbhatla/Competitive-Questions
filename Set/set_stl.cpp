//use to store elements in sorted order 
//set ignores duplicate values
/*

begin() , end()   --------
rbegin() , rend() -------- \  _____    O(1) Time Complexity
cbegin() , cend() ---------/
size() , empty()  --------

insert()         --------
count()          --------  \  
find()           --------    ---- >  O(logN) Time Complexity
lower_bound()    --------  /
upper_bound()    --------



insert() - This function is used to insert a new element in the Set.
begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows last element in the set.
rbegin()– Returns a reverse iterator pointing to the last element in the container.
rend()– Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
size() – Returns the number of elements in the set.
empty() – Returns whether the set is empty.

*/

#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s; //set<int,greater<int>>s; for decreasing order
    s.insert(1); 
    s.insert(4); 
    s.insert(2); 
    s.insert(5); 
    s.insert(6);

    for(int x:s)
        cout<<x<<" ";
    //for(auto it=s.begin();it!=s.end();it++)
        //cout<<*it<<" ";
  // for(auto it=s.rbegin();it!=s.rend();it++)// returns reverse iterator
       // cout<<*it<<" ";
    auto find=s.find(5);
    if(find==s.end())
    cout<<"Not Found";
    else
        cout<<"Found";   


// upper Bound
/*The set::upper_bound() is a built-in function in C++ STL which returns an iterator pointing to the immediate next element which is just greater than k. 
If the key passed in the parameter exceeds the maximum key in the container, then the iterator returned points to next of last element (which can be identified using set end() function) in the set container.
*/
    // when 2 is present, points to next element after 2 i.e 4
    auto it = s.upper_bound(2); 
    cout << "\nThe upper bound of key 2 is "; 
    cout << (*it) << '\n'; 

    // when 3 is not present. points to next greater after 3 i.e 4
    it = s.upper_bound(3); 
    cout << "The upper bound of key 3 is "; 
    cout << (*it) << '\n'; 
    it = s.upper_bound(10); 
    cout << "The upper bound of key 10 is "; 
    cout << (*it) << '\n'; 

//Lower Bound 
/*The set::lower_bound() is a built-in function in C++ STL which returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter. 
In case k is not present in the set container, the function returns an iterator pointing to the immediate next element which is just greater than k. 
If the key passed in the parameter exceeds the maximum value in the container, then the iterator returned points to the last element in the set container.*/
    // when 2 is present 
    auto it1 = s.lower_bound(2); 
    cout << "\nThe lower bound of key 2 is "; 
    cout << (*it1) << '\n'; 

    // when 3 is not present points to next greater after 3 
    it1 = s.lower_bound(3); 
    cout << "The lower bound of key 3 is "; 
    cout << (*it1) << '\n'; 

    // when 8 exceeds the max element in set 
    it1 = s.lower_bound(8); 
    cout << "The lower bound of key 8 is "; 
    cout << (*it1) << '\n'; 

    return 0;
}
