
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
bool visited[10005];
vector<ll> adj[10005];
vector<ll> ans;
void dfs(ll src)
{
    visited[src] = true;
    ans.push_back(src);
    for(auto it:adj[src])
    {
        if(!visited[it])
        {
           dfs(it);
        }
    }
}
int main()
{
	ll no_nodes;
    cin>>no_nodes;
    ll a,b;
    for(int i=0;i<no_nodes-1;i++)
    {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    for(int i=1;i<=10;i++)
    {
    	for(int j=0;j<adj[i].size();j++)
    	{
    		cout<<adj[i][j]<<" ";
    	}
    	cout<<"\n";
    }
    cout<<"\n";
    ll pt;
    cin>>pt;
    dfs(pt);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
bool visited[10005];
vector<ll> adj[10005];
vector<ll> ans;
void printpath()
{
	 cout<<"Path from src to dest is :\n";
      for(auto it:ans)
      {
        	cout<<it<<"-->";
      }
}
void dfs(ll src,ll des)
{
	ans.push_back(src);
	if(src == des)
	{
		printpath();
		return;
	}
	visited[src] = true;
	
	if(adj[src].size()>0)
	{
		for(auto it:adj[src])
		{
			if(!visited[it])
			{
			  dfs(it,des);
			}
		}
	}
	ans.pop_back();
}
int main()
{
	ll no_nodes;
    cin>>no_nodes;
    ll a,b;
    for(int i=0;i<no_nodes-1;i++)
    {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    ll src,des;
    cin>>src>>des;
    dfs(src,des);
}

//
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
bool visited[10005];
vector<ll> adj[10005];
vector<ll> ans;
bool find_path(ll src,ll dest)
{
    if(src == dest)
    {
       return true;
    }
    if(!visited[src])
    {
    	ans.push_back(src);
    }
    visited[src] = true;
    bool found = false;
    for(auto it:adj[src])
    {
    	if(visited[it])
    	{
    		continue;
    	}
        if(find_path(it,dest))
        {
           found = true;
        }
        else{
        	ans.push_back(src);
        	find_path(it,dest);
        }
    }
   
    return found;
}
int main()
{
	ll no_nodes;
    cin>>no_nodes;
    ll a,b;
    for(int i=0;i<no_nodes-1;i++)
    {
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    ll src,des;
    cin>>src>>des;
    if(find_path(src,des))
    {
        cout<<"Path from src to dest is :\n";
        for(auto it:ans)
        {
        	cout<<it<<"-->";
        }
        cout<<des<<"\n";
        cout<<"\n";
    }
    else
    {
        cout<<"There is no path from src to destination\n";
    }
}

