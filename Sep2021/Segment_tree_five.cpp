/*
Given an array of N integers , given M queries of two types 

1 l,r,val : Type 1 query --->Update query : update the array from [l,r] and increment each element in the array by val

2 l,r : Type 2 query ---> Query between [L,R] find the sum of the range A[l] + A[l+1] +A[l+2]+.....+A[r]

1<=N<=10^9 (So update over a range needs to be )
1<=Q<=10^5 (number of queries )
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b%2 == 1)
		{
			res = (res *a)%MOD;
		}
		b>>=1;
		a = (a*a)%MOD;
	}
	return res;
}

ll tree[2000005] , ar[2000005];
ll lazy[2000005];

void build(ll ss,ll se,ll idx)
{
	if(ss == se)
	{
		tree[idx] = ar[ss];
		return;
	}
	ll mid = (ss+se)/2;
	build(ss,mid,2*idx);
	build(mid+1,se,2*idx+1);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}


void lazy_update(ll ss,ll se,ll lef,ll rig,ll idx,ll val)
{
	if(lazy[idx]!=0)
	{
		tree[idx]+=lazy[idx];
		if(ss!=se)
		{
			lazy[2*idx]+=lazy[idx];
			lazy[2*idx+1]+=lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(lef > se || rig < ss)
	{
		return;
	}
	
	if(ss>=lef && se<=rig)
	{
		lazy[idx]+=val;
		if(ss!=se)
		{
			lazy[2*idx]+=val;
			lazy[2*idx+1]+=val;
		}
		return;
	}
	
    ll mid = (ss+se)/2;
    lazy_update(ss,mid,lef,rig,2*idx,val);
	lazy_update(mid+1,se,lef,rig,2*idx+1,val);
	tree[idx] = tree[2*idx] + tree[2*idx+1];
	return;
}

ll query(ll ss,ll se,ll lef,ll rig,ll idx)
{
	if(lazy[idx]!=0)
	{
		tree[idx]+=lazy[idx];
		if(ss!=se)
		{
			lazy[2*idx]+=lazy[idx];
			lazy[2*idx+1]+=lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(lef > se || rig < ss)
	{
		return 0;
	}
	if(ss>=lef && se<=rig)
	{
	    return tree[idx];
	}
    ll mid = (ss+se)/2;
    ll lp = query(ss,mid,lef,rig,2*idx);
	ll rp = query(mid+1,se,lef,rig,2*idx+1);
	return lp+rp;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	build(0,n-1,1);
	while(m--)
	{
	    ll ch,le,ri;
	    cin>>ch>>le>>ri;
	    --le;
	    --ri;
	    if(ch ==  1)
	    {
	        ll vv;
	        cin>>vv;
	        lazy_update(0,n-1,le,ri,1,vv);
	    }
	    else{
	        ll ans = query(0,n-1,le,ri,1);
	        cout<<ans<<"\n";
	    }
	}
}