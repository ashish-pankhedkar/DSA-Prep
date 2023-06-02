#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLL(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "- " << temp->data << " -";
        temp = temp->next;
    }
}

void insertAthead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
    }
    else
    {
        node *temp = new node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAttail(node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new node(data);
    }

    node *temp2 = new node(data);
    tail->next = temp2;
    temp2->prev = tail;
    tail = temp2;
}


void insertAtpos(node* &head, node* &tail, int pos,int data)
{   
    node* temp=new node(data);
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    
    if(pos ==0)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    else
    {
        node* temp2 = head;
        pos--;
        while(pos--)
        {
            temp2=temp2->next;
        }
        if(temp2->next == NULL)
        {
        temp2->next = temp;
        temp->prev=temp2;
        tail = temp;
        return;
        }
        temp2->next->prev=temp;
        temp->next = temp2->next;
        temp2->next = temp;
        temp->prev=temp2;

    }
}


void DeleteNode(node* &head, int pos)
{   node* temp = head;
    if(pos == 0)
    {
        temp->next->prev = NULL;
        head =temp->next;
        return;
    }

    else{

        pos--;
        while(pos--)
        {
            temp=temp->next;

        }
        if(temp->next->next == NULL)
        {
            temp->next = NULL;
            //update tail if using
            return;
        }

        else
        {temp->next->next->prev = temp;
        temp->next = temp->next->next;
        return;
        }   
    }
}

int getlen(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

int main()
{
    node *head = new node(1);
    node* tail = head;
    // node* head = NULL;
    // printLL(head);
    // cout << endl;
    // cout << getlen(head) << endl;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 5);
    printLL(head);
    cout << endl;
    DeleteNode(head,3);
    printLL(head);
    cout<<endl;
    cout<<head->data;
    return 0;
} 