/* Snake and Ladder problems using BFS (Single source shortest paths)
Given a 6*6 grid , we have certain points on the board where there is either a ladder to go to a point 
or snake which has negative distance to bring back to a point.
*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// vector<ll> adj[100005];
// void addedge(ll a,ll b)
// {
//     adj[a].push_back(b);
// }

// ll dist[100005];
// void bfs(ll src,ll dest)
// {
//     queue<ll> q;
//     q.push(src);
    
//    for(int i=0;i<100005;i++)
//     {
//       dist[i] = INT_MAX;
//     }
//     dist[src] = 0;
//     while(!q.empty())
//     {
//         ll ff = q.front();
//         q.pop();
//         for(auto it : adj[ff])
//         {
//              if(dist[it] == INT_MAX)
//              {
//                  q.push(it);
//                  dist[it] = min(dist[it],dist[ff]+1);
//              }
//         }
//     }
//     for(int i=0;i<=36;i++)
//     {
//         cout<<"Node "<<i<<"from src has distance"<<" "<<dist[i]<<"\n";
//     }
//     cout<<"\n";
// }

// int main()
// {
//     ll board[50] = {0};
//     board[2] = 13;
//     board[5] = 2;
//     board[9] = 18;
//     board[18] = 11;
//     board[17] = -13;
//     board[20] = -14;
//     board[24] = -8;
//     board[25] = 10;
//     board[32] = -2;
//     board[34] = -22;
   
//    for(int i=0;i<=36;i++)
//    {
//        for(int j=1;j<=6;j++)
//        {
//            ll vv = (i+j);
//            vv+=board[vv];
//            if(vv<=36)
//            {
//                cout<<i<<" "<<vv<<"\n";
//                addedge(i,vv);
//            }
//        }
//    }
//    bfs(0,36);
// }

/* Connected components using DFS */
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// vector<ll> adj[100005];
// void addedge(ll a,ll b)
// {
//     adj[a].push_back(b);
//     adj[b].push_back(a);
// }

// void dfs(bool *vis,ll node)
// {
//      cout<<node<<" ";
//      vis[node] = true;
//      for(auto pt : adj[node])
//      {
//          if(!vis[pt])
//          {
//              dfs(vis,pt);
//          }
//      }
// }

// int main()
// {
//    ll n;
//    cin>>n;
//    ll m;
//    cin>>m;
//    bool vis[n+2]={false};
//    for(int i=0;i<m;i++)
//    {
//        ll a,b;
//        cin>>a>>b;
//        addedge(a,b);
//    }
//    ll cnt = 0;
//    for(int i=0;i<=n;i++)
//    {
//        if(!vis[i])
//        {
//            cout<<"Connected component"<<" "<<cnt+1<<"--->";
//            dfs(vis,i);
//            ++cnt;
//        }
//    }
// }


/* Journey to the Moon (Hacker rank)
The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example



There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID's of two astronauts from the same country
Returns
- int: the number of valid pairs

Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID's of two who share the same nationality.

Constraints : 
1<=n<=10^5
1<=p<=10^4

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

vector<ll> res[100005];
vector<ll> adj[100005];

void dfs(bool *vis,ll cnt,ll node)
{
    vis[node] = true;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            res[cnt].push_back(it);
            dfs(vis,cnt,it);
        }
    }
}

ll calcNcR(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0) 
    {
        while (r) 
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
 
    else
        p = 1;
 
    return p;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll x,y;
    bool vis[100005] = {false};
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    ll cc = 1;
    for(int i=0;i<=n;i++)
    {
        if(!vis[i])
        {
            res[cc].push_back(i);
            dfs(vis,cc,i);
            cc++;
        }
    }
    
    vector<ll> v;
    for(int j=1;j<=cc;j++)
    {
        v.push_back(res[j].size());
    }
    
    ll tot = calcNcR(n,2);
    ll su = 0;
    for(int i=0;i<cc-1;i++)
    {
        if(v[i]>=2)
        {
          su+=calcNcR(v[i],2);
        }
    }
    cout<<tot-su<<"\n";
}



/*
You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format
A single integer N, denoting the size of chess board.

Constraints
1 ≤ N < 15

Output Format
A single integer denoting the count of solutions.

Sample Input
4
Sample Output
2
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
ll cnt = 0;

bool isvalid(ll ar[][20],ll i,ll j,ll n)
{
    //check for the columns
    for(int row=0;row<i;row++)
    {
        if(ar[row][j] ==1)
        {
            return false;
        }
    }
    
    //left diagonals 
    
    ll x = i,y=j;
    while(x>=0 && y>=0)
    {
        if(ar[x][y] == 1)
        {
            return false;
        }
        --x;
        --y;
    }
    
    // right diagonals
    
    x=i,y=j;
    while(x>=0 && y<n)
    {
        if(ar[x][y] == 1)
        {
            return false;
        }
        --x;
        ++y;
    }
    
    return true;
}

bool print_path(ll ar[20][20],ll i,ll n)
{
    if(i==n)
    {
        cnt++;
	    return false;
    }
    
    for(int j=0;j<n;j++)
    {
      if(isvalid(ar,i,j,n))
      {
       //keep the queen at this position
       ar[i][j] = 1;
       bool can_we_keep = print_path(ar,i+1,n);
       if(can_we_keep)
       {
           return true;
       }
       //backtracking takes place
       ar[i][j] = 0;
      }
    }
    return false;
}

int main()
{
	ll n;
	cin>>n;
	ll ar[20][20]={0};
	print_path(ar,0,n);
	cout<<cnt<<"\n";
}