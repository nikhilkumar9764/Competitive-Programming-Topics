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