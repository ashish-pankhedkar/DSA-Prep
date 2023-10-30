#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int mini = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        int profit = prices[i] - mini;
        maxProfit = max(maxProfit, profit);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}
int main()
{
    return 0;
}