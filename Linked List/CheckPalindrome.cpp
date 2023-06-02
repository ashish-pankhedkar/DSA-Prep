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

ListNode *findMid(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else if (head->next->next == NULL)
        return head->next;

    else
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
}

ListNode *reverseLL_iterative(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
        ListNode *neeed = curr->next;
        curr->next = prev;
        prev = curr;
        curr = neeed;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *mid = findMid(head);
    mid->next = reverseLL_iterative(mid->next);
    ListNode *f = head;
    ListNode *s = mid->next;

    if (s == NULL)
    {
        return f->val == mid->val;
    }

    while (s != NULL)
    {
        if (f->val != s->val)
            return false;

        f = f->next;
        s = s->next;
    }
    return true;
}
int main()
{

    return 0;
}