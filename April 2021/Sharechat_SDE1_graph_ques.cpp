// 8 2 --> No of employees,2 (skill,salary)
// 1. 3 47
// 2. 6 13
// 3. 4 47
// 4. 7 39
// 5. 8 24
// 6. 7 23 
// 7. 7 35 
// 8. 4 50 
// 3 2 --> No of groups,2
// 5 7
// 6 8 
// 5 6
// 240 ---> Budget

// Given N employees with (skill,salary) u,v and you are given a budget to select employees with maximum skill
// Some groups are also given and if you select one person from a group , you have to select the entire group
// Print the maximum skill you can get keeping budget in mind


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
vector<pair<ll,ll>> vp;
vector<ll> adj[100005];
ll sf[100005];
vector<bool> visited(100005);

void dfs_skill(ll x,ll &s1,ll &s2,ll st)
{
    visited[x] = true;
    s1+=vp[x-1].first;
    s2+=vp[x-1].second;
    sf[x] = st;
     for(int i=0;i<adj[x].size();i++)
     {
        if(!visited[adj[x][i]])
        {
            dfs_skill(adj[x][i],s1,s2,st);
        }
     }
}

int main()
{
	ll num,tx;
	cin>>num>>tx;
	ll x,y;
	for(int i=0;i<num;i++)
	{
	    cin>>x>>y;
	    vp.push_back({x,y});
	}
     
	ll q,xx;
	cin>>q>>xx;
	ll fi,ss;
	while(q--)
	{
	    cin>>fi>>ss;
	    adj[fi].push_back(ss);
	    adj[ss].push_back(fi);
	}
	ll bud;
	cin>>bud;
	vector<pair<ll,ll>> res;
	ll comp = 0;
	for(ll i=1;i<=num;i++)
	{
	   if(!visited[i])
	   {
	     ll vv = 0,vt = 0;
	     dfs_skill(i,vv,vt,i);
	     res.push_back({vv,vt});
	     ++comp;
	   }
	}
	for(int p=comp+1;p<=num;p++)
	{
	    res.push_back({res[sf[p]-1].first,res[sf[p]-1].second});
	}
	
	ll knap[num+1][bud+1];
    for(int i=0;i<=num;i++)
    {
        for(int j=0;j<=bud;j++)
        {
            if(i ==0 || j==0)
            {
                knap[i][j] = 0;
            }
            else if(j<res[i-1].second)
            {
                knap[i][j] = knap[i-1][j];
            }
            else 
            {
                knap[i][j] = max(knap[i-1][j],res[i-1].first+knap[i-1][j-res[i-1].second]);
            }
        }
    }
    cout<<knap[num][bud]<<"\n";
}


