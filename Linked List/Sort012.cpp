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

// USING FREQUENCY APPROACH

Node *segregate(Node *head)
{

    // Add code here
    if (head == NULL || head->next == NULL)
        return head;

    int cnt[3] = {0, 0, 0};

    Node *curr = head;

    // count frequency
    while (curr != NULL)
    {
        cnt[curr->data]++;
        curr = curr->next;
    }

    curr = head;
    int num = 0;
    while (curr != NULL)
    {
        if (cnt[num] == 0)
            num++;

        else
        {
            curr->data = num;
            curr = curr->next;
            cnt[num]--;
        }
    }

    return head;
}

// CHanging Links approach

void populate(Node *&head, Node *temp)
{
    head->next = temp;
    head = temp;
}

Node *segregate(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    // Add code here
    Node *Headzero = new Node(-1);
    Node *Headone = new Node(-1);
    Node *Headtwo = new Node(-1);
    Node *tailzero = Headzero;
    Node *tailone = Headone;
    Node *tailtwo = Headtwo;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            populate(tailzero, temp);
        }
        else if (temp->data == 1)
        {
            populate(tailone, temp);
        }
        else if (temp->data == 2)
        {
            populate(tailtwo, temp);
        }
        temp = temp->next;
    }

    if (Headone->next != NULL)
    {
        tailzero->next = Headone->next;
    }
    else
    {
        tailzero->next = Headtwo->next;
    }

    tailone->next = Headtwo->next;
    tailtwo->next = NULL;

    head = Headzero->next;
    return head;
}
int main()
{

    return 0;
}