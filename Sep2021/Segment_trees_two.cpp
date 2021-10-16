//Query Bits : You are given an n-bit integer (initially 0). There are Q queries. Each query is of following type:
0 L R: Set all the bits from Lth bit to Rth bit to zero.
1 L R: Set all the bits from Lth bit to Rth bit to one.
2 L R: Find the integer formed by the bits in range [L, R]. Answer all the queries of type 2. Indexing is 0-based. See the sample test case for clarity.
Input Format
First line contains two integers, nand q. Next Q lines contains Q queries.
Constraints
1<=n,q<=200000 0<=L,R<n
Output Format
For each query of type 2, print the integer(in decimal) formed by it modulo 109+7.
Sample Input
3 6
1 0 1
2 0 2
0 1 1
2 1 1
1 2 2
2 0 2

Sample Output
6
0
5
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll lazy[200005];
void buildTree(ll *tree,ll ind,ll s,ll e)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[ind] = 0;
		return;
	}

	ll mid = (s+e)/2;
	buildTree(tree,2*ind,s,mid);
	buildTree(tree,2*ind+1,mid+1,e);

	tree[ind] = 0;
	return;
	
}


ll power(ll a,ll b,ll mod = MOD)
{
	ll res = 1;
	while(b)
	{
		if(b%2 == 1)
		{
			res = (res *a)%mod;
		}
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}

void lazy_update(ll *t,ll ss,ll se,ll node)
{
	if(lazy[node]!=-1)
	{
		t[node] = (power(2,(se-ss+1),MOD)-1)*lazy[node];
		if(ss!=se)
		{
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node] = -1;
	}
	
}

void update_range(ll *t,ll ss,ll se,ll l,ll r,ll val,ll node)
{
	   lazy_update(t,ss,se,node);
	   if(ss>r || se<l)
	   {
	     return;
	   }
	   if(ss>=l && se<=r)
	   {
	       	t[node] = (power(2,(se-ss+1),MOD)-1)*val;
	       	if(ss!=se)
        {
            lazy[node*2]=val;
            lazy[node*2+1]=val;
        }
        return;
	   }
	   ll mid=ss+se>>1;
    update_range(t,ss,mid,l,r,val,node*2);
    update_range(t,mid+1,se,l,r,val,node*2+1);
    t[node]=(t[node*2]*power(2,se-mid,MOD)%MOD+t[node*2+1])%MOD;
}

ll query(ll *t,ll ss,ll se,ll l,ll r,ll node)
{
    lazy_update(t,ss,se,node);
	   if(ss>r || se<l)
	   {
	     return 0;
	   }
	   if(ss>=l && se<=r)
	   {
	       return t[node];
	   }
	   ll mid= (ss+se)/2;
    ll p1 = query(t,ss,mid,l,r,(2*node));
    ll p2 = query(t,mid+1,se,l,r,(2*node)+1);
    return (p1* power(2,min(se,r)-mid,MOD)%MOD+p2)%MOD;
}

int main()
{
   ll n,m;
   cin>>n>>m;
   ll t[4*n+2];
   for(int i=0;i<200005;i++)
   {
      lazy[i] = -1;
   }
   buildTree(t,1,0,n-1);
   while(m--)
   {
        int x,l,r;
        cin>>x>>l>>r;
        if(x == 0 || x==1 )
        {
            update_range(t,0,n-1,l,r,x,1);
        }
        else
        {
            ll ans=query(t,0,n-1,l,r,1);
            cout<<ans<<endl;
        }
    }
}
