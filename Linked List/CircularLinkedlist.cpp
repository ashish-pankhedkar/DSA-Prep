#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	// constructor
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void insert(Node *&tail, int element, int data)
{
	Node *newNode = new Node(data);
	if (tail == NULL)
	{
		newNode->next = newNode;
		tail = newNode;
		return;
	}

	else
	{
		Node *curr = tail;
		while (curr->data != element)
		{
			curr = tail->next;
		}

		newNode->next = curr->next;
		curr->next = newNode;
		return;
	}
}


void print(Node* tail)
{
	Node* curr = tail;
	if(curr == NULL)
	{
		cout<<"Empty List"<<endl;
	}
	// cout<<"-"<<curr->data<<"-";
	// curr=curr->next;
	do
	{
		cout<<"-"<<curr->data<<"-";
		curr=curr->next;
	}
	while(curr!= tail);
	cout<<endl;
}


void del(Node* &tail, int val)
{
Node* prev = tail;
Node* curr = tail->next;
if(tail == NULL)
{
	cout<<"empty list cant be deleted"<<endl;
	return;
}

//only one node present
else if( curr == prev)
{
	tail = NULL;
	return;
}

else{
	
	while(curr->data != val)
	{	
		prev = curr;
		curr=curr->next;
	}
	prev->next = curr->next;

	if(tail == curr)
	{
		tail=tail->next;
	}
	curr->next = NULL;
	// delete curr;
}

}
int main()
{
	Node* tail = NULL;

	insert(tail,0,0);
	print(tail);

	del(tail,0);
	print(tail);

	// insert(tail,0,1);
	// // print(tail);

	// insert(tail,1,3);
	// // print(tail);

	// insert(tail,1,2);
	// print(tail);

	// del(tail,0);
	// print(tail);

	return 0;
}

