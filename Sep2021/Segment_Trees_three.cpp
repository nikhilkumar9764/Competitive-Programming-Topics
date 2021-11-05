/*You are given an n-bit integer (initially 0). There are Q queries. Each query is of following type:

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
Explanation
Initially the integer in binary is "000". After first query, it becomes, 110(=6). Answer to next query comes out to be 6, i.e. "110" in decimal. After 3rd query, it becomes "100". Answer to 4th query is 0,i.e. decimal of "0". After 5th query, it becomes, "101" and thus answer to the last query comes out to be 5, i.e. "101" i decimal.


My Solution : (Lazy propogation used in segment trees)

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll lazy[1000000];
void buildTree(ll *tree,ll ind,ll s,ll e)
{
	if(s>e)
		return;
	if(s==e)
	{
		tree[ind] = 0;
		return;
	}
<<<<<<< HEAD

	ll mid = (s+e)/2;
	buildTree(tree,2*ind,s,mid);
	buildTree(tree,2*ind+1,mid+1,e);

	tree[ind] = 0;
	return;
	
}


ll power(ll a,ll p,ll m = MOD)
{
	ll res=1;
	while(p>0){
		if(p&1)
			res=(res*a)%m;
		a=(a*a)%m;
		p>>=1;
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

=======

	ll mid = (s+e)/2;
	buildTree(tree,2*ind,s,mid);
	buildTree(tree,2*ind+1,mid+1,e);

	tree[ind] = 0;
	return;
	
}


ll power(ll a,ll p,ll m = MOD)
{
	ll res=1;
	while(p>0){
		if(p&1)
			res=(res*a)%m;
		a=(a*a)%m;
		p>>=1;
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

>>>>>>> 4f3c45e70b020e6f332c2d790a11c1cc4ed56794
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
   for(int i=0;i<1000000;i++)
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


/*Accepted solution */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define mod 1000000007
#define inf 1e18
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int tree[10000006],lazy[10000006];
int powmod(int a,int b){
	int ans=1;
	while(b>0){
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}
void build(int index,int s,int e){
	if(s==e){
		tree[index]=0;lazy[index]=-1;return;
	}
	int mid=(s+e)/2;
	build(2*index,s,mid);
	build(2*index+1,mid+1,e);
	tree[index]=0;lazy[index]=-1;
}
void update(int index,int s,int e,int l,int r,int d){
	if(lazy[index]!=-1){
		tree[index]=lazy[index];
		if(s!=e){
			lazy[2*index]=lazy[index];
			lazy[2*index+1]=lazy[index];
		}
	}
	if(s>r || e<l) return;
	if(s>=l && e<=r){
		lazy[index]=d;
		if(s!=e){
			lazy[2*index]=d;
			lazy[2*index+1]=d;
		}
		return;
	}
	int mid=(s+e)/2;
	update(2*index,s,mid,l,r,d);
	update(2*index+1,mid+1,e,l,r,d);
	lazy[index]=-1;
}
int query(int index,int s,int e,int l,int r){
	if(lazy[index]!=-1){
		tree[index]=lazy[index];
		if(s!=e){
			lazy[2*index]=lazy[index];
			lazy[2*index+1]=lazy[index];
		}
	}
	if(s>e) return 0;
	if(s>r || e<l) return 0;
	if(s>=l && e<=r && lazy[index]!=-1){
		if(lazy[index]==0) return 0;
		int res=(powmod(2,(e-s+1))-1)%mod;
		res=(res*powmod(2,(r-e)))%mod;
		return res%mod;
	}
	int mid=(s+e)/2;
	int res1=query(2*index,s,mid,l,r);
	int res2=query(2*index+1,mid+1,e,l,r);
	return (res1+res2)%mod;
}
int32_t main()
{
	int n,q;cin>>n>>q;
	build(1,0,n-1);
	while(q--){
		int d,l,r;cin>>d>>l>>r;
		if(d<=1){
			update(1,0,n-1,l,r,d);
		}
		else cout<<query(1,0,n-1,l,r)<<endl;
	}
}
