#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define MAX (ll) (1e6+4)
vector<ll> prime;
void simple_sieve()
{
     vector<bool> ar(MAX,true);
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(ar[i] == true)
        {
          for(int j=i*2;j<=MAX;j+=i)
          {
            ar[j] = false;
          }
        }
    }
    for(int i=2;i<=MAX;i++)
    {
        if(ar[i] == true)
        {
            prime.push_back(i);
        }
    }
}
void seg_sieve(ll l,ll r)
{
    vector<bool> isprime(r-l+1 , true);
    for(int i=0;prime[i]*prime[i]<=r;i++)
    {
        ll curr = prime[i];
        ll base = (l/curr)*curr;
        if(base<l)
        {
            base+=curr;
        }
        for(int j=base;j<=r;j+=curr)
        {
            isprime[j-l] = false;
        }
       if(base == prime[i])
       {
           isprime[base-l] = true;
       }
    }
    for(int i=0;i<=r-l;i++)
    {
        if(isprime[i])
        {
            cout<<l+i<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    simple_sieve();
    ll t;
    cin>>t;
    while(t--)
    {
         ll l,r;
         cin>>l>>r;
         seg_sieve(l,r);
    }
} 