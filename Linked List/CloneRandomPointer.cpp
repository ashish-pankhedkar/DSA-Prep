#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// SC O(1) approach using mixing of linkedlist

Node *copyRandomList(Node *head)
{

    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
    {
        Node *CloneHead = new Node(head->val);
        if (head->random == NULL)
        {
            CloneHead->random = NULL;
        }
        else
        {
            CloneHead->random = CloneHead;
        }
        return CloneHead;
    }

    Node *CloneHead = new Node(head->val);
    Node *CloneTail = CloneHead;
    Node *temp = head->next;
    while (temp != NULL)
    {
        CloneTail->next = new Node(temp->val);
        temp = temp->next;
        CloneTail = CloneTail->next;
    }

    CloneTail->next = NULL;

    temp = head;
    Node *temp2 = CloneHead;
    Node *temp3 = NULL;
    Node *temp4 = NULL;
    while (temp != NULL)
    {
        temp3 = temp->next;
        temp4 = temp2->next;
        temp->next = temp2;
        temp2->next = temp3;
        temp = temp3;
        temp2 = temp4;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        else
            temp->next->random = NULL;

        temp = temp->next->next;
    }

    temp2 = head->next;
    temp3 = NULL;
    temp = head;
    while (temp != NULL)
    {
        temp3 = temp->next;
        temp->next = temp->next->next;
        if (temp3->next)
        {
            temp3->next = temp3->next->next;
        }
        temp = temp->next;
    }

    return temp2;
}

// My approach using  map to store to store old->new  mapping
Node *copyRandomList(Node *head)
{

    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
    {
        Node *CloneHead = new Node(head->val);
        if (head->random == NULL)
        {
            CloneHead->random = NULL;
        }
        else
        {
            CloneHead->random = CloneHead;
        }
        return CloneHead;
    }

    unordered_map<Node *, Node *> oldnew;

    Node *CloneHead = new Node(head->val);
    Node *CloneTail = CloneHead;
    Node *temp = head->next;
    while (temp != NULL)
    {
        CloneTail->next = new Node(temp->val);
        temp = temp->next;
        CloneTail = CloneTail->next;
    }

    CloneTail->next = NULL;

    temp = head;
    Node *temp2 = CloneHead;

    while (temp != NULL && temp2 != NULL)
    {
        oldnew[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = CloneHead;
    temp2 = head;
    while (temp != NULL)
    {
        temp->random = oldnew[temp2->random];
        temp = temp->next;
        temp2 = temp2->next;
    }

    return CloneHead;
}
int main()
{

    return 0;
}