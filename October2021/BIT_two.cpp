/* Inversion Count (SPOJ)
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.

Input
The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.

Output
For every test output one line giving the number of inversions of A.

Example
Input:
2

3
3
1
2

5
2
3
8
6
1

Output:
2
5



 */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)


// void update(ll bit[],ll idx,ll inc,ll n)
// {
//     while(idx<=n)
//     {
//         bit[idx]+=1;
//         idx+=(idx&(-idx));
//     }
// }

// ll query(ll bit[] , ll idx)
// {
//     ll ans = 0;
//     while(idx>0)
//     {
//         ans+=bit[idx];
//         idx-=(idx&(-idx));
//     }
//     return ans;
// }

// int main()
// {
//     ll t;
// 	cin>>t;
// 	string str;
// 	while(t--)
// 	{
// 	    getline(cin,str);
// 		ll n;
// 		cin>>n;
// 		ll ar[n];
// 		ll maxi = -1;
// 		for(int i=0;i<n;i++)
// 		{
// 			cin>>ar[i];
// 			maxi = max(maxi,ar[i]);
// 		}
// 		ll fi = 0;
// 		ll bit[maxi+3] = {0};
// 		for(int i=n-1;i>=0;i--)
// 		{
// 		    fi+=query(bit,ar[i]-1);
// 		    update(bit,ar[i],1,maxi);
// 		}
// 		cout<<fi<<"\n";
// 	}
// }


/* Taking into account the negative numbers also in the array (Co-ordinate compression)
  i.e arranging the numbers according to the indexes in increasing order of value.
*/


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)


void update(ll bit[],ll idx,ll inc,ll n)
{
    while(idx<=n)
    {
        bit[idx]+=1;
        idx+=(idx&(-idx));
    }
}

ll query(ll bit[] , ll idx)
{
    ll ans = 0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ans;
}

int main()
{
    ll t;
	cin>>t;
	string str;
	while(t--)
	{
	    getline(cin,str);
		ll n;
		cin>>n;
		ll ar[n];
		ll maxi = -1;
		set<ll> se;
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			se.insert(ar[i]);
			
		}
		ll fi = 0;
		ll qq[n];
		map<ll,ll> ma;
		ll cc = 1;
		for(auto it : se)
		{
			ma[it] = cc;
			cc++;
		}

		for(int i=0;i<n;i++)
		{
			ll pos = ma[ar[i]];
			qq[i] = pos;
		}

		for(int i=0;i<n;i++)
		{
			maxi = max(maxi,qq[i]);
		}

		ll bit[maxi+3] = {0};
		for(int i=n-1;i>=0;i--)
		{
		    fi+=query(bit,qq[i]-1);
		    update(bit,qq[i],1,maxi);
		}
		cout<<fi<<"\n";
	}
}


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// ll ar[100005];
// ll bit[100005];

// void update(ll pt,ll n,ll inc)
// {
//      while(pt<=n)
//      {
//          bit[pt]+=inc;
//          pt+=(pt&(-pt));
//      }
// }

// ll query(ll l)
// {
//     ll su = 0;
//     while (l>0)
//     {
//         su+=bit[l];
//         l = l-(l&(-l));
//     }
//     return su;
// }

// int main()
// {
//     ll n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>ar[i];
//         update(i,n,ar[i]);
//     }
    
//     ll qu;
//     cin>>qu;
//     while(qu--)
//     {
//         ll ty;
//         cin>>ty;
//         if(ty == 1)
//         {
//             ll pt,inc;
//             cin>>pt>>inc;
//             update(pt,n,inc);
//         }
//         else{
//             ll lef,rig;
//             cin>>lef>>rig;
//             cout<<query(rig)-query(lef-1)<<"\n";
//         }
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// ll ar[100005];
// ll bit[100005];

// void update(ll pt,ll n,ll inc)
// {
//      while(pt<=n)
//      {
//          bit[pt] = max(bit[pt],inc);
//          pt+=(pt&(-pt));
//      }
// }

// ll query(ll l)
// {
//     ll ans = 0;
//     while (l>0)
//     {
//         ans = max(ans,bit[l]);
//         l = l-(l&(-l));
//     }
//     return ans;
// }

// int main()
// {
//     ll n;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>ar[i];
//         update(i,n,ar[i]);
//     }
//     ll qu;
//     cin>>qu;
//     while(qu--)
//     {
//         ll ty;
//         cin>>ty;
//         if(ty == 1)
//         {
//             ll pt,inc;
//             cin>>pt>>inc;
//             update(pt,n,inc);
//         }
//         else{
//             ll x;
//             cin>>x;
//             cout<<query(x)<<"\n";
//         }
//     }
// }