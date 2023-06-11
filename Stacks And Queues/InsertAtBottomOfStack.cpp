#include<bits/stdc++.h>
using namespace std;

//Extra stack approach 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    stack<int> s;

    while(!myStack.empty())
    {
        s.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while(!s.empty())
    {
        myStack.push(s.top());
        s.pop();
    }
    return myStack;

}


//recursion

void rec(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;

    }

    else
    {
        int k = s.top();
        s.pop();
        rec(s,x);
        s.push(k);
        return;
    }
}

stack<int> pushAtBottom2(stack<int>& myStack, int x) 
{
    // Write your code here.
    rec(myStack,x);
    return myStack;

}
int main(){
     
   return 0;
}