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

void reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *neeed = curr->next;
        curr->next = prev;
        prev = curr;
        curr = neeed;
    }
    head = prev;
}

Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    if (head == NULL)
        return head;

    else if (head->next == NULL)
    {
        head->data += 1;
        return head;
    }

    else
    {
        reverse(head);

        Node *temp = head;
        Node *prev = NULL;

        int carry = 0;
        int digit = 0;

        // add one to first place
        digit = temp->data + 1 + carry;
        carry = digit / 10;
        digit %= 10;
        temp->data = digit;
        prev = temp;
        temp = temp->next;

        while (temp != NULL)
        {
            digit = temp->data + carry;
            carry = digit / 10;
            digit %= 10;
            temp->data = digit;
            prev = temp;
            temp = temp->next;
        }

        if (carry)
        {
            prev->next = new Node(1);
        }

        reverse(head);
        return head;
    }
}
int main()
{

    return 0;
}