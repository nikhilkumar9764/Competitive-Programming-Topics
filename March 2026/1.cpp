#include<bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int tax[55]; 

vector<int> find_path(int st,int end,int n)
{
    if(st == end) return {st};
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        for(auto nb:adj[it])
        {
            if(!visited[nb])
            {
                visited[nb] = true;
                parent[nb] = it;
                if(nb == end)
                {
                    int curr = end;
                    vector<int> pt;
                    while(curr!=-1)
                    {
                       pt.push_back(curr);
                       curr=parent[curr];
                    }
                    reverse(pt.begin(),pt.end());
                    return pt;
                }
                q.push(nb);
            }
        }
    }
    return {};
}

int max_savings(vector<int> &path)
{
    int n = path.size();
    vector<int> dp(n);
    if(n==0) return 0;
    if(n==1) return tax[path[0]]/2;

    dp[0] = tax[path[0]]/2;
    dp[1] = max(dp[0],tax[path[1]]/2);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+tax[path[i]]/2);
    }
    for(auto it: dp)
    {
    	cout<<it<<" ";
    }
    cout<<"\n";
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    int no_edges;
    cin>>no_edges;
    int x,y;
    for(int i=0;i<no_edges;i++)
    {
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>tax[i];
    }
    int no_journeys;
    cin>>no_journeys;
    int st,en;
    int res = 0;
    for(int j=0;j<no_journeys;j++)
    {
        cin>>st>>en;
        vector<int> p1 = find_path(st,en,n);
        int bsum = 0;
        for(int k=0;k<p1.size();k++)
        {
            bsum+=tax[p1[k]];
        }
        res+= bsum-max_savings(p1);
    }
    cout<<res<<"\n";
}