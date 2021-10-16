// Question : Max query-1 Coding Blocks (Segment Tree used)

You are given an array A of N elements and Q queries. Each query consists of 3 integers L R K. For each query, you have to find the number of elements Ax1, Ax2,….,Axj>=K, where L<=x1, x2,…xj<=R.

Input Format
First line contains an integer N, denoting the number of elements in the array A. Next line contains N integers denoting the elements of the array. Next line contains a single integer Q, denoting the number of queries. Next Q lines contains Q queries, consisting of 3 integers each, L R K.

Constraints
1<=N,Q<=10^5
|Ai|, |K|<=10^9
1<=L, R<=N

Output Format
Print Q lines, where ith line contains the answer to the ith query.

Sample Input
5
1 2 3 4 5
5
1 4 1
1 5 2
1 5 3
1 5 4
1 5 5
Sample Output
4
4
3
2
1


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

void build_tree(vector<vector<ll>> &tree,ll *arr,ll ss,ll se,ll node)
{
    if(ss == se)
    {
       tree[node].push_back(arr[ss]);
       return;
    }
    ll mid = (ss+se)/2;
    build_tree(tree,arr,ss,mid,(2*node));
    build_tree(tree,arr,mid+1,se,(2*node)+1);
    merge(tree[2*node].begin(),tree[2*node].end(),tree[2*node+1].begin(),tree[2*node+1].end(),back_inserter(tree[node]));
    return;
}

ll query_tree(vector<vector<ll>> &tree,ll ss,ll se,ll qs,ll qe,ll node,ll k)
{
	if(qs>se || qe<ss)
	{
		return 0;
	}
	
	if(ss>=qs && se<=qe)
	{
	    ll vv = tree[node].end()-lower_bound(tree[node].begin(),tree[node].end(),k);	
	    return vv;
	}
	ll mid = (ss+se)/2;
	ll lef = query_tree(tree,ss,mid,qs,qe,2*node,k);
	ll right = query_tree(tree,mid+1,se,qs,qe,(2*node)+1,k);
	return lef+right;
}

int main()
{
   ll n;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   vector<vector<ll>> tree(4*n+3);
   build_tree(tree,arr,0,n-1,1);
   
  ll m;
  cin>>m;
  while(m--)
  {
      ll l,r,k;
      cin>>l>>r>>k;
      ll ans = query_tree(tree,0,n-1,l-1,r-1,1,k);
      cout<<ans<<"\n";
  }
}
