/* Comrades- III 
The human army has proved itself against the mighty aliens by winning the Great War.
But even in times of peace, the army should remain alert and disciplint.

The army has N soldiers. The soldiers are numbered from 1 to N. The army has a superiority hierarchy. Every soldier has one immediate superior. The superior of a superior of a soldier is also a superior to that soldier. So, a soldier may have one or more superiors but only one immediate superior.

As a exercise to determine the efficiency of the army, the following drill has been designed.

You are given a list of orders. Each order is of the form "<Type><space><ID>"
where Type is either 1,2 or 3 and ID is a number S (1<=S<=N) that denotes a soldier.

There are three types of orders:
Type 1:
All the soldiers who have S as one of their superior will wake up.

Type 2:
All the soldiers who have S as one of their superior will go to sleep.

Type 3:
Count and output the number of soldiers who are awake and have S as one of their superior.

NOTE: Among all soldiers there is one soldier who does not have any superior. He is the commander of the whole army.

Input :

The first line contains N, the number of soldiers. The next line contains N space separated integers. The ith integer represents the immediate superior of the ith soldier.
The immediate superior of the commander of the army will be '0'.

The third line contains Q, the number of orders.
Each of the next Q lines contain two integers, the type of order and S.

Output :

For each Type-3 order, output the number of soldiers who are awake and have the given soldier as their superior.

Constraints :

1 <= N <= 100000
1 <= Q <= 100000
1 <= Type <= 3
1 <= S <= N

A soldier cannot be his own superior.

Sample Input
3
2 0 1
3
3 1
2 1
3 1

Sample Output
1
0
Time Limit: 2
Memory Limit: 256
Source Limit:
Explanation
Initially all soldiers are awake. There is only one soldier who has soldier 1 as his superior i.e. soldier 3. So the answer of the first Type 3 order is 1. After the order "2 1", all soldiers who have 1 as one of their superiors (here, only soldier 3) will go to sleep. Therefore, the answer of the next order "3 1" is 0.

*/

#include<bits/stdc++.h>

using namespace std;

#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x, v) memset(x, v, sizeof(x))
#define si(x) (int)x.size()
#define N 100005

vi adj[N];
int tin[N],tout[N];
int timer;

void dfs(int cur,int par)
{
    int i;
    tin[cur] = ++timer;
    for(i=0;i<adj[cur].size();i++)
    {
        int nxt = adj[cur][i];
        if(nxt != par)
        {
            dfs(nxt,cur);
        }
    }
    tout[cur] = timer;
}

struct node
{
    int cnt;
    int lazy;
}t[4*N];

void build(int node,int s,int e)
{
    if(s == e)
    {
        t[node].cnt = 1;
        t[node].lazy = 0;
        return;
    }

    int m = (s+e)/2;
    int c = 2*node;

    build(c,s,m);
    build(c+1,m+1,e);

    t[node].cnt = t[c].cnt + t[c+1].cnt;
}

void update(int node,int s,int e,int x,int y,int v)
{
    if(s > e)
        return;
    int m = (s+e)/2;
    int c = 2*node;

    if(t[node].lazy)
    {
        if(t[node].lazy == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = t[node].lazy;
        }
        t[node].lazy = 0;
    }

    if(s > y || e < x)
        return;

    if(x <= s && e <= y)
    {

        if(v == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = v;
        }
        return;
    }

    update(c,s,m,x,y,v);
    update(c+1,m+1,e,x,y,v);

    t[node].cnt = t[c].cnt + t[c+1].cnt;
}

int query(int node,int s,int e,int x,int y)
{
    if(s > e || s > y || e < x)
        return 0;
    int m = (s+e)/2;
    int c = 2*node;

    if(t[node].lazy)
    {
        if(t[node].lazy == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = t[node].lazy;
        }
        t[node].lazy = 0;
    }

    if(x <= s && e <= y)
    {
        return t[node].cnt;
    }

    return query(c,s,m,x,y) + query(c+1,m+1,e,x,y);
}

int main()
{
    int n,i;
    cin>>n;

    assert(1 <= n && n <= 100000);

    int root = -1;
    for(i=1;i<=n;i++)
    {
        int j;
        cin>>j;

        assert(0 <= j && j <= n);

        if(j == 0)
            root = i;
        else
            adj[j].pb(i);
    }

    dfs(root,0);

	build(1,1,n);
     
    int q;
    cin>>q;

    assert(1 <= q && q <= 100000);

    while(q--)
    {
        int op,u;
        cin>>op>>u;

        assert(1 <= op && op <= 3);
        assert(1 <= u && u <= n);

        if(op <= 2)
        {
            update(1,1,n,tin[u]+1,tout[u],3-op);
        }
        else
        {
            int ans = query(1,1,n,tin[u]+1,tout[u]);
            cout<<ans<<endl;
        }
    }
    return 0;
}