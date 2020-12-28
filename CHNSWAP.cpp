#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
ll find_roots(ll x)
{
    long double p = x;
    ll r = (ll)((-1.0+(sqrt(1+4*p)))/2.0);
    return r;
}
ll nCr(ll n)
{
    if(n<2)
    {
        return 0;
    }
    else{
        return (n*(n-1))/2;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll su = (n*(n+1))/2;
        ll half = su/2;
        ll ans = 0;
        if(su%2 ==1)
        {
            cout<<0<<"\n";
            continue;
        }
        else
        {
           ll x = find_roots(su);
           ans+=(n-x);
           ll s1 = (x*(x+1))/2;
           ll s2 = su-s1;
           if(s1 == s2)
           {
               ans+=(nCr(x)+nCr(n-x));
           }
           cout<<ans<<"\n";
        }
    }
}