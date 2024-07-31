#include <bits/stdc++.h>

using namespace std;

bool check (long long x)
{
    for (long long i=2;i<=sqrt(x);++i)
    if (x%i==0)return false;
    return x>1;
}
long long tcs(long long x)
{
    long long s=0;
    while(x!=0)
    {
        s+=(x%10)*(x%10);
        x/=10;
    }
    return s;
}
bool check1(long long n)
{
    long long s=0;
    while(n>=0)
    {
        n=tcs(n);
    }
    return n==1;
}
long long n;
int main()
{
    cin >> n;
    for (long long i=n;i>=1;--i)
    {
        if (check(i) or n%i==0)
        {
            cout<<i<<" ";
        }
    }
    cout << '\n';
    for (long long i=n;i>=1;--i)
    {
        if (check1(i)) cout << i << " ";
    }
    return 0;
}
