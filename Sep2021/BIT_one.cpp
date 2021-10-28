/* Range sum query */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
ll ar[100005];
ll bit[100005];

void update(ll pt,ll n,ll inc)
{
     while(pt<=n)
     {
         bit[pt]+=inc;
         pt+=(pt&(-pt));
     }
}

ll query(ll l)
{
    ll su = 0;
    while (l>0)
    {
        su+=bit[l];
        l = l-(l&(-l));
    }
    return su;
}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        update(i,n,ar[i]);
    }
    
    ll qu;
    cin>>qu;
    while(qu--)
    {
        ll ty;
        cin>>ty;
        if(ty == 1)
        {
            ll pt,inc;
            cin>>pt>>inc;
            update(pt,n,inc);
        }
        else{
            ll lef,rig;
            cin>>lef>>rig;
            cout<<query(rig)-query(lef-1)<<"\n";
        }
    }
}


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
ll ar[100005];
ll bit[100005];

void update(ll pt,ll n,ll inc)
{
     while(pt<=n)
     {
         bit[pt] = max(bit[pt],inc);
         pt+=(pt&(-pt));
     }
}

ll query(ll l)
{
    ll ans = 0;
    while (l>0)
    {
        ans = max(ans,bit[l]);
        l = l-(l&(-l));
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        update(i,n,ar[i]);
    }
    ll qu;
    cin>>qu;
    while(qu--)
    {
        ll ty;
        cin>>ty;
        if(ty == 1)
        {
            ll pt,inc;
            cin>>pt>>inc;
            update(pt,n,inc);
        }
        else{
            ll x;
            cin>>x;
            cout<<query(x)<<"\n";
        }
    }
}