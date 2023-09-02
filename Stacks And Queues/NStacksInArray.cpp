#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class NStack
{
    int *arr;   //given array
    int *next;  //next array to store freespace if stack is empty else stop ke niche wala
    int *top;   //top of each stack
    int freespot;   //next free memloc i.e next ka index
    int n, s;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        freespot = 0;

        //initilaize all the arrays
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        //set top of all to -1 
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // memset(top,(-1),n);

        //set next free space
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        // if no free space then cant push return false
        if (freespot == -1)
        {
            return false;
        }
        
        //get the index of free space
        int index = freespot;

        //update the free space
        freespot = next[index];

        //push the element in available space
        arr[index] = x;

        //updat the next as pichla wala top i.e current top ke niche wala
        next[index] = top[m - 1];

        //update top of that stack as currrent index
        top[m - 1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // get the index as stack ka top
        int index = top[m - 1];

        //update the top as next since next was pichla wala top
        top[m - 1] = next[index];

        //store the top elemtn to return at the end
        int x = arr[index];

        //update the next as freespot as now the index is irrelevent and next of that is also irreleveant
        // so store the curent freespot
        next[index] = freespot;

        //freespot  is the current index which was poped because we know that it is sure shot free
        freespot = index;

        //return the stored value
        return x;
    }
};
int main()
{

    return 0;
}