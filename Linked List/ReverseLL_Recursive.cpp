#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    //constructor
    node(int data)
    {
        this ->data=data;
        this->next = NULL;
    }
   
};


//Function to print linked list
void printLL(node* &head)
{   
    node* temp = head;
    while(temp != NULL)
    {
        cout<<"- "<<temp->data<<" -";
        temp=temp->next;
    }
}

void reverseLL_recursive(node* &head, node* curr, node* prev)
{   
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    node* need = curr->next;
    reverseLL_recursive(head,need,curr);
    curr->next=prev;
    
}

int main(){

    node* head= new node(1);
    // head->next = new node(2);
    // head->next->next = new node(3);
    // head->next->next->next = new node(4);
    printLL(head);
    cout<<endl;
    reverseLL_recursive(head,head,NULL);
    printLL(head);

     
   return 0;
}