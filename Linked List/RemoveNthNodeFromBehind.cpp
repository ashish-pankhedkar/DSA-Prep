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
//fast slow approach

ListNode *removeNthFromEnd(ListNode *head, int n)
{   ListNode* st = head;
    ListNode* fast =st;
    ListNode* slow =st;

    for(int i=0;i<n;i++)
    {
        fast = fast->next ;
    }

    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;

    return st->next;
}

//my approach with calculating length
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int leng = 0;
    ListNode *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        leng++;
    }

    leng = leng - n;
    if (leng == 0)
    {
        return head->next;
    }
    temp = head;
    while (--leng)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;

    return head;
}

int main()
{

    return 0;
}