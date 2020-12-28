#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define inf 1e18
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll n,k;
       cin>>n>>k;
       ll x,y;
       vector<pair<ll,ll>>vp; 
       for(int i=0;i<n;i++)
       {
           cin>>x>>y;
           vp.push_back(make_pair(x,y));
       }
       ll fl = 0;
       for(int i=0;i<n;i++)
       {
           fl = 0;
           for(int j=0;j<n;j++)
           {
                ll dif = abs(vp[i].first-vp[j].first) + abs(vp[i].second-vp[j].second);
                if(dif>k)
                {
                    fl = 1;
                    break;
                }
           }
           if(fl == 0)
           {
               cout<<1<<"\n";
               break;
           }
       }
       if(fl)
       {
       cout<<-1<<"\n";
       }
       else{
           continue;
       }
       vp.clear();
    }
}