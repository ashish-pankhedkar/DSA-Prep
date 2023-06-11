#include<bits/stdc++.h>
using namespace std;

// Function to insert element at correct place in stack
void insert(stack<int> &s,int x)
{
    //if top is small or stack is empty then push the element
	if(s.empty() || s.top()<=x)
	{
		s.push(x);
		return;
	}
	//else if top is greater then store the top recurse fpor remaining part then push the bigger top.
	else 
	{
		int y= s.top();
		s.pop();
		insert(s,x);
		s.push(y);
		return;
	}

	
}

//function to sort
void sortStack(stack<int> &st)
{
	// Write your code here

	if(st.empty())
	{
		return;
	}
	else{
		int x = st.top();
		st.pop();
		sortStack(st);
		insert(st,x);
		return;
	}
}
int main(){
     
   return 0;
}