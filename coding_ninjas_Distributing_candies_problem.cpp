/*//Distributing candies Coding Ninjas Problem.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
ll chck(ll ar[],ll n,ll k,ll val)
{
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ll div = ar[i]/val;
        ans+=div;
    }
    if(ans>=k)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        ll ans = -1;
        ll low = 0,hi = ar[n-1];
        while(low<=hi)
        {
            ll mid = (low+hi)/2;
            if(chck(ar,n,k,mid))
            {
                ans = mid;
                low = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}
*/
/*
// Momo's Market Coding Ninjas problem 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    vector<ll> pr;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    pr.push_back(ar[0]);
    for(int i=1;i<n;i++)
    {
       pr.push_back(pr[i-1]+ar[i]);
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll val;
        cin>>val;
        ll ind = lower_bound(pr.begin(),pr.end(),val)-pr.begin();
        if(val<ar[0])
        {
            cout<<0<<" "<<val<<"\n";
        }
        else if(ind == n)
        {
            cout<<n<<" "<<0<<"\n";
        }
        else if(pr[ind] == val)
        {
            cout<<ind+1<<" "<<0<<"\n";
        }
        else
        {
            ll prev = pr[ind-1];
            ll ans = val -prev;
            cout<<ind<<" "<<ans<<"\n";
        }
    }
}
*/  

// Taj Mahal Entry

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll pr[n];
    for(int i=0;i<n;i++)
    {
        pr[i] = ar[i] - i;
    }
    ll ans = -1;
    for(int i=0;i<n;i++)
    {
        if(pr[i] == 0)
        {
            ans = i+1;
            break;
        }
    }
    cout<<ans<<"\n";
}