#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head == NULL)
        return NULL;


        //step 1 :reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = 0;

        //Calculate length
        int len =0;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            temp = temp->next;
            len++;
        }

        if(len>=k)
        { while(curr!=NULL && cnt<k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr  = next;
                cnt++;
            }


            //step 2 : revursion dekh lega age ka

            if(next != NULL)
            {
                head->next = reverseKGroup(next,k);
            }

            return prev;
        }
        else
        return head;
    }
int main(){
     
   return 0;
}