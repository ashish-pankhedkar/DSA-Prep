#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// STRIVER ----------ITERATIVE

ListNode *findKthNode(ListNode *head, int k)
{
    ListNode *temp = head;

    while (temp != NULL && --k)
    {
        temp = temp->next;
    }

    return temp;
}

void reverse(ListNode *head)
{
    ListNode *next = NULL, *prev = NULL, *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head, *prevNode = NULL, *nextNode = NULL;

    while (temp != NULL)
    {
        ListNode *kthNode = findKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevNode != NULL)
                prevNode->next = temp;
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if (temp == head)
            head = kthNode;
        else
        {
            prevNode->next = kthNode;
        }

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}



// LOVE BABBAR ---RECURSEIVE

ListNode *reverseKGroup(ListNode *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // step 1 :reverse first k nodes
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    int cnt = 0;

    // Calculate length
    int len = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    if (len >= k)
    {
        while (curr != NULL && cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // step 2 : revursion dekh lega age ka

        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
    else
        return head;
}
int main()
{

    return 0;
}