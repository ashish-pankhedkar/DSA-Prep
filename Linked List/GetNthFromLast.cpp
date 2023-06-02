#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to find the data of nth node from the end of a linked list.

int getNthFromLast(Node *head, int n)
{
    // Your code here

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {   //it means that n is greater than length
        if (fast == NULL)
            return -1;
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

int main()
{

    return 0;
}