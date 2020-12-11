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

ll build_sum(string s)
{
    ll n = s.size();
    ll su = 0;
    for(int i=0;i<n;i++)
    {
        su+= add((i==0)? 0 : hashes[i-1] , mul(pw[i],s[i]-'a'+1,MOD),MOD);
    }
    return su;
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
    precalc();
    ll n;
    cin>>n;
    string ar[n];
    vector<pair<ll,ll>> vp;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
     vector<vector<ll>> grps;
    for(int i=0;i<n;i++)
    {
        ll v1 = build_sum(ar[i]);
        vp.push_back(make_pair(v1,i));
    }
    map<ll,vector<ll>> ma;
    for(auto it:vp)
    {
        ma[it.first].push_back(it.second);
    }
    for(auto it:ma)
    {
        if((it.second).size() > 1)
        {
            for(int j=0;j<(it.second).size();j++)
            {
                cout<<it.second[j]<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
}