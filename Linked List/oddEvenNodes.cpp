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

void insertTail(ListNode *&tail, ListNode *newNode)
{
    tail->next = newNode;
    tail = newNode;
}

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    ListNode *oddListHead = new ListNode(-1);
    ListNode *oddListTail = oddListHead;

    ListNode *evenListHead = new ListNode(-1);
    ListNode *evenListTail = evenListHead;

    ListNode *temp = head;

    while (temp != NULL)
    {
        insertTail(oddListTail, temp);
        temp = temp->next;

        if (temp == NULL)
            break;

        insertTail(evenListTail, temp);
        temp = temp->next;
    }

    evenListTail->next = NULL;

    oddListTail->next = evenListHead->next;
    return oddListHead->next;
}
int main()
{
    return 0;
}