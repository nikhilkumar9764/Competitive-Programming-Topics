#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll tot = n*(n+1)/2;
    if(tot%2 == 1)
    {
       cout<<0<<"\n";
    }
    else{
        tot = tot/2;
        ll dp[n][tot+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=tot;j++)
            {
                dp[i][j] = dp[i-1][j];
                ll left = j-i;
                if(left>=0)
                {
                    dp[i][j]+=(dp[i-1][left]%MOD);
                }
            }
        }
        cout<<dp[n-1][tot]%MOD<<"\n";
    }
}