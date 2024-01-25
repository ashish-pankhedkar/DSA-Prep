#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    //constructor
    ListNode(int data)
    {
        this ->data=data;
        this->next = NULL;
    }
   
};


//Function to print linked list
void printLL(ListNode* &head)
{   
    ListNode* temp = head;
    while(temp != NULL)
    {
        cout<<"- "<<temp->data<<" -";
        temp=temp->next;
    }
}

void reverseLL_interative(ListNode* &head)
{
    ListNode* curr =head;
    ListNode* prev = NULL;

    while(curr != NULL)
    {
        ListNode* neeed = curr->next;
        curr->next = prev;
        prev= curr;
        curr= neeed;
    }
    head = prev;
}

int main(){

    ListNode* head= new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    printLL(head);
    cout<<endl;
    reverseLL_interative(head);
    printLL(head);

     
   return 0;
}