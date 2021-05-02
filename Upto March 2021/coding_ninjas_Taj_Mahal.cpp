#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
        ll n;
        cin>>n;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        ll pr[n];
        for(int i=0;i<n;i++)
        {
          ll ans = 0;
          ll low = 0,hi = 1e9;
          while(low<=hi)
           {
              ll mid = (low+hi)/2;
              if((i+mid*n)>=ar[i])
                {
                   ans = (i+(mid*n));
                   hi = mid-1;
                }
               else
               {
                  low = mid+1;
               }
            }
            pr[i] = ans;
        }
        ll min_el = pr[0];
        ll ind = 1;
        for(int i=1;i<n;i++)
        {
            if(pr[i]<min_el)
            {
                ind = i+1;
                min_el = ar[i];
            }
        }
        cout<<ind<<"\n";
}
