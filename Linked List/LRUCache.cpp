#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class node
    {
    public:
        int key, value;
        node *prev;
        node *next;
        node(int Key, int Value)
        {
            key = Key;
            value = Value;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node *> m;
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        newnode->next = head->next;
        newnode->prev = head;
        head->next = newnode;
        newnode->next->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        node *nodeaddr = m[key];
        int res = nodeaddr->value;
        m.erase(key);
        deletenode(nodeaddr);
        addnode(nodeaddr);
        m[key] = head->next;
        return res;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        else if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};
int main()
{
    return 0;
}