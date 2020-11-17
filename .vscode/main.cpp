#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> vp;
        ll x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            vp.push_back(x);
        }
        ll pt;
        cin>>pt;
        ll xx = *(lower_bound(vp.begin(),vp.end(),pt));
        cout<<xx<<"\n";
    }
}