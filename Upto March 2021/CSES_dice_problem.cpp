/*Problem G. Book shop 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
   int n,x;
   cin>>n>>x; 
   vector<pair<int,int>> vp;
   int p,q;
   int ar[n],pr[n];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }
   for(int i=0;i<n;i++)
   {
       cin>>pr[i];
   }
   for(int i=0;i<n;i++)
   {
       vp.push_back(make_pair(ar[i],pr[i]));
   }
   int dp[n+1][x+1];
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=x;j++)
       {
           if(i== 0)
           {
               dp[i][j] = 0;
           }
           else if(j<vp[i-1].first)
           {
               dp[i][j] = dp[i-1][j];
           }
           else{
               dp[i][j] = max(dp[i-1][j],(vp[i-1].second+dp[i-1][j-vp[i-1].first]));
           }
       }
   }
   cout<<dp[n][x]<<"\n";
}*/

/*Problem H. Array Description 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
   ll n,x;
   cin>>n>>x;
   vector<ll> ar(n+1);
   for(int i=1;i<=n;i++)
   {
       cin>>ar[i];
   }
   ll dp[n+2][x+2];
   memset(dp,0,sizeof(dp));

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=x;j++)
       {
            if(i==1)
            {
                if(ar[i] == 0 || ar[i] == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else{
                if(ar[i] == 0|| ar[i] == j)
                {
                    dp[i][j] =  ((dp[i-1][j-1]+dp[i-1][j])%MOD + (dp[i-1][j+1]))%MOD;
                }
                else{
                    dp[i][j] = 0;
                }
            }
       }
   }
   ll ans = 0;
   for(int i=1;i<=x;i++)
   {
       ans=(ans+dp[n][i])%MOD;
   }
   cout<<ans%MOD<<"\n";
}
*/

/*Problem I. Edit Distance
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
    string s,t;
    cin>>s>>t;
    int fi = s.size();
    int se = t.size();
    int dp[fi+1][se+1];
    for(int i=0;i<=fi;i++)
    {
        for(int j=0;j<=se;j++)
        {
            if(i == 0)
            {
                dp[i][j] = j;
            }
            else if(j == 0)
            {
                dp[i][j] = i;
            }
            else if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        }
    }
    cout<<dp[fi][se]<<"\n";
}*/

/* Problem J. Rectangle Cutting 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
    ll a,b;
    cin>>a>>b;
    vector<vector<ll>> dp(a+1,vector<ll>(b+1,INT_MAX));
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            if(i==j)
            {
                dp[i][j] = 0;
            }
            else{
                // Horizontal cuts
                for(int k=1;k<=i-1;k++)
                {
                    dp[i][j] = min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                }

                // Vertical cuts
                for(int k=1;k<=j-1;k++)
                {
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    cout<<dp[a][b]<<"\n";
}
*/