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