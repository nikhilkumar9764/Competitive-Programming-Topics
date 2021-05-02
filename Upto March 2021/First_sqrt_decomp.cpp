#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
const ll N = 1e5+7;
const ll B = 400;
ll prv[N],nxt[N],len[(N/B)+10],st[(N/B)+10],en[(N/B)+10],ar[N];
ll s[(N/B)+10][B+10];
ll block[B];
map<ll,set<ll>> ma;
ll query(ll lef,ll rig)
{
	ll su = 0;
	for(int i=lef;i<=rig;i++)
	{
		su+=(ar[i]%MOD);
	}
	return su;
}

ll query_over_block(ll lef,ll rig)
{
	ll su = 0;
	for(int i=lef;i<=rig;i++)
	{
		su+=(block[i]%MOD);
	}
	return su;
}

ll query_elements(ll s,ll end,ll k)
{
	ll ans = 0;
	for(int i=s;i<=end;i++)
	{
		if(nxt[i]>k)
		{
			++ans;
		}
	}
	return ans;
}
ll query_block(ll p,ll en,ll k)
{
	ll ans = 0;
	for(int i=p;i<=en;i++)
	{
		ans+=s[i]+len[i]+1 - upper_bound(s[i]+1,s[i]+len[i]+1,k);
	}
	return ans;
}
int main()
{
	ll n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++)
	{
		nxt[i] = n+1;
		if(!ma[ar[i]].empty())
		{
			prv[i]= *ma[ar[i]].rbegin();
			nxt[prv[i]] = i;
 		}
 		ma[ar[i]].insert(i);
	}
	
	for(int i=1;i<=n;i++)
	{
		ll b = i/B;
		block[b]+=ar[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		ll b = i/B;
		if(!len[b])
		{
			st[b] =i;
		}
		en[b] = i;
		s[b][++len[b]] = nxt[i] ;
	}
	for(int i=1;i<=(n/B);i++)
	{
		sort(s[i]+1,s[i]+len[i]+1);
	}
	while(q--)
	{
		ll ch;
		cin>>ch;
		if(ch == 5)
		{
			ll l,r;
			cin>>l>>r;
			ll fi = 0;
			if(l/B ==r/B)
			{
				fi = query_elements(l,r,r);
			}
			else{
				fi = query_elements(l,en[l/B],r)+query_elements(st[r/B],r,r)+query_block((l/B)+1,(r/B)-1,r);
			}
			cout<<fi<<"\n";
		}
		else if(ch == 1)
		{
			sort(ar+1,ar+n+1);
			ll l,r;
			cin>>l>>r;
			ll fi = 0;
			if(l/B ==r/B)
			{
				fi = query(l,r);
			}
			else
			{
				fi = ((query(l,en[l/B])%MOD)+ (query(st[r/B],r)%MOD)+(query_over_block((l/B)+1,(r/B)-1)%MOD))%MOD;
			}
			cout<<fi%MOD<<"\n";
		}
	}
}
