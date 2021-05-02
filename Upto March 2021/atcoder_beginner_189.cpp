#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
vector<ll> check(vector<ll> p,ll n,ll su)
{
    vector<ll> re;
    multiset<ll> m;
    for(auto it:p)
    {
        m.insert(it);
    }
    for(int i=0;i<n;i++)
    {
        auto pt = (--m.end());
        ll v1 = *pt;
        ll v2 = su-v1;
        auto jx = m.find(v2);
        if(jx == m.end())
        {
            return {};
        }
        re.push_back(v1);
        re.push_back(v2);
        su = max(v1,v2);
        m.erase(pt);
        m.erase(jx);
    }
    return re;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> ar(n*2);
        for(int i=0;i<n*2;i++)
        {
            cin>>ar[i];
        }
        sort(ar.begin(),ar.end());
        ll fl = 0;
        for(int i=0;i<2*n-1;i++)
        {
           ll su = ar[i]+ar[(2*n)-1];
           vector<ll> res = check(ar,n,su);
           if(res.size()>0)
           {
               cout<<"YES\n";
               cout<<su<<"\n";
               fl = 1;
               break;
           }
        }
        if(fl == 0)
        {
            cout<<"NO\n";
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                cout<<res[2*i]<<" "<<res[2*i+1]<<"\n";
            }
            cout<<"\n";
        }
    }
}