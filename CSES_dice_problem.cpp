/*#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    vector<ll> dp(n+5,0);
    dp[0] = 1;
    dp[1] = 1; 
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if((i-j)>=0)
            {
              dp[i]= (dp[i]%MOD + dp[i-j]%MOD) % MOD;
            }
            else
            {
                break;
            }
        }
    }
    cout<<dp[n]<<"\n";
}
*/

