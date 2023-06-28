#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;

    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto c : word)
        {
            if (!node->containsKey(c))
                node->put(c, new Node());

            node = node->get(c);
        }

        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (auto c : word)
        {
            if (!node->containsKey(c))
                return false;

            node = node->get(c);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (auto c : prefix)
        {
            if (!node->containsKey(c))
                return false;
            node = node->get(c);
        }

        return true;
    }
};
