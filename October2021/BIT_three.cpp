#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)


void update(ll bit[],ll idx,ll inc,ll n)
{
    while(idx<=n)
    {
        bit[idx]+=1;
        idx+=(idx&(-idx));
    }
}

ll query(ll bit[] , ll idx)
{
    ll ans = 0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ans;
}

int main()
{
    ll t;
	cin>>t;
	string str;
	while(t--)
	{
	    getline(cin,str);
		ll n;
		cin>>n;
		ll ar[n];
		ll maxi = -1;
		set<ll> se;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			se.insert(ar[i]);
			
		}
		ll fi = 0;
		ll qq[n];
		map<ll,ll> ma;
		ll cc = 1;
		for(auto it : se)
		{
			ma[it] = cc;
			cc++;
		}

		for(int i=0;i<n;i++)
		{
			ll pos = ma[ar[i]];
			qq[i] = pos;
		}

		for(int i=0;i<n;i++)
		{
			maxi = max(maxi,qq[i]);
		}

		ll bit[maxi+3] = {0};
		for(int i=n-1;i>=0;i--)
		{
		    fi+=query(bit,qq[i]-1);
		    update(bit,qq[i],1,maxi);
		}
		cout<<fi<<"\n";
	}
}