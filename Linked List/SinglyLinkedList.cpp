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

// Function to instert new data at head
void insertAtHead(node* &head,int data) //reference liya kyukinayi copy nahi bnani. usi me update krna h
{   //create new node
    node* temp = new node(data);
    //temp ka next is head    
    temp->next=head;
    head=temp;

}

void insertAttail(node* &tail,int data) //reference liya kyukinayi copy nahi bnani. usi me update krna h
{   //create new node
    node* temp = new node(data);
    tail->next = temp;
    tail = temp; 
    


} 
//Insertion at any give position
void insertAtpos(node* &head,node* &tail,int pos, int data)
{
    node* temp = head;
    node* temp2 = new node(data);
    if(pos==0)
    {
        temp2->next=head;
        head=temp2;
        return;
    }
    while(pos--)
    {
        temp = temp -> next;
    }
    temp2->next = temp->next;
    temp->next=temp2;
    if(temp2->next == NULL)
    {
        tail = tail->next;
    }

}


//Delettion

void DeleteNode(node* &head,node* &tail,int pos)
{
    if(pos ==0)
    {
        head = head->next;
        return;
    }

    node* temp=head;
    pos--;
    while(pos--)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    if(temp->next == NULL)
    {
        tail = temp;
    }

}


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

int main(){
    node* head = new node(1);
    node* tail = head;
    insertAttail(tail,2);
    insertAttail(tail,4);
    insertAttail(tail,5);
    printLL(head);
    cout<<endl;
    cout<<"head and tail before " <<head->data<<" "<<tail->data<<endl;
    DeleteNode(head,tail,3);
   
    printLL(head);
    cout<<endl;
    cout<<"head and tail after " <<head->data<<" "<<tail->data<<endl;
 
    // cout<<head->data<<" data "<<head->next<<" next";
     
   return 0;
}