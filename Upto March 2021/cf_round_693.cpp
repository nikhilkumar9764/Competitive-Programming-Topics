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
		ll n,m;
        cin>>n>>m;
        ll ar[n][m];
        vector<ll> vec;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ar[i][j];
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ll f1 = ar[i][m-1-j];
                ll f2 = ar[n-1-i][j];
                vec.push_back(ar[i][j]);
                vec.push_back(f1);
                vec.push_back(f2);
                sort(vec.begin(),vec.end());
                ans+=(abs(vec[0]-vec[1])+ abs(vec[2]-vec[1]));
                ar[i][j] = vec[1];
                ar[i][m-1-j] = vec[1];
                ar[n-1-i][j] = vec[1];
                vec.clear();
            }
        }
        cout<<ans<<"\n";
        vec.clear();
	}
}