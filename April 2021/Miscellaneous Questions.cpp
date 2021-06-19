// Given a string of length n , print a string of length n such that each character occurring in the string has
// odd no of occurrences
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
	 ll no_rep = n/27;
	 if(no_rep < 1)
	 { 
	 	ll cnt = 0;
		for(int i=0;i<n;i++)
		{
			cout<<(char)('a'+i);
		}
		cout<<"\n";
	 }
	 else
	 {
	 	ll no_a;
	 	ll cnt = 0;
		if(no_rep%2 == 0 && n%27==0)
		{
			no_a = no_rep*27-1;
		}
		else if(no_rep%2 ==0 && n%27 > 0)
		{
			no_a = no_rep*27+1;
		}
		else
		{
			no_a = no_rep*27;
		}
		ll rem = n-no_a;
		for(int i=0;i<no_a;i++)
		{
			cout<<'a';
		}
		for(int i=0;i<rem;i++)
		{
			cout<<(char)('b'+i);
		}
		cout<<"\n";
	 }
	}
}

/*Given an array of n numbers compute maximum gcd possible of n/2 disjoint pairs 
of the array ie if n = 4 and arr[] = {6,5,25,8}  so [5,25] and [6,8] can be taken 
as 2 pairs and thus answer would be 7 */

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
   ll si = 1<<n;
   vector<ll> ans(si+1,0);
   for(int i=0;i<si;i++)
   {
   	  for(int j=1;j<n;j++)
   	  {
   	  	 if(!(i&(1<<j)))
   	  	 {
   	  	 	for(int p=0;p<j;p++)
   	  	 	{
   	  	 		if(!(i&(1<<p)))
   	  	 		{
   	  	 			ans[i|(1<<j)|(1<<p)] = max(ans[i|(1<<j)|(1<<p)],ans[i]+__gcd(ar[j],ar[p]));
   	  	 		}
   	  	 	}
   	  	 }
   	  }
   }
   cout<<ans[si-1]<<"\n";
}    

// Find the maximum sum of subsequence in an array such that the adjacent elements are not considered
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll dp[2][n];
    dp[0][0] = ar[0];
    dp[1][0] = 0;
    for(int i=1;i<n;i++)
    {
        dp[0][i] = dp[1][i-1]+ar[i];
        dp[1][i] = dp[0][i-1];
    }
    ll an = max(dp[0][n-1],dp[1][n-1]);
    cout<<an<<"\n";
}


/* Given a cost matrix such that there are n houses along the x axis(rows) and k colours(columns) to paint these houses
Find the minimum cost required to paint all the n houses such that no 2 adjacent house use the same 
colour to be painted.
Ex : n,k = [4,6] 
1 5 7 2 3 4
5 8 4 3 6 1 
8 2 9 7 2 3 
1 2 4 9 1 7
*/
// Time complexity : O (n*k)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll cost[n][k];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
             cin>>cost[i][j]; 
        }
    }
    ll dp[n][k];
    ll fi = INT_MAX, se = INT_MAX;
    for(int i=0;i<k;i++)
    {
        if(cost[0][i]<fi)
        {
            se = fi;
            fi = cost[0][i];
        }
        else if(se > cost[0][i])
        {
            se = cost[0][i];
        }
    }
    for(int i=0;i<k;i++)
    {
        dp[0][i] = cost[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(cost[i-1][j] == fi)
            {
                dp[i][j] = cost[i][j] + se;
            }
            else
            {
                dp[i][j] = cost[i][j] + fi;
            }
        }
        fi = INT_MAX,se = INT_MAX;
        for(int p=0;p<k;p++)
        {
           if(dp[i][p]<fi)
           {
              se = fi;
              fi = dp[i][p];
           }
           else if(se > dp[i][p])
           {
             se = dp[i][p];
           }
        }
    }
    ll anp = INT_MAX;
    for(int i=0;i<k;i++)
    {
         anp = min(anp,dp[n-1][i]);
    }
    cout<<anp<<"\n";
}

/* Painting Fence Algorithm . Given n,k

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
   ll n,k;
   cin>>n>>k;
   ll dp[n+1];
   memset(dp,0,sizeof(dp));
   dp[1] = k;
   dp[2] = k*k;
   for(int i=3;i<=n;i++)
   {
   	  dp[i] = ((k-1)*(dp[i-1]+dp[i-2]))%MOD;
   }
   cout<<dp[n]<<"\n";
}