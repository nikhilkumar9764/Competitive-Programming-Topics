/* 0-1 Knapsack Problem
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    ll tot_sum;
    cin>>tot_sum;
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
}
*/ 

 /*Longest Common Subsequence 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    string p,q;
    cin>>p>>q;
    ll len1 = p.size();
    ll len2 = q.size();
    ll dp[len1+1][len2+1];
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i == 0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(p[i-1] == q[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[len1][len2]<<"\n";
}
*/

/* Subset Sum Problem 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll ss[n];
    for(int i=0;i<n;i++)
    {
        cin>>ss[i];
    }
    ll tot;
    cin>>tot;
    bool dp[n+1][tot+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=tot;j++)
        {
            if(i==0 && j>0)
            {
                dp[i][j] = false;
            }
            else if(j==0)
            {
                dp[i][0] = true;
            }
            else{
                if(dp[i-1][j] == true || dp[i-1][j-ss[i-1]] == true)
                {
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
    }

    if(dp[n][tot])
    {
        cout<<"Subset exists with the given sum"<<"\n";
    }
    else{
        cout<<"No such subset exists with the given sum\n";
    }
}
*/

/* Coin changing problem 
Given a set of coins to choose from and a sum to be formed , find the minimum no of 
coins required to form the amount
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll n;
    cin>>n;
    ll ss[n];
    for(int i=0;i<n;i++)
    {
        cin>>ss[i];
    }
    ll tot;
    cin>>tot;
    ll dp[n][tot+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=tot;j++)
        {
            if(j == 0)
            {
                dp[i][0] = 0;
            }
            else if(j<ss[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else if(j>=ss[i] && i == 0)
            {
                dp[i][j] = dp[i][j-ss[i]]+1;
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-ss[i]]+1);
            }
        }
    }
    cout<<dp[n-1][tot]<<"\n";
}
*/ 

