
/* Problem J . Rectangle Cutting 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll r;
        cin>>r;
        ll ar1[r];
        for(int i=0;i<r;i++)
        {
            cin>>ar1[i];
        }
        ll m;
        cin>>m;
        ll ar2[m];
        for(int i=0;i<m;i++)
        {
            cin>>ar2[i];
        }
        ll pr1[r] ,pr2[m];
        pr1[0] = ar1[0];
        pr2[0] = ar2[0];
        for(int i=1;i<r;i++)
        {
            pr1[i]= ar1[i]+pr1[i-1];
        }
        for(int i=1;i<m;i++)
        {
            pr2[i]=ar2[i]+pr2[i-1];
        }
        ll m1 = *max_element(pr1,pr1+r);
        ll m2 = *max_element(pr2,pr2+m);
        ll ans = 0;
        ll fi =m1+m2;
        ans = max({ans,m1,m2,fi});
        cout<<ans<<"\n";
    }
}*/

/* Boredom CF Round 455 */ 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
vector<ll> vec(100005);
int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        vec[ar[i]]++;
    }
    ll el = *(max_element(ar,ar+n));
    vector<ll> dp(el+1);
    dp[0] = 0;
    dp[1] = vec[1];
    for(int i=2;i<=el;i++)
    {
        dp[i] = max(dp[i-1] , dp[i-2]+vec[i]*i);
    }
    cout<<dp[el]<<"\n";
}