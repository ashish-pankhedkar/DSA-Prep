#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


//FLOYD CYCLE DETECTION - fast slow karo agar cycle toh mil jayenge



ListNode* startloop(ListNode* head)
{   if(head ==NULL)
    return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }

            slow=slow->next;

            if(slow == fast)
            break;
        }

        if(fast == NULL)
        return NULL;
// AFTER THIS START SLOW FROM HEAD AND MOVE FAST,SLOW ONE STEP TILL THEY ARE EQUAL
        slow = head;
        while(slow!= fast)
        {
            slow=slow->next;
            fast=fast->next;
        }

        return fast;
}




void REMOVELOOP(ListNode* head)
{
        ListNode* temp = startloop(head);
        ListNode* temp2 = temp; 
        while(temp2->next != temp)
        {
            temp2=temp2->next;
        }

        temp2->next = NULL;
}



int main(){
     
   return 0;
}