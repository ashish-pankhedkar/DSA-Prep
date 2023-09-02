#include <bits/stdc++.h>
using namespace std;

/*Just consider that in case of smaller element anyways we are storing that in min, so we can use the place in stack to save some other value that gets us to the previous min that we are overwriting.
So we can do value = current - previousmin
So that when we pop we can get the previousmin = current - value
(Note current is stored in min variable and value is the one stored in stack)
We are using 2*formula because without 2 multiplication negative and negative subtraction becomes bigger than min which is wrong as we always need value to be smaller so that we know that we have manipulated it greater values are taken as it is
eg: -7 - -2 = -7+2 = -5 greater than -7
but -7 -7 - -2 = -14 - - 2 = -14 + 2 = -12 smaller than -7*/

class SpecialStack
{
    // Define the data members.
    int mini;
    stack<int> s;

    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    SpecialStack()
    {
        mini = INT_MAX;
    }

    void push(int val)
    {
        if (s.empty())
        {
            mini = val;
            s.push(val);
        }

        else
        {
            if (val < mini)
            {
                s.push(2 * val - mini);
                mini = val;
            }

            else
                s.push(val);
        }
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }

        else
        {

            if (s.top() >= mini)
            {
                int x = s.top();
                s.pop();
                return x;
            }
            else
            {
                int x = mini;
                mini = 2 * mini - s.top();
                s.pop();
                return x;
            }
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        else
        {
            if (s.top() >= mini)
            {
                return s.top();
            }
            else
            {
                return mini;
            }
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin()
    {
        // Implement the getMin() function.
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{

    return 0;
}
