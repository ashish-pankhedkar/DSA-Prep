#include <bits/stdc++.h>
using namespace std;
int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }

    return count;
}

int countDigits(int n) {
    string s = to_string(n);
    return s.size();
}
int main()
{
    return 0;
}