#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const  ll MOD = 1e9+7;
const int p = 31;
ll hashes[100005],pw[100005];   
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
}

void build(string s)
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
    string s;
    cin>>s;
    precalc();
    build(s);
    for(int i=0;i<s.size();i++)
    {
        cout<<hashes[i]<<"\n";
    }
    cout<<"\n";
    ll l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    ll val1 = gethash(l1,r1);
    ll val2 = gethash(l2,r2);
    if(l1 == r1 || (l1<l2 && (val1%MOD * pw[l2-l1]%MOD)% MOD == val2%MOD) || (l2<l1 && (val2%MOD * pw[l1-l2]%MOD)% MOD == val1%MOD) ) // String hashing algorithm comes only with clause of "High probability" . But 2 strings
      // having equal hashes neccessarily need not be equal.
    {
        cout<<val1%MOD * pw[l2-l1]%MOD<<"\n";
        cout<<val2%MOD<<"\n";
        cout<<"The substrings are equal\n";
    }
    else{
        cout<<"The substrings are not equal\n";
    }
}