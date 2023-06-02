#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    
    if(head == NULL || head->next == NULL)
    {
        return 0;
    }
    
    Node* fast = head->next;
    Node* slow= head;
    int len = 1;
    
    while(fast!= NULL)
    {
        fast=fast->next;
        if(fast != NULL)
        fast=fast->next;
        
        slow=slow->next;
        
        if(slow == fast)
        break;
    }
    
    if(fast == NULL)
    return 0;
    
    slow=slow->next;
    
    while(fast != slow)
    {
        slow=slow->next;
        len++;
    }
    return len;
    
    
}

int main(){
     
   return 0;
}