//can store repeated elements. the multoset is implemented as red black trees same as set.

// CPP program to illustrate the 
// erase() and count() function 
// in multiset

#include <iostream>
#include <algorithm>
#include <set>


using namespace std; 
int main() 
{ 
    
    multiset<int> s = { 15, 10, 15, 11, 10, 18, 18, 20, 20 };  
    
    cout <<"15 occurs "<< s.count(15)<< " times in container.\n"; 
            
    s.erase(15);//erases all occurences of 15
// Print again count of 15
    cout <<"15 occurs " << s.count(15) << " times in container.\n"; 
    
    // Erase a range using erase() function
    s.erase(s.begin(), s.end());
    cout<<"Size of multiset: "<<s.size()<<'\n';


    multiset<int> set; 

    // Function to insert elements 
    // in the multiset container 
    set.insert(1); 
    set.insert(3); 
    set.insert(3); 
    set.insert(5); 
    set.insert(4); 

    cout << "The multiset elements are: "; 
    for (auto it = set.begin(); it != set.end(); it++) 
        cout << *it << " "; 

    // when 3 is present 
    auto it = set.upper_bound(3); 
    cout << "\nThe upper bound of key 3 is "; 
    cout << (*it) << endl; 

    // when 2 is not present points to next greater after 2 
    it = set.upper_bound(2); 
    cout << "The upper bound of key 2 is "; 
    cout << (*it) << endl; 

    // when 10 exceeds the max element in multiset 
    it = set.upper_bound(10); 
    cout << "The upper bound of key 10 is "; 
    cout << (*it) << endl; 

/*
The multiset::equal_range() is a built-in function in C++ STL which returns an iterator of pairs. 
The pair refers to the range that includes all the elements in the container which have a key equivalent to k. 
The lower bound will be the element itself and the upper bound will point to the next element after key k. 
If there are no elements matching key K, the range returned is of length 0 with both iterators pointing to the first element which is greater than k according to the container’s internal comparison object (key_comp). 
If the key exceeds the maximum element in the set container, it returns an iterator pointing to the past the last element in the multiset container.
*/
    // Function returns lower bound and upper bound 
    auto itr = set.equal_range(3); 
    cout << "\nThe lower bound of 3 is " << *itr.first; 
    cout << "\nThe upper bound of 3 is " << *itr.second; 
    return 0; 
} 
