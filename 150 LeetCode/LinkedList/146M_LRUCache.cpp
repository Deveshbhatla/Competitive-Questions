// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

// Doubly linked list
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    unordered_map<int, Node *> map;

    int capacity, count;
    Node *head, *tail;

    LRUCache(int c) // constructor to create a cache of a specific size
    {
        capacity = c;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
        count = 0;
    }

    void deleteNode(Node *delnode) // deleting a node from the doubly linked list
    {
        Node *prevv = delnode->prev;
        Node *nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    void addToHead(Node *node) // Adding a new node into doubly linked list at the head
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    int get(int key)
    {
        if (map[key] != NULL)
        {
            Node *node = map[key];
            int result = node->value;
            deleteNode(node);
            addToHead(node);
            cout << "Got the value : " << result << " for the key: " << key << endl;
            return result;
        }
        cout << "Did not get any value for the key: " << key << endl;
        return -1;
    }

    void put(int key, int value)
    {
        cout << "Going to set the (key, "
             << "value) : (" << key << ", " << value << ")" << endl;
        if (map[key] != NULL)
        {
            Node *node = map[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            map[key] = node;
            if (count < capacity)
            {
                count++;
                addToHead(node);
            }
            else
            {
                map.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(node);
            }
        }
    }
};

int main()
{
    {

        LRUCache cache(2);

        // it will store a key (1) with value
        // 10 in the cache.
        cache.put(1, 10);

        // it will store a key (2) with value 20 in the cache.
        cache.put(2, 20);
        cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns 10

        // removing key 2 and store a key (3) with value 30 in the cache.
        cache.put(3, 30);

        cout << "Value for the key: 2 is " << cache.get(2) << endl; // returns -1 (not found)

        // removing key 1 and store a key (4) with value 40 in the cache.
        cache.put(4, 40);

        cout << "Value for the key: 1 is " << cache.get(1) << endl; // returns -1 (not found)
        cout << "Value for the key: 3 is " << cache.get(3) << endl; // returns 30
        cout << "Value for the key: 4 is " << cache.get(4) << endl; // return 40

        return 0;
    }
}