#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
ll n,q;
bool check(ll q,ll ap[],ll val)
{
    ll cnt = 1;
    ll prev = 0,i=1;
    while(i<n && cnt<q)
    {
         if(ap[i]-ap[prev]>=val)
         {
             ++cnt;
             prev = i;
         }
         ++i;
    }
    if(cnt >= q)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    
    cin>>n;
    cin>>q;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll low = 1,high = 1e9;
    sort(ar,ar+n);
    while(low<=high)
    {
        ll mid = (low+high)/2;
        if(check(q,ar,mid))
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<high<<"\n";
}