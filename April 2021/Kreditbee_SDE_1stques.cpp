// Q1 . Range Query Problem : Given an array A of N numbers and Q queries of form (L,R) and only one type of operation is allowed 
// You can increment any number between L,R by one 

// Minimum no of operations required to make bitwise AND between L,R >0

// Method Used : Maintain a prefix sum of bits 

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define mod (ll) (1e9+7)

int main() 
{
    ll n;
    cin>>n;
    ll ar[n];
    ll pre_bit_sum[n][32];
    for(int i=0;i<n;i++)
    {
    	cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<32;j++)
       {
       	  pre_bit_sum[i][j] = 0;
       }
    }
    ll base;
    for(int i=0;i<n;i++)
    {
       base = 1;
       for(int j=0;j<32;j++)
       {
       	   if(i == 0 && (ar[i]&base))
       	   {
       	   	 pre_bit_sum[i][j]+=1;
       	   }
       	   else if(i>0 && (ar[i]&base))
       	   {
       	   	 pre_bit_sum[i][j]= pre_bit_sum[i-1][j]+1;
       	   }
       	   else if(i>0)
       	   {
       	   	  pre_bit_sum[i][j]= pre_bit_sum[i-1][j];
       	   }
       	 base = base*2;
       }
    }
    ll q;
    cin>>q;
    while(q--)
    {
    	ll l,r;
    	cin>>l>>r;
    	ll no_el = (r-l)+1;
    	--l;
    	--r;
    	ll res[32] = {0};
    	for(int i=0;i<32;i++)
    	{
    		if(l==0)
    		{
    			res[i] = pre_bit_sum[r][i];
    		}
    		else if((l-1)>=0)
    		{
    			res[i] = pre_bit_sum[r][i]- pre_bit_sum[l-1][i];
    		}
    		
    	}
    	ll ans = INT_MAX;
    	ll base = 1;
    	for(int i=0;i<32;i++)
    	{ 
    		if(res[i]>0)
    		{
    			 ll pp = (no_el-res[i])*(base);
    			 ans = min(ans,pp);
    		}
    		base = base*2;
    	}
    	cout<<ans<<"\n";
    }
}
