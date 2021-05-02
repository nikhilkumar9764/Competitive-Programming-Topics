#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
bool visited[10005];
vector<ll> adj[10005];
ll sf[10005];
/*void bfs(ll p)
{
   for(int i=1;i<=10005;i++)
   {
       dist[i] = 1e18;
   }
   queue<ll> q;
   q.push(p);
   dist[p] = 0;
   visited[p] = true;
   while(!q.empty())
   {
       ll curr = q.front();
       cout<<curr<<"-->";
       q.pop();
       for(auto it:adj[curr])
       {
           if(visited[it])
           {
              continue;
           }
           else
           {
               q.push(it);
               visited[it] = true;
               dist[it] = dist[curr]+1;
           }
       }
   }
}*/
void dfs(ll i,ll started_from)
{
    visited[i] = true;
    sf[i] = started_from;
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            dfs(it,started_from);
        }
    }
}
int main()
{
	ll no_nodes,no_ed;
    cin>>no_nodes>>no_ed;
    ll a,b;
    for(int i=0;i<no_ed;i++)
    {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    for(int j=1;j<=no_nodes;j++)
    {
        if(visited[j])
        {
            continue;
        }
        else{
            dfs(j,j);
        }
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll pt1,pt2;
        cin>>pt1>>pt2;
        if(sf[pt1] == sf[pt2])
        {
            // They both have the same starting point so they are connected 
            cout<<"These are connected nodes belonging to the same group\n";
        }
        else{
            cout<<"Both belong to two different groups and are not connected\n";
        }
    }
    
}

