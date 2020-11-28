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
      ll n;
      cin>>n;
      for(int i=n/2;i>=1;i--)
      {
          cout<<i<<" ";
      }
      for(int i=n;i>(n/2);i--)
      {
          cout<<i<<" ";
      }
      cout<<"\n";
    }
}