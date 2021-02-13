/*deque insert() function in C++ STL: Inserts an element. And returns an iterator that points to the first of the newly inserted elements.

deque rbegin() function in C++ STL: Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).

deque rend() function in C++ STL: Returns a reverse iterator which points to the position before the beginning of the deque (which is considered its reverse end).

deque cbegin() in C++ STL: Returns a constant iterator pointing to the first element of the container, that is, the iterator cannot be used to modify, only traverse the deque.

deque max_size() function in C++ STL: Returns the maximum number of elements that a deque container can hold.

deque assign() function in C++ STL: Assign values to the same or different deque container.

deque resize() function in C++ STL: Function which changes the size of the deque.

deque::push_front() in C++ STL: This function is used to push elements into a deque from the front.

deque::push_back() in C++ STL: This function is used to push elements into a deque from the back.

deque::pop_front() and deque::pop_back() in C++ STL: pop_front() function is used to pop or remove elements from a deque from the front. pop_back() function is used to pop or remove elements from a deque from the back.

deque::front() and deque::back() in C++ STL: front() function is used to reference the first element of the deque container. back() function is used to reference the last element of the deque container.

deque::clear() and deque::erase() in C++ STL: clear() function is used to remove all the elements of the deque container, thus making its size 0. erase() function is used to remove elements from a container from the specified position or range.

deque::empty() and deque::size() in C++ STL: empty() function is used to check if the deque container is empty or not. size() function is used to return the size of the deque container or the number of elements in the deque container.

deque::operator= and deque::operator[] in C++ STL:
operator= operator is used to assign new contents to the container by replacing the existing contents. operator[] operator is used to reference the element present at position given inside the operator.

deque::at() and deque::swap() in C++ STL: at() function is used reference the element present at the position given as the parameter to the function. swap() function is used to swap the contents of one deque with another deque of same type and size.

deque::begin() and deque::end in C++ STL: begin() function is used to return an iterator pointing to the first element of the deque container. end() function is used to return an iterator pointing to the last element of the deque container.

deque::emplace_front() and deque::emplace_back() in C++ STL: emplace_front() function is used to insert a new element into the deque container. The new element is added to the beginning of the deque.
emplace_back() function is used to insert a new element into the deque container. The new element is added to the end of the deque.
*/
#include<bits/stdc++.h>
using namespace std;
void display(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
    deque <int> DeQueue; 
    DeQueue.push_back(1); 
    DeQueue.push_front(2); 
    DeQueue.push_back(3); 
    DeQueue.push_front(4); 
    DeQueue.push_front(5); 

    cout << "The deque is : "; 
    display(DeQueue); 
  
    cout << "\nDeQueue.size() : " << DeQueue.size(); 
    cout << "\nDeQueue.max_size() : " << DeQueue.max_size(); 
  
    cout << "\nDeQueue.at(2) : " << DeQueue.at(2); 
    cout << "\nDeQueue.front() : " << DeQueue.front(); 
    cout << "\nDeQueue.back() : " << DeQueue.back(); 
  
    cout << "\nDeQueue.pop_front() : "; 
    DeQueue.pop_front(); 
    display(DeQueue); 
  
    cout << "\nDeQueue.pop_back() : "; 
    DeQueue.pop_back(); 
    display(DeQueue); 
  
    return 0; 
} 
