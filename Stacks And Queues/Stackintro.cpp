#include <bits/stdc++.h>
using namespace std;

// implementation of stack using array/vector
class stackk{
    private:
    vector<int> s;
    int size=0;
    public:
    void push(int data)
    {
        s.push_back(data);
        size++;
    }
    void pop()
    {
        if(size == 0)
        {
            cout<<"Stack Empty cannot pop  ";
            
        }        
        else{
            size--;
            
        }
    }

    int top()
    {
        if(size == 0)
        {
            cout<<"Stack Empty no element at top";
            return -1;
        }    
        else{
            return s[size-1];
        }

    }
    bool isEmpty()
    {
        return size==0;
    }
};

int main()
{
    stackk s;
    s.push(2);
    // s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.isEmpty();
    return 0;
}