#include <bits/stdc++.h>
using namespace std;
int from1(int n)
{
    switch (n % 4)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return (n + 1);
    case 3:
        return 0;
    }
}
int findXOR(int l, int r)
{
    // complete the function here
    return from1(l - 1) ^ from1(r);
}
int main()
{
    return 0;
}