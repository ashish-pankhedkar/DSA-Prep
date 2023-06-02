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


// Approach by using same linked list - Space optimized

int leng(ListNode *head)
{   
    int leng = 0;
    while (head != NULL)
    {
        head = head->next;
        leng++;
    }
    return leng;
}

ListNode *addTwoNumbers(ListNode *ll1, ListNode *ll2)
{
    //get length of the linked lists and take l1 as the biger one and l2 as smaller one
    int leng1 = leng(ll1);
    int leng2 = leng(ll2);
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    ListNode *ret = NULL; //this so that we can return at the end and to keep track of which we choose  
    if (leng1 > leng2)
    {
        l1 = ll1;
        ret = ll1;
        l2 = ll2;
    }

    else
    {
        l1 = ll2;
        ret = ll2;
        l2 = ll1;
    }
    //this prev needed to add carry at the last 
    ListNode *prev = NULL;
    int c = 0, val1 = 0, val2 = 0, sum = 0;
    while (l1 != NULL) //loop only till l1 as l1 is the larger one
    {
        val1 = l1->val;
        //if l2 is finsihed then take it as 0 else take val and go to next
        if (l2 == NULL)
        {
            val2 = 0;
        }
        else
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = val1 + val2 + c;
        c = sum / 10;
        sum %= 10;
        l1->val = sum;
        prev = l1;
        l1 = l1->next;
    }
    // if there is carry at the lsat then add it
    if (c)
    {
        prev->next = new ListNode(1);
    }
    return ret;
}


// Approach by creating new linked list
void insertTail(ListNode *&tail, int data)
{
    ListNode *temp = new ListNode(data);
    tail->next = temp;
    tail = temp;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(-1);
    ListNode *tail = ans;
    int c = 0, val1 = 0, val2 = 0, sum = 0;
    // traverse till both are not null
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
        {
            val1 = 0;
        }
        else
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if (l2 == NULL)
        {
            val2 = 0;
        }
        else
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        sum = val1 + val2 + c;
        c = sum / 10;
        sum %= 10;
        insertTail(tail, sum);
    }

    if (c)
    {
        insertTail(tail, 1);
    }

    return ans->next;
}

int main()
{

    return 0;
}