// Given a string of length n , print a string of length n such that each character occurring in the string has
// odd no of occurrences
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
	 ll no_rep = n/27;
	 if(no_rep < 1)
	 { 
	 	ll cnt = 0;
		for(int i=0;i<n;i++)
		{
			cout<<(char)('a'+i);
		}
		cout<<"\n";
	 }
	 else
	 {
	 	ll no_a;
	 	ll cnt = 0;
		if(no_rep%2 == 0 && n%27==0)
		{
			no_a = no_rep*27-1;
		}
		else if(no_rep%2 ==0 && n%27 > 0)
		{
			no_a = no_rep*27+1;
		}
		else
		{
			no_a = no_rep*27;
		}
		ll rem = n-no_a;
		for(int i=0;i<no_a;i++)
		{
			cout<<'a';
		}
		for(int i=0;i<rem;i++)
		{
			cout<<(char)('b'+i);
		}
		cout<<"\n";
	 }
	}
}

/*Given an array of n numbers compute maximum gcd possible of n/2 disjoint pairs 
of the array ie if n = 4 and arr[] = {6,5,25,8}  so [5,25] and [6,8] can be taken 
as 2 pairs and thus answer would be 7 */

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
   ll si = 1<<n;
   vector<ll> ans(si+1,0);
   for(int i=0;i<si;i++)
   {
   	  for(int j=1;j<n;j++)
   	  {
   	  	 if(!(i&(1<<j)))
   	  	 {
   	  	 	for(int p=0;p<j;p++)
   	  	 	{
   	  	 		if(!(i&(1<<p)))
   	  	 		{
   	  	 			ans[i|(1<<j)|(1<<p)] = max(ans[i|(1<<j)|(1<<p)],ans[i]+__gcd(ar[j],ar[p]));
   	  	 		}
   	  	 	}
   	  	 }
   	  }
   }
   cout<<ans[si-1]<<"\n";
}    
