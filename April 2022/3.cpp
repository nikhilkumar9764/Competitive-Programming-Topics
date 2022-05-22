/*Codejam 2022 Round 1B-- (Controlled inflation) -- DP -- Medium tough */
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<":"<<" ";
        ll n,p;
        cin>>n>>p;
        ll el;
        vector<pair<ll,ll>> range(n+1,{1e12,-1e12});
        range[0].first = range[0].second = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++)
            {
                cin>>el;
                range[i+1].first = min(range[i+1].first,el);
                range[i+1].second = max(range[i+1].second,el);
            }
        }
        ll dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = ((range[i].second-range[i].first)+ min(dp[i-1][0]+abs(range[i].second-range[i-1].first),dp[i-1][1]+abs(range[i].second-range[i-1].second)));
            dp[i][1] = ((range[i].second-range[i].first)+ min(dp[i-1][0]+abs(range[i].first-range[i-1].first),dp[i-1][1]+abs(range[i].first-range[i-1].second)));
        }

        cout<<min(dp[n][0],dp[n][1])<<"\n";
    }
}

/* Atcoder DP Begineer Round 251

Takahashi is with N animals. The N animals are called Animal 1, Animal 2, …, Animal N.

Takahashi will perform the following N kinds of action. Each action can be performed any number of (possibly zero) times.

Pay A[1] yen (the currency in Japan) to feed Animals 1 and 2.
Pay A[2] yen to feed Animals 2 and 3.
Pay A[3] yen to feed Animals 3 and 4.
⋯
Pay A[i] yen to feed Animals i and (i+1).
⋯
Pay A[N−2] yen to feed Animals (N−2) and (N−1).
Pay A[N−1] yen to feed Animals (N−1) and N.
Pay A[N] yen to feed Animals N and 1.
Note that the N-th action above feeds "Animals N and 1."

Print the minimum possible total cost to feed every animal at least once.

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
      ll n;
      cin>>n;
      ll ar[n];
      for(int i=0;i<n;i++)
      {
          cin>>ar[i];
      }
      ll dp[n][2];
      dp[0][0] = 1e12;
      dp[0][1] = ar[0];
      for(int i=1;i<n;i++)
      {
          dp[i][0] = dp[i-1][1];
          dp[i][1] = ar[i]+min(dp[i-1][0],dp[i-1][1]);
      }
      
      ll ans1=min(dp[n-1][0] , dp[n-1][1]);
      ll dp[n][2];
      dp[n-1][0] = 1e12;
      dp[n-1][1] = ar[n-1];
      for(int i=0;i<n-1;i++)
      {
          dp[i][0] = dp[i-1][1];
          dp[i][1] = ar[i]+min(dp[(i-1+n)%n][0],dp[(i-1+n)%n][1]);
      }
      ll ans2 = min(dp[n-2][0] , dp[n-2][1]);
      cout<<min(ans1,ans2)<<"\n";
   }
}
