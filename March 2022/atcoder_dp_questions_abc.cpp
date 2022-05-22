/* ABC 245 Simple DP question -- Choose elements 
(choosing a path exists or not)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main() 
{
     ll n,k;
     cin>>n>>k;
     ll ar[2][n];
     for(int i=0;i<2;i++)
     {
         for(int j=0;j<n;j++)
         {
             cin>>ar[i][j];
         }
     }
     bool dp[2][n];
     for(int i=0;i<2;i++)
     {
         for(int j=0;j<n;j++)
         {
             dp[i][j] = false;
         }
     }
     dp[0][0] = true;
     dp[1][0] = true;
     for(int i=1;i<n;i++)
     {
         for(int j=0;j<2;j++)
         {
            if(dp[0][i-1]==true && abs(ar[0][i-1]-ar[j][i])<=k )
            {
                dp[j][i] = true;
            }
            else if(dp[1][i-1]==true && abs(ar[1][i-1]-ar[j][i])<=k)
            {
                dp[j][i] = true;
            }
         }
     }
     if(dp[0][n-1]==true || dp[1][n-1]==true)
     {
         cout<<"Yes\n";
     }
     else{
         cout<<"No\n";
     }
}

/*Interview Question : 

Given a list of islands say N , one can go from island i to another island j if |i-j| is a power of 2 and also 
the cost of going from one island to another is |c[i]-c[j]| . Calculate the minimum cost of going from island 1 to island N. 

Use DP and solve it in NlogN time 
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
	ll n;
	cin>>n;
	ll ar[n];
	for(int i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	ll dp[n];
	for(int i=0;i<n;i++)
	{
	    dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(int i=0;i<n-1;i++)
	{
	    ll d1 = abs(n-1-i);
	    ll steps = log2(d1);
	    for(int j=0;j<=steps;j++)
	    {
	        ll idx = i+pow(2,j);
	        dp[idx] = min(dp[idx], dp[i]+abs(ar[idx]-ar[i]));
	    }
	}
    ll ans = dp[n-1];
    cout<<ans<<"\n";
}

/* Atcoder Beginner 243 -- C Problem */

