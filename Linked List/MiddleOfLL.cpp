#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Normal length approach
int getMiddle(Node *head)
{
    // Your code here

    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    int mid = len % 2 ? ((len + 1) / 2) : ((len / 2) + 1);
    temp = head;
    mid--;
    while (mid--)
    {
        temp = temp->next;
    }
    return temp->data;
}

// fast slow approach
Node *getMiddlee(Node *head)
{
    // handle easy cases of null head, one node , twp nodes
    if (head == NULL || head->next == NULL)
        return head;
    else if (head->next->next == NULL)
        return head->next;

    else
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;

            slow = slow->next;
        }
        return slow;
    }
}

void printLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "- " << temp->data << " -";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    printLL(head);
    cout << endl;
    cout << getMiddlee(head)->data;
    return 0;
}