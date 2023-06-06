#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;

    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}
Node *sortLL(Node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = sortLL(left);
    right = sortLL(right);

    Node *result = merge(left, right);

    return result;
}
int main()
{

    return 0;
}