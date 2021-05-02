#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
ll merge(ll ar[],ll beg,ll mid,ll end)
{
    ll i =beg,j=mid, k = 0;
    ll tmp[end-beg+1];
    ll tot = 0;
    while(i<mid && j<=end)
    {
        if(ar[i]<ar[j])
        {
            tot+=(end-j+1)*ar[i];
            tmp[k++] = ar[i++];
        }
        else{
           tmp[k++] = ar[j++];
        }
    }
    while(i<mid)
    {
       tmp[k++] = ar[i++]; 
    }
    while(j<=end)
    {
       tmp[k++] = ar[j++];
    }
    for(ll p=beg,k=0;p<=end;p++,k++)
    {
        ar[p] = tmp[k];
    }
    return tot;
}
ll merge_sort(ll ar[],ll beg, ll end)
{
    ll cnt = 0;
    if(end>beg)
    {
        ll mid = (beg+end)/2;
        ll f1  = merge_sort(ar,beg,mid);
        ll f2 = merge_sort(ar,mid+1,end);
        ll fin = merge(ar,beg,mid+1,end);
        cnt+=f1+f2+fin;
    }
    return cnt;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll fin_ans = merge_sort(ar,0,n-1);
    cout<<fin_ans<<"\n";
    }
}