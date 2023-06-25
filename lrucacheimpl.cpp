#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int key, val;
    node *prev;
    node *next;
    node(int key1, int value1)
    {
        key = key1;
        val = value1;
    }
};
class LRUCache
{
public:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> mp;
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *tmp = head->next;
        newnode->next = tmp;
        newnode->prev = head;
        head->next = newnode;
        tmp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        // Write your code here
        if (mp.find(key) != mp.end())
        {
            node *tmp = mp[key];
            int ans = tmp->val;
            mp.erase(key);
            deletenode(tmp);
            addnode(tmp);
            mp[key] = head->next;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        // Write your code here
        if (mp.find(key) != mp.end())
        {
            node *old = mp[key];
            mp.erase(key);
            deletenode(old);
        }
        else if (cap == mp.size())
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};
