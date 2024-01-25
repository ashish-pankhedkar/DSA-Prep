#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(ListNode* fir, ListNode* sec)
    {   //char pointer banao track rakhne ke liye
        ListNode* curr1 = fir;
        ListNode* next1 = fir->next;
        ListNode* curr2 = sec;
        ListNode* next2 = curr2->next;


        if(next1 == NULL)
        {
            curr1->next = curr2;
            return fir;
        }

        while(next1 != NULL && curr2 != NULL)
        {   //agar dusri wali list ka element pehle wale list meke node me ghus raha hon
            //toh ghusa do aur pointr update kardo.
            if(curr2->val >= curr1->val && curr2->val <= next1->val)
            {   //node addition
                curr1->next = curr2;
                next2 = curr2->next; 
                curr2->next=next1;
                //pointer update for loop
                curr1=curr1->next;
                curr2 = next2;
            }
            //agar nahi ghus raha toh bas pointer aage badha do
            else
            {
                curr1 = next1;
                next1 = next1->next;

                if(next1 == NULL)
                {
                    // linked list khatam hogayi dusri wali
                    curr1->next = curr2;
                }
            }
        }

        return fir;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        //agar dono mese ek list null h toh bachi hui ko return kardo
        if(list1 == NULL) 
        return list2;
        else if(list2 == NULL)
        return list1;
        

        // jiska first node chota hai usko pehle pass karo
        if(list1->val < list2->val)
       return solve(list1,list2);
        
        else
        return solve(list2,list1);
     
    }

int main(){
     
   return 0;
}