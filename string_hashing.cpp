#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const  ll MOD = 1e9+7;
const int p = 31;
string s;
ll hashes[100005],pw[100005],inv[100005];   
ll add(ll a,ll b,ll MOD)
{
    ll res = (a+b)%MOD;
    if(res<0)
    {
        res+=MOD;
    }
    return res;
}

ll mul(ll a,ll b,ll MOD)
{
    ll res = (a*1LL*b)%MOD;
    if(res<0)
    {
        res+=MOD;
    }
    return res;
}

ll power_calc(ll a,ll b,ll MOD)
{
    ll res = 1;
    while(b>0)
    {
        if(b%2 == 1)
        {
           res = mul(res,a,MOD);
        }
        a = mul(a,a,MOD);
        b = b/2;
    }
    return res;
}

void precalc()
{
    pw[0] = 1;
    for(int i=1;i<10005;i++)
    {
        pw[i] = mul(pw[i-1],p,MOD);
    }
    ll pow_inv = power_calc(p,MOD-2,MOD);
    inv[0] = 1;
    for(int i=1;i<100005;i++)
    {
        inv[i] = mul(inv[i-1],pow_inv,MOD);
    }
}

void build()
{
    ll n = s.size();
    for(int i=0;i<n;i++)
    {
        hashes[i] = add((i==0)? 0 : hashes[i-1] , mul(pw[i],s[i]-'a'+1,MOD),MOD);
    }
}

ll gethash(ll l,ll r)
{
    if(l == 0)
    {
        return hashes[r]%MOD;
    }
    else{
        ll ans = ((hashes[r]-hashes[l-1]+MOD))%MOD;
        return ans;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
      cin>>s;
      precalc();
      build();
      ll cnt = 0;
      ll n = s.size();
      for(int i=0;i<n;i++)
      {
          cout<<hashes[i]<<" ";
      }
      cout<<"\n";
      for(int i=1;i<n-1;i+=2)
      {
          ll ind1 = (i/2);
          ll ind2 = (i+n)/2;
          ll val1 = (gethash(0,ind1)*pw[ind1+1])%MOD;
          ll val2 = gethash(ind1+1,i);
          ll val3 = (gethash(i+1,ind2)*pw[ind2-i])%MOD;
          ll val4 = gethash(ind2+1,n-1);
          if(val1 == val2 && val3 == val4)
          {
              ++cnt;
          } 
      }
      cout<<cnt<<"\n";
    }
}