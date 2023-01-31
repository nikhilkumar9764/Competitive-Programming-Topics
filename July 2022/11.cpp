/*Leetcode weekly 307 (Minimum no of Hours training to win a competition) */

class Solution {
public:
    string largestPalindromic(string num)
    {
        int cnt[10] = {0};
        for(int i=0;i<num.size();i++)
        {
            cnt[num[i]-'0']++;
        }
        string front = "";
        for(int i=9;i>=0;i--)
        {
            if(i==0 && front.empty())
            {
                continue;
            }
            if(cnt[i]>1)
            {
                while(cnt[i]>1)
                {
                    front+=to_string(i);
                    cnt[i]-=2;
                }
            }
        }
        string fi = front;
        reverse(front.begin(),front.end());
        string rev = front;
        for(int i=9;i>=0;i--)
        {
            if(cnt[i]>0)
            {
                return fi+to_string(i)+rev;
            }
        }
        return fi+rev;
    }
};


/* Corona Problem (Algouniversity)

Corona has affected the country of IslandLand and people need to practice social distancing.
 IslandLand is a country on the X-Axis with M islands floating on water. 
There are N people living in this country.
You have been given the start and end coordinates Li and Ri of all the M islands. 
Suppose the government arranges the people in IslandLand in such a way that all the people have their feet on some island segment.
Your task is to find the largest possible value of the minimum distance between any two people and report it to the government so that the government can ensure social distancing.

Constraints
2≤N≤105
1≤M≤105
0≤Li≤Ri≤1018
INPUT
The first line contains two integers N and M. The next M lines contain two integers Li,Ri denoting the start point and the end point of the island segment.

OUTPUT
Output a single integer indicating the largest possible value of the minimum distance between any two people.

Example
Input:
5 3
0 2
4 7
9 9
Output:
2

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
vector<ll> adj[MAX];
ll intime[MAX] , outtime[MAX];
ll subtree[MAX];
bool vis[MAX];
ll val = 0;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vp;
    ll x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        vp.push_back({x,y});
    }
    sort(vp.begin(),vp.end());
    ll low = 1,hi = 1e18;
    ll min_dist = 0;
    vector<ll> an;
    while(low<=hi)
    {
        ll mid = low+(hi-low)/2;
        ll cnt_people = 0;
        ll prev = 0;
        for(auto it : vp)
        {
            ll lef = it.first;
            ll rig = it.second;
            lef = max(mid+prev,lef);
            ll num = (rig-lef)/mid;
            if(lef<=rig)
            {
                num++;
            }
            if(num>0)
            {
                cnt_people+=num;
                prev = lef+(num-1)*mid;
            }
        }
        if(cnt_people+1>=n)
        {
            an.push_back(mid);
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<an.back()<<"\n";
}

/* Print all shortest paths btw source and destination in an undirected graph 
Given an unweighted graph consisting of N nodes and M bidirectional edges.
Print all nodes that could be part of any shortest path from node 1 to node N in ascending order.
If node N is not reachable from node 1, then print −1.

2≤N≤105
1≤M≤2×105
*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

void find_paths(vector<vector<ll>> &paths,vector<ll> &path,vector<ll> parent[],ll n, ll u)
{
    if(u==-1 || parent[u][0] == -1)
    {
        paths.push_back(path);
        return;
    }
    
    for(auto it: parent[u])
    {
        path.push_back(it);
        find_paths(paths,path,parent,n,it);
        path.pop_back();
    }
}

void bfs(vector<ll> adj[],vector<ll> parent[],ll n,ll src)
{
    queue<ll> q;
    vector<ll> dist(n+3 , INT_MAX);
    q.push(src);
    dist[src] = 0;
    parent[src] = {-1};
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        for(auto v : adj[it])
        {
            if(dist[v] > dist[it]+1)
            {
                dist[v] = dist[it]+1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(it);
            }
            else if(dist[v] == dist[it]+1)
            {
                 parent[v].push_back(it);
            }
        }
    }
}

void print_paths(vector<ll> adj[],ll n,ll src,ll des)
{
    vector<vector<ll>> paths;
    vector<ll> path;
    vector<ll> parent[n+2];
    bfs(adj,parent,n,src);
    
    find_paths(paths,path,parent,n,des);
    set<ll> se;
    
    if(paths.size() == 0)
    {
        cout<<-1<<"\n";
    }
    else{
    for(auto it : paths)
    {
        for(int j=0;j<it.size();j++)
        {
            se.insert(it[j]);
        }
    }
    se.insert(des);
    
    for(auto j : se)
    {
        cout<<j<<" ";
    }
    
    cout<<"\n";
    }
}

int main() 
{
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+2];
    ll x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    print_paths(adj,n,1,n);
}


/* 2nd approach : Apply bfs at node 1 and node N and find distance for all the nodes*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

int main() 
{
    ll n;
    cin>>n;
    ll x,y,ww;
    vector<ll> adj[n+1];
    ll no_edges;
    cin>>no_edges;
    for(int i=0;i<no_edges;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
     
    bool vis[n+1] = {false};
    ll dis[n+1];
    for(int i=1;i<=n;i++)
    {
        dis[i] = INT_MAX;
    }

ll st = 1,en = n;
dis[st] = 0;
queue<int> q;
q.push(st);
vis[st] = true;

  while(!q.empty())
  {
    auto it = q.front();
    q.pop();
    for(auto pt:adj[it])
    {
      if(!vis[pt])
      { 
        vis[pt] = true;
        q.push(pt);
      }
        dis[pt] = min(dis[pt],1+ dis[it]);
    } 
  }
  
 
bool vis2[n+1] = {false};
    ll dis2[n+1];
    for(int i=1;i<=n;i++)
    {
        dis2[i] = INT_MAX;
    }
ll st2 = n,en2 = 1;
dis2[st2] = 0;
queue<int> q1;
q1.push(st2);
vis[st2] = true;

  while(!q1.empty())
  {
    auto it = q1.front();
    q1.pop();
    for(auto pt:adj[it])
    {
      if(!vis2[pt])
      { 
        vis2[pt] = true;
        q1.push(pt);
      }
      dis2[pt] = min(dis2[pt],1+ dis2[it]);
    } 
  }

  
 ll ev = dis[n];
 if(ev == INT_MAX)
 {
     cout<<-1<<"\n";
 }
 else{
     for(int i=1;i<=n;i++)
     {
         if(dis[i]+dis2[i]==ev)
         {
             cout<<i<<" ";
         }
     }
      cout<<"\n";
 }
}







/* Trip to algoland*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

int main() 
{
    ll n,m;
    cin>>n>>m;
    ll fl = 0;
    map<string,string> mm;
    map<pair<string,string>,string> ma;
    string x,y,z;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        mm[x] = y;
        ma[{x,y}] = z;
    }
   
    string src,des;
    cin>>src>>des;
    vector<string> res;
    queue<string> q;
    q.push(src);
    while(!q.empty())
    {
         auto it = q.front();
         q.pop();
         string vv,v1;
         if(mm.find(it)!=mm.end())
         {
         	vv = mm[it];
         }
         else{
         	break;
         }
         if(ma.find({it,vv})!=ma.end())
         {
         	v1 = ma[{it,vv}];
         }
         else{
         	break;
         }
         q.push(vv);
         res.push_back(v1);
         if(vv == des)
         {
             fl = 1;
             break;
         }
    }
    
    if(fl == 0)
    {
        cout<<"Impossible\n";
    }
    else{
        cout<<res.size()<<"\n";
        for(auto i : res)
        {
            cout<<i<<"\n";
        }
    }
}
