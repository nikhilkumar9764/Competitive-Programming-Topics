/*
Educational DP Contest (atcoder) - Problem A . Frogs-1
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll ar[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    vector<ll> dp(n+5,0);
    dp[0] = 0;
    dp[1] = abs(ar[1]-ar[0]);
    for(int i=2;i<=n-1;i++)
    {
        dp[i] = min(dp[i-1]+abs(ar[i]-ar[i-1]) , dp[i-2]+abs(ar[i]-ar[i-2]));
    }
    cout<<dp[n-1]<<"\n";
}
*/

/*
Educational DP Contest (atcoder) - Problem B . Frogs-2
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n,k;
    cin>>n>>k;
    ll ar[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    vector<ll> dp(n+5,INT_MAX);
    dp[0] = 0;
    dp[1] = abs(ar[1]-ar[0]);
    for(int i=2;i<=n-1;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if((i-j)>=0)
            {
              ll val = dp[i-j] + abs(ar[i]-ar[i-j]);
              dp[i] = min(dp[i],val);
            }
        }
    }
    cout<<dp[n-1]<<"\n";
}
*/

/*
Educational DP contest - Problem C. Vacation

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll dp[n][3];
    ll p,q,r;
    cin>>p>>q>>r;
    dp[0][0] = p;
    dp[0][1] = q;
    dp[0][2] = r;
    ll x,y,z;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y>>z;
        dp[i][0] = x+max(dp[i-1][1] ,dp[i-1][2]);
        dp[i][1] = y+max(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = z+max(dp[i-1][0] , dp[i-1][1]); 
    }
    ll val = max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    cout<<val<<"\n";
}
*/ 

/*
Educational DP contest - Problem D .Knapsack 1

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n,tot_sum;
    cin>>n>>tot_sum;
    ll wt[n],val[n];
    for(int i=0;i<(2*n);i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }
    ll dp[n+1][tot_sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=tot_sum+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] =0;
            }
            else if(j<wt[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }
    cout<<dp[n][tot_sum]<<"\n";
} */

/*Educational DP contest - Problem E .Knapsack 2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define inf 1e18
int main()
{
    ll n,w;
    cin>>n>>w;
    ll wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }
    ll dp1[n*1000+5],dp2[n*1000+5];
    for(int i=0;i<(n*1000)+2;i++)
    {
        dp1[i] = inf;
        dp2[i] = inf;
    }
    dp1[0] = 0;
    dp1[val[0]] = wt[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=(n*1000);j++)
        {
            if(j<val[i])
            {
                dp2[j] = dp1[j];
            }
            else{
                dp2[j] = min({dp1[j],wt[i]+dp1[j-val[i]]});
            }
        }
        for(int i=0;i<=(n*1000);i++)
        {
            dp1[i]=dp2[i];
            dp2[i] = inf;
        }
    }
    ll res=0;
    for(int i=0;i<=(n*1000);i++)
    {
        if(dp1[i]<=w)
        {
            res = i;
        }
    }
    cout<<res<<"\n";
} */

/*Educational DP contest - Problem F .LCS

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define inf 1e18
int main()
{
    string s,t;
    cin>>s>>t;
    ll l1 = s.size();
    ll l2 = t.size();
    ll dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(s[i-1] == t[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    ll len = dp[l1][l2];
    int i = l1,j=l2;
    char st[len+1];
    st[len] = '\0';
    while(i>0 && j>0)
    {
        if(s[i-1] == t[j-1])
        {
            st[len-1] = s[i-1];
            --i;
            --j;
            --len;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            --i;
        }
        else{
            --j;
        }
    }
    cout<<st<<"\n";
} */

/* 
Educational DP contest - Problem G . Longest Path 
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define MAX (ll)  (1e5+5)
bool visited[MAX];
vector<ll> edges[MAX];
ll dist[MAX];
ll in_deg[MAX];

void dfs(ll a)
{
    assert(!visited[a]);
    visited[a] = true;
    for(auto i:edges[a])
    {
        dist[i] = max(dist[i],dist[a]+1);
        --in_deg[i];
        if(in_deg[i] == 0)
        {
            dfs(i);
        }
    }
}
int main()
{
   ll n,m;
   cin>>n>>m;
   ll a,b;
   while(m--)
   {
       cin>>a>>b;
       edges[a].push_back(b);
       ++in_deg[b];
   }
   for(int i=1;i<=n;i++)
   {
       if(!visited[i] && in_deg[i] == 0)
       {
           dfs(i);
       }
   }
   ll ans = 0;
   for(int i=1;i<=n;i++)
   {
       ans = max(ans,dist[i]);
   }
   cout<<ans<<"\n";
}
*/