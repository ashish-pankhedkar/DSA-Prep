#include<bits/stdc++.h>
using namespace std;

struct ListNode {
int data;
ListNode *next;
ListNode() : data(0), next(nullptr) {}
ListNode(int x) : data(x), next(nullptr) {}
ListNode(int x, ListNode *next) : data(x), next(next) {}
};




 ListNode * removeDuplicates( ListNode *head) 
{
    // your code goes here
    if(head==NULL || head->next == NULL)
    return head;
    
    ListNode* curr= head->next;
    ListNode* prev = head;
    unordered_set<int> s;
    s.insert(head->data);
    
    while(curr!=NULL)
    {  //if data found in set        
        if(s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            curr = curr->next;
        }
        
        else
        {  s.insert(curr->data);
            prev = curr;
            curr=curr->next;
        }
    }
    
    return head;
}
int main(){
     
   return 0;
}