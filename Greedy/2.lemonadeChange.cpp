#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;
    for (int i = 0; i < bills.size(); i++)
    {

        if (bills[i] == 5)
            five++;
        if (bills[i] == 10)
            ten++;
        int change = bills[i] - 5;

        while (change >= 10 && ten > 0)
        {
            ten--;
            change -= 10;
        }

        while (change >= 5 && five > 0)
        {
            five--;
            change -= 5;
        }
        // cout<<"five "<<five<<" ten"<<ten<<endl;

        if (change > 0)
            return false;
    }
    return true;
}
int main()
{
    return 0;
}