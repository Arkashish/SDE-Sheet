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
class LFUCache
{
public:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> mp;
    LFUCache(int capacity)
    {
        // Write your code here.
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    void addnode(node *newnode)
    {
        node *tmp = head->next;
        newnode->next = tmp;
        newnode->prev = head;
        head->next = newnode;
        tmp->prev = newnode;
    }
    int get(int key)
    {
        // Write your code here.
        if (mp.find(key) != mp.end())
        {
            node *temp = mp[key];
            int ans = temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
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
        // Write your code here.
        if (mp.find(key) != mp.end())
        {
            node *old = mp[key];
            mp.erase(key);
            deletenode(old);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        mp[key] = head->next;
    }
};
