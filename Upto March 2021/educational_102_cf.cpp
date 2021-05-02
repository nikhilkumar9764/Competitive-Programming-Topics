#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,d;
        cin>>n>>d;
        vector<ll> v1,v2;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        for(int i=0;i<n;i++)
        {
           if(ar[i]<=d)
           {
               v1.push_back(ar[i]);
           }
        }
        sort(v1.begin(),v1.end());
        if(v1.size() == n || v1.size() ==0)
        {
            cout<<"YES\n";
        }
        else{
            if((v1.size()>=2 && v1[0]+v1[1]<=d) || ar[n-1]<=d)
            {
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        v1.clear();
	}
}