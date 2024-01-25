#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


//FLOYD CYCLE DETECTION - fast slow karo agar cycle toh mil jayenge



bool hasCycle(ListNode* head)
{
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && slow!= fast)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }

            slow=slow->next;
        }

        if(fast ==  NULL)
        return false;
        else return true;
}
int main(){
     
   return 0;
}