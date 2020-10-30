#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define MAXN (ll) (1e5)
ll pref[MAXN] , ar[MAXN];
ll intersect(ll a,ll b,ll x,ll y)
{
    if(x>b || a>y)
    {
        return 0;
    }
    else{
       ll fi = max(a,x);
       ll se = min(b,y);
       return abs(fi-se);
    }
}
void precompute(ll n)
{
	pref[0] = ar[0];
	for(int i=1;i<n;i++)
	{
	    pref[i] = ar[i] + pref[i-1];
	}
}
int main()
{
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	ll q;
	cin>>q;
	ll blck_size = sqrt(q);
	vector<pair<pair<ll,ll>,ll>> vp;
	ll aux[MAXN] = {0};
	precompute(n);
	for(int i=0;i<q;i++)
	{
	    ll type;
	    cin>>type;
	    if((type == 1 && i%blck_size!=0)||(type == 1 && i==0))
	    {
	        ll l,r;
	        cin>>l>>r;
	        ll ans = pref[r-1] - pref[l-2];
	        for(int i=0;i<vp.size();i++)
	        {
	            ll len = intersect(l,r,vp[i].first.first,vp[i].first.second);
	            ans+= (len+1) * vp[i].second;
	        }
	        cout<<ans<<"\n";
	    }
	    else if(type ==1 && i%blck_size==0)
	    {
	    	ll l,r;
	        cin>>l>>r;
	        for(int i=0;i<n;i++)
	        {
	            aux[i] = 0;
	        }
	        for(int i=0;i<vp.size();i++)
	        {
	            ll lef = vp[i].first.first,rig = vp[i].first.second;
	            aux[lef-1]= aux[lef-1]+ vp[i].second;
	            aux[rig]=aux[rig] - vp[i].second;
	        }
	        for(int i=1;i<n;i++)
	        {
	           aux[i]+=aux[i-1];
	        }
	        for(int i=0;i<n;i++)
	        {
	           ar[i]+=aux[i];
	        }
	        precompute(n);
	        ll ff = pref[r-1]-pref[l-2];
	        cout<<ff<<"\n";
	        vp.clear();
	    }
        else if(type ==2 && i==0 || (type ==2 && i%blck_size!=0))
	    {
	        ll l,r,x;
	        cin>>l>>r>>x;
	        vp.push_back(make_pair(make_pair(l,r),x));
	    }
	    else if(type ==2 && i!=0 && i%blck_size == 0)
	    {
	        ll l,r,x;
	        cin>>l>>r>>x;
	        for(int i=0;i<n;i++)
	        {
	            aux[i] = 0;
	        }
	        for(int i=0;i<vp.size();i++)
	        {
	            ll lef = vp[i].first.first,rig = vp[i].first.second;
	            aux[lef-1]= aux[lef-1]+ vp[i].second;
	            aux[rig]=aux[rig] - vp[i].second;
	        }
	        for(int i=1;i<n;i++)
	        {
	           aux[i]+=aux[i-1];
	        }
	        for(int i=0;i<n;i++)
	        {
	           ar[i]+=aux[i];
	        }
	        precompute(n);
	        vp.clear();
	        vp.push_back(make_pair(make_pair(l,r),x));
	    }
	}
}