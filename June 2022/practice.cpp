#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> ar(n,vector<ll>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    
    vector<ll> v1;
    for(int i=0;i<n;i++)
    {
        v1.push_back(ar[i][m-1]);
    }

    while(q--)
    {
        ll idx;
        cin>>idx;
        auto it = upper_bound(v1.begin(),v1.end(),idx)-v1.begin();
        --it;
        ll x_idx = it;
        auto it2 = upper_bound(ar[x_idx].begin(),ar[x_idx].end(),idx)-ar[x_idx].begin();
        --it2;
        cout<<x_idx<<" "<<it2<<"\n";
    }

}

/* There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction
 you are going, and you want to drive from point 1 to point n to make money by picking up passengers. 
You cannot change the direction of the taxi.
The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith 
passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.
For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.
Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.

Note: You may drop off a passenger and pick up a different passenger at the same point.

Example 1:

Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.
Example 2:

Input: n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
Output: 20
Explanation: We will pick up the following passengers:
- Drive passenger 1 from point 3 to point 10 for a profit of 10 - 3 + 2 = 9 dollars.
- Drive passenger 2 from point 10 to point 12 for a profit of 12 - 10 + 3 = 5 dollars.
- Drive passenger 5 from point 13 to point 18 for a profit of 18 - 13 + 1 = 6 dollars.
We earn 9 + 5 + 6 = 20 dollars in total.
 
Constraints:

1 <= n <= 10^5
1 <= rides.length <= 3*10^4
rides[i].length == 3
1 <= starti < endi <= n
1 <= tipi <= 10^5
*/
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        };
        sort(rides.begin(), rides.end(), cmp);
        
        vector<long long> dp(n+1, 0);
        
        long long mx = 0;
        long long last = 0;
        for(int i=0; i<rides.size(); ++i) {
            vector<int> r = rides[i];
            while(last < r[1]) {
                dp[last] = mx;
                last++;
            }
            dp[r[1]] = max(mx, dp[r[0]] + r[2] + r[1] - r[0]);
            mx = max(mx, dp[r[1]]);
        }
        return mx;
    }
};

/* Geekland Colosseum */

3 6
0 1
0 2
0 2
0 1
0 1
0 1
0 2
0 2

/* GFG Amazon Alexa-1 Hiring challenge 
Euler path question : 
https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems/#
Road blockage question 
*/
vector<int> adj[100005];
  bool vis[100005];
   vector<int> euler;
   map<int,int> st,en;
   int level[100005];
   
    void dfs(int node, int lev=1)
    {
        vis[node] = true;
        level[node] = lev;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,lev+1);
            }
            euler.push_back(node);
        }
    }
    
    vector<int> solve(int N, int Q, vector<vector<int> > &Edge,
                      vector<vector<int> > &query) 
                      {
        
        for(auto p : Edge)
        {
            int x1 = p[0] , y1 = p[1];
            adj[x1].push_back(y1);
            adj[y1].push_back(x1);
        }
        euler.push_back(0);
        dfs(0);
        for(int j=0;j<euler.size();j++)
        {
            if(!st[euler[j]])
            {
                st[euler[j]] = j;
            }
            en[euler[j]] = j;
        }
        
        int sz = euler.size();
        int pref[sz]={0};
        pref[0] = level[euler[0]];
        for(int j=1;j<sz;j++)
        {
            pref[j] = max(pref[j-1] , level[euler[j]]);
        }
        
        int suf[sz]={0};
        suf[sz-1] = level[euler[sz-1]];
        for(int j=sz-2;j>=0;j--)
        {
            suf[j] = max(suf[j+1] , level[euler[j]]);
        }
        
        vector<int> ans;
        for(auto it : query)
        {
            int v1 = it[0] ,v2=it[1];
            int x = max(v1,v2);
            int fi = st[x],se = en[x];
            int aa = max(pref[fi-1],suf[se+1]);
            ans.push_back(aa-1);
        }
        return ans;
    }

/* GFG Amazon Alexa 2 (Maximum multiples)

*/
long long maximumMultiple(int N, int A[]) 
    {
        vector<long long > pos,neg,zero;
        for(int i=0;i<N;i++)
        {
            if(A[i]<0)
            {
                neg.push_back(A[i]);
            }
            else if(A[i] == 0)
            {
                zero.push_back(A[i]);
            }
            else{
                pos.push_back(A[i]);
            }
        }
        
        sort(A,A+N);
        if(pos.size() == neg.size() && pos.size() == N/2)
        {
            reverse(A,A+(N/2));
        }
        long long  ans = -1e18;
        for(int j=0;j<N;j++)
        {
            long long vv = A[j]*A[N-1-j];
            ans = max(ans,vv);
        }
        return ans;
    }

/* GFG Amazon Alexa-2 Hiring Challenge 
(https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-2-for-amazon-alexa/problems/) 
  */

  class Solution {
  public:
    void dfs(int node,vector<int> adj[],bool vis[],string &col,set<char> &se)
    {
        vis[node] = true;
        for(auto it: adj[node])
        {
            if(!vis[it] && col[it]==col[node])
            {
                dfs(it,adj,vis,col,se);
            }
            else{
                se.insert(col[it]);
            }
        }
    }
  
    vector<string> solve(int N, int M, int Q, string col,
                         vector<vector<int> > &Edge, vector<string> &query) 
                         {
               int dp[26][26][26];
               memset(dp,sizeof(dp),0);
               vector<int> adj[N+2];
               bool vis[N+2] = {false};
               for(auto it : Edge)
               {
                   auto fi = it[0],se =it[1];
                   adj[fi].push_back(se);
                   adj[se].push_back(fi);
               }
               
               for(int i=0;i<N;i++)
               {
                   if(!vis[i])
                   {
                       set<char> se;
                       dfs(i,adj,vis,col,se);
                       for(auto it1 : se)
                       {
                           for(auto it2:se)
                           {
                               int x1 = it1-'a';
                               int x2 = it2-'a';
                               dp[col[i]-'a'][x1][x2] = 1;
                           }
                       }
                   }
               }
               
               vector<string> res;
               for(auto i : query)
               {
                   int a = i[0]-'a';
                   int b = i[1]-'a',c=i[2]-'a';
                   if(dp[a][b][c]==1 || dp[a][c][b]==1 || dp[b][a][c]==1 || dp[b][c][a]==1 || dp[c][a][b]==1
                   || dp[c][b][a]==1)
                   {
                       res.push_back("YES");
                   }
                   else{
                       res.push_back("NO");
                   }
               }
            return res;   
    }
};