#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> m;

    // Insert elements using insert() function
    m.insert({ 10, 100 });
    m.insert({ 30, 300 });

    // Inserting using "[]" operator
    m[20] = 200;

    // Donot provide any value with key 40 The operator access the key and since it doesnot exists, it will insert defaut value of int ie 0
    m[40];
   
    cout << "The map is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = m.begin(); itr != m.end(); itr++) 
    {
        cout << '\t' << itr->first<< '\t' << itr->second << '\n';
    }
    cout <<'\n';

    // We can also update the value of an existing key-value pair using "[]" operator which is not possible with insert() function
    m[40] = 400;

    cout << "\nThe map is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = m.begin(); itr != m.end(); itr++)
     {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

cout<<"the elements from position 30 are: "<<'\n';
   for (auto itr = m.find(30); itr != m.end(); itr++)
        cout << itr->first<< '\t' << itr->second << '\n';


//Lower bound 
    map<int, int> mp;
    mp.insert({ 2, 30 });
    mp.insert({ 1, 10 });
    mp.insert({ 5, 50 });
    mp.insert({ 4, 40 });
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // when 2 is present
    auto it = mp.lower_bound(2);
    cout << "The lower bound of key 2 is ";
    cout << (*it).first << " " << (*it).second << endl;

    // when 3 is not present points to next greater after 3
    it = mp.lower_bound(3);
    cout << "The lower bound of key 3 is ";
    cout << (*it).first << " " << (*it).second;

    // when 6 exceeds
    it = mp.lower_bound(6);
    cout << "\nThe lower bound of key 6 is ";
    cout << (*it).first << " " << (*it).second;

cout<<'\n';
    mp.insert({ 12, 30 });
    mp.insert({ 11, 10 });
    mp.insert({ 15, 50 });
    mp.insert({ 14, 40 });
     auto itr = mp.upper_bound(11);
    cout << "The upper bound of key 11 is ";
    cout << (*itr).first << " " << (*itr).second << endl;

    // when 13 is not present
    itr = mp.upper_bound(13);
    cout << "The upper bound of key 13 is ";
    cout << (*itr).first << " " << (*itr).second << endl;

    // when 17 is exceeds the maximum key, so size of mp is returned as key and value as 0.
    itr = mp.upper_bound(17);
    cout << "The upper bound of key 17 is ";
    cout << (*itr).first << " " << (*itr).second;

    return 0;
}