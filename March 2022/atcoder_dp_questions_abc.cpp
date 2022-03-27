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