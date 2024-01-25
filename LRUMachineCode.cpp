#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *previous;
    Node *next;
    int value;
    int key;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        previous = NULL;
        next = NULL;
    }
};

class Cache
{

public:
    int capacity;
    int time_limit;
    string evictionPolicy;
    Cache(){}

    Cache(string evictionPolicy, int capacity, int time_limit)
    {
        this->evictionPolicy = evictionPolicy;
        this->capacity = capacity;
        this->time_limit = time_limit;
    }

    virtual int getValue(int key) = 0;
    virtual void put(int key, int value) = 0;
};

class LruCache : public Cache
{
    Node *head = NULL, *tail = NULL;
    map<int, Node *> cache_map;

public:
  
    int getValue(int key)
    {
        if (cache_map.find(key) == cache_map.end())
        {
            cout << "key not found" << endl;
            return -1;
        }
        else
        {
            return cache_map[key]->value;
        }
    }

    void put(int key, int value)
    {
        if (cache_map.find(key) != cache_map.end())
        {
            // key is present
            Node *to_delete_node = cache_map[key];
            shiftNode(to_delete_node);
            tail->value = value;
            cache_map[key] = tail;
        }
        else
        {
            // key not being present
            if (cache_map.size() < capacity)
            {
                Node *newNode = new Node(key, value);
                cache_map[key] = newNode;
                if (head == NULL and tail == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                    insertAtEnd(newNode);
            }
            else
            {
                // capacity being full, remove the head from linkedlist and map
                int to_remove_key = head->key;
                cache_map.erase(to_remove_key);
                head = head->next;
                put(key, value);
            }
        }
    }

    void shiftNode(Node *to_delete_node)
    {
        Node *prev_node = to_delete_node->previous;
        prev_node->next = to_delete_node->next;
        to_delete_node->next->previous = prev_node;

        tail->next = to_delete_node;
        tail = to_delete_node;
    }

    void insertAtEnd(Node *node)
    {
        tail->next = node;
        node->next = NULL;
        tail = node;
    }
};

int main()
{

    Cache *lru;
    lru
    LruCache lru("LRU", 4, 4);
    lru.put(1, 100);
    lru.put(2, 200);
    lru.put(3, 300);
    lru.put(4, 400);
    cout << lru.getValue(3)<<endl;
    lru.put(5, 500);
    cout << lru->getValue(1);

    // cout << foo(2+2);
    return 0;
}