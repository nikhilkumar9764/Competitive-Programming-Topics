#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
ll blck;
struct Query
{
    ll l,r;
};
bool comp(Query a,Query b)
{
    if(a.l/blck<b.l/blck)
    {
        return a.l/blck<b.l/blck;
    }
    else if(b.l/blck<a.l/blck)
    {
        return b.l/blck<a.l/blck;
    }
    else
    {
        return a.l<b.l;
    }
}
void queryresults(int ar[],int m,Query q[],int m)
{
    blck = (ll)(sqrt(n));
    sort(q,q+m,comp);
    ll su = 0;
    ll currentlef = 0,currentrig = 0;
    for(int i=0;i<m;i++)
    {
        ll lef = q[i].l;
        ll rig = q[i].r;
        while(currentlef<lef)
        {
            su-=ar[currentlef];
            ++currentlef;
        }
        while(currentlef>lef)
        {
            su+=ar[currentlef-1];
            --currentlef;
        }
        while(currentrig<=rig)
        {
            su+=ar[currentrig];
            ++currentrig;
        }
        while(currentrig>(rig+1))
        {
            su-=ar[currentrig-1];
            --currentrig;
        }
        cout<<"Sum within L and R is : "<<su<<"\n";
    }
}
int main()
{
	ll n;
	cin>>n;
	ll ar[n];
	for(int i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	ll m;
	cin>>m;
	Query q[m];
	for(int i=0;i<m;i++)
	{
	    cin>>q[i].l>>q[i].r;
	}
	queryresults(ar,n,q,m);
}
