#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
ll fib(ll n,vector<ll> &dp)
{
    if(n==0 || n==1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    ll ans = fib(n-1,dp) + fib(n-2,dp);
    dp[n] = ans;
    return ans;
}
ll partycomb(ll n)
{
    vector<ll> dp(n+1,0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++)
    {
        dp[i] = dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    cout<<fib(n,dp)<<"\n";
    ll num;
    cin>>num;
    ll way = partycomb(num);
    cout<<"No of ways to party are :"<<way<<"\n"; 
}