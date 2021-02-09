#include <bits/stdc++.h>
#include <utility> //for pairs
#include <string> 
using namespace std;

int main()
{
    pair <string, int> g1;
    pair <string, int> g2("Check", 3);
    pair <string, int> g3(g2);
    pair <int, int> g4(5, 10);

    g1 = make_pair(string("Hello"), 1);
    g2.first = "World";
    g2.second = 2;

    cout << "This is pair g" << g1.second << " with value " << g1.first<<'\n';

    cout << "This is pair g" << g3.second<< " with value " << g3.first <<" This pair was initialized as a copy of pair g2" <<'\n';

    cout<<"This is pair g"<<g2.second<<" with value "<<g2.first<<" The values of this pair were changed after initialization."<<'\n';

    cout << "This is pair g4 with values "<< g4.first << " and " << g4.second<< " made for showing addition. The sum of the values in this pair is "
        << g4.first+g4.second<<'\n';

    cout << "We can concatenate the values of the pairs g1, g2 and g3 : "<< g1.first + g3.first + g2.first <<'\n';

    cout << "We can also swap pairs (but type of pairs should be same) : " << '\n';
    cout << "Before swapping, " << "g1 has " << g1.first<< " and g2 has " << g2.first << endl;
    swap(g1, g2);
    cout << "After swapping, " << "g1 has " << g1.first << " and g2 has " << g2.first;

    return 0;
}
