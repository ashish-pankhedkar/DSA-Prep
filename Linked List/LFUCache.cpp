#include <bits/stdc++.h>
using namespace std;
//struct to maintain  the key value next prev and count of times it has occured
struct node
{
    int key, value, cnt;
    node *next;
    node *prev;
    node(int Key, int Value)
    {
        key = Key;
        value = Value;
        cnt = 1;
    }
};
// linked list to connect all then nodes
struct List
{
    int size;
    node *head;
    node *tail;
    List()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addnode(node *newnode)
    {
        newnode->next = head->next;
        newnode->prev = head;
        head->next = newnode;
        newnode->next->prev = newnode;
        size++;
    }
    
    void removenode(node *delnode)
    {
        delnode->next->prev = delnode->prev;
        delnode->prev->next = delnode->next;
        size--;
    }
};

class LFUCache
{
public:
    // key node map to keep track of each key and corresponding node
    map<int, node *> keynode;
    // map to maintain each list for each freq
    map<int, List *> freq;
    // max szie of the cache
    int maxsize;
    // minimium freq of a key
    int minfreq;
    //current size of the cache
    int currsize;

    LFUCache(int capacity)
    {
        maxsize = capacity;
        minfreq = 0;
        currsize = 0;
    }

    void updatefreq(node *nodee)
    {   // remove the key node pair from the keynode map 
        keynode.erase(nodee->key);
        //remoe the node from the list
        freq[nodee->cnt]->removenode(nodee);
        //if the node is the last node of its min frequency then removing it will cause no node of that freq and hence increase the min freq
        if (nodee->cnt == minfreq && freq[nodee->cnt]->size == 0)
            minfreq++;

        // create a new list for the newer freq of the node
        List *newHighFreqList = new List();
        // if a list for the new freq exists then use it only
        if (freq.find(nodee->cnt + 1) != freq.end()) // already a list for that freq exists
        {
            newHighFreqList = freq[nodee->cnt + 1];
        }
        //increase the freq
        nodee->cnt += 1;
        // add the node to the new freq list
        newHighFreqList->addnode(nodee);
        // change the freq list to the new one for the new freq in map
        freq[nodee->cnt] = newHighFreqList;
        //change the node of the key to the new node
        keynode[nodee->key] = nodee;
    }

    int get(int key)
    { //If not found return -1
        if (keynode.find(key) == keynode.end())
            return -1;
     //get the node for the key
        node *nodee = keynode[key];
        //store the value of the key so as to return later
        int res = nodee->value;
        //update the frequency of that node
        updatefreq(nodee);
        //return the value
        return res;
    }

    void put(int key, int value)
    {
        if (maxsize == 0)
            return;
        // already existing number, change the vlaue and update the frequency
        if (keynode.find(key) != keynode.end())
        {
            keynode[key]->value = value;
            updatefreq(keynode[key]);
        }
        // new number first time entry
        else
        {   //if the cache is filled remove the last node from the min freq
            if (currsize == maxsize)
            {   //get list of min freq
                List *list = freq[minfreq];
                //remove it from keynode map
                keynode.erase(list->tail->prev->key);
                //rempve the node
                freq[minfreq]->removenode(list->tail->prev);
                //decrease size
                currsize--;
            }
            // increase the size as new element to be added
            currsize++;
            // this is first time so min freq will be 1
            minfreq = 1;
            // create new list
            List *list = new List();
            //if list for one is already present use that
            if (freq.find(minfreq) != freq.end())
            {
                list = freq[minfreq];
            }
            // create new node for the key value
            node *nodee = new node(key, value);
            // add it to the list
            list->addnode(nodee);
            //add that to keynode map
            keynode[key] = nodee;
            // assign the new list to freq map
            freq[minfreq] = list;
        }
    }
};
int main()
{
    return 0;
}