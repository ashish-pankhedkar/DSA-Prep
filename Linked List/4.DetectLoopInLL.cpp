#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


// set approach
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
    return false;
    else {
        ListNode* temp = head;
        unordered_set<ListNode*> s;
        while(temp != NULL)
        {
            if(s.find(temp->next) != s.end())
            {
                return true;
            }
            else
            {
                s.insert(temp->next);
                temp=temp->next;
            }
        }
        
        return false;
    }
}

