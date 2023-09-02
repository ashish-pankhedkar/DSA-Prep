#include <bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    vector<long long> ans;
    queue<long long int> q;

    long long int f = 0;
    long long int l = K - 1;

    //insert only the negative of  first k elements
    for (long long int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
    }
    // loop from first window to last 
    while (l < N)
    {   //if q is empty i.e no negative elemnt  => 0 
        if (q.empty())
        {
            ans.push_back(0);
        }
        //else the first element of the queue is the first negative element in k window
        else
        {
            ans.push_back(q.front());
        }
    // if curent first element was negative then pop it as the next window wont contain it
        if (A[f] < 0)
        {
            q.pop();
        }
        // increment the indices
        f++;
        l++;
        // if the new element in the winodw is negative then add it to the queue
        if (A[l] < 0)
        {
            q.push(A[l]);
        }
    }

    return ans;
}
int main()
{
    return 0;
}