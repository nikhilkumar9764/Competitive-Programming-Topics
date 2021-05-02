#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        ll ans =1;
        while(a%2 == 0)
        {
            ans = ans*2;
            a = a/2;
        }
        while(b%2 == 0)
        {
            ans = ans*2;
            b = b/2;
        }
        if(ans>=n)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}