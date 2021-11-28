/*Given n no of students , k -->denoting the minimum total goodness required 
There are n boys standing in a line , the ith boy has height Hi and goodness Gi . You are given a number k

Determine the number of ways to select a team of boys such that sum of their goodness is atleast K.

Notes : 
1. You can only select a single boy once per team.
2. Two ways of selection are diff if there are atleast 1 boy who is not selected in one 
but selected in the other
3. You can move from left to right and select a boy whose height is greater than or equal to the last selected boy
4. You cannot reorder them , but you may skip some of them

N = 3 ,K = 2

H = [1,3,2]
G= [1,2,1]

Answer is 3 

Constraints:

 1<=T<=10
 1<=N<=40
 1<=K<=10^9
 1<=H[i], G[i]<=10^9
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
 
ll pw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2 == 1)
		{
			res = (res*a)%MOD;
		}
		b=b/2;
		a = (a*a)%MOD;
	}
	return res%MOD;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	ll n,k;
	cin>>n>>k;
    ll h[n],g[n];
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>g[i];
	}
	ll cnt = 0;
	 for(int i=1;i<=(1LL<<n)-1;i++)
	 {
		 ll su = 0,last = -1;
		 ll fl = 0;
		for(int j=0;j<n;j++)
		{
			if(i&(1LL<<j) && h[j]>=last)
			{
               su+=g[j];
			   last = h[j];
			}
			else if(i&(1LL<<j) && h[j]<last)
			{
				fl = 1;
				break;
			}
		}
		if(fl == 1)
		{
			continue;
		}
		else{
			if(su>=k)
			{
				cnt++;
			}
		}
	 }
	 cout<<cnt<<"\n";
	}
}

/*
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

 

Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 10^6


Approach used : DP + Bitmasking (Hard)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
	ll n;
	cin>>n;
	ll ar[2*n];
	for(int i=0;i<2*n;i++)
	{
		cin>>ar[i];
	}
    ll vv = 2*n;
	ll sz = (1<<vv);
    ll hcf[vv][vv];
    for(int i=0;i<vv-1;i++)
	{
		for(int j=i+1;j<vv;j++)
		{
			hcf[i][j] = __gcd(ar[i],ar[j]);
			hcf[j][i] = hcf[i][j];
		}
	}

	for(int i=1;i<sz;i++)
	{
		ll no_set_bits = __builtin_popcount(i);
		if(no_set_bits%2 == 1)
		{
			continue;
		}
        for(int j=0;j<vv;j++)
		{
			for(int k=j+1;k<vv;k++)
			{
                  if(i&(1<<j) && i&(1<<k))
				  {
					  dp[i] = max(dp[i],dp[i-(1<<j)-(1<<k)]+__gcd(ar[j],ar[k])*(no_set_bits/2));
				  }
			}
		}
	}
	cout<<dp[sz-1]<<"\n";
}


/*  https://www.codechef.com/problems/MINSZ/

Consider an array A={a1,a2,...,an} of size n≥1. If ak=2x−1 for all 1≤k≤n, for some integer x (1≤x≤60), then A is called interesting array.

You are given a number C. Find any interesting array A of minimum possible size such that a1⨁a2⨁...⨁an=C, where ⨁ represents bitwise XOR operation.

If there exists multiple such arrays, output any one.

Input Format
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains single integer C on a single line.
Output Format
For each testcase, on the first line output the minimum possible size of array A satisfying the given property.
On the next line output the elements of array A in any order.

Constraints : 
  1≤T≤10^5 
  0≤C<2^60

It is guaranteed in the input that sum of lengths of arrays over all testcases does not exceed 10^6. 
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       ll x;
       cin>>x;
       vector<ll> ans;
       ll curr_xor = 0;
       for(int i=60;i>=0;i--)
       {
           ll xx = (1LL<<i)&x;
           ll yy = (1LL<<i)&curr_xor;
           if(xx!=yy)
           {
               ans.push_back((1LL<<(i+1))-1);
               curr_xor^= (1LL<<(i+1))-1;
           }
       }
       if(ans.size() == 0)
       {
           cout<<2<<"\n";
           cout<<1<<" "<<1<<"\n";
       }
       else{
           cout<<ans.size()<<"\n";
           for(auto it:ans)
           {
               cout<<it<<" ";
           }
           cout<<"\n";
       }
       ans.clear();
    }
}

/*
Xenia and Bit operations :
https://codeforces.com/contest/339/problem/D

Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.
Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. 
At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. 
And so on; the operations of bitwise exclusive OR and bitwise OR alternate. 
In the end, she obtains a sequence consisting of one element, and that element is v.

Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.
You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment a[p] = b. After each query, you need to print the new value v for the new sequence a.

Input:
The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

Output:
Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

Examples:
2 4
1 6 3 5
1 4
3 4
1 2
1 2
(Segment Trees Concept used here)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b%2 == 1)
		{
			res = (res *a)%MOD;
		}
		b>>=1;
		a = (a*a)%MOD;
	}
	return res;
}

ll tree[2000005] , ar[2000005];
void build(ll ss,ll se,ll idx)
{
	if(ss == se)
	{
		tree[idx] = ar[ss];
		return;
	}
	ll mid = (ss+se)/2;
	build(ss,mid,2*idx);
	build(mid+1,se,2*idx+1);
	ll no_times = log2(se-ss+1);
	if(no_times % 2)
	{
		tree[idx] = tree[2*idx] | tree[2*idx+1];
	}
	else{
		tree[idx] = tree[2*idx] ^ tree[2*idx+1];
	}
}


void update(ll ss,ll se,ll pt,ll idx,ll val)
{
	if(pt > se || pt < ss)
	{
		return;
	}
	if(ss == se && ss == pt)
	{
		tree[idx] = val;
	}
	else
	{
	    ll mid = (ss+se)/2;
    	update(ss,mid,pt,2*idx,val);
	    update(mid+1,se,pt,2*idx+1,val);
	    ll no_times = log2(se-ss+1);
	    if(no_times % 2)
	     {
	    	tree[idx] = tree[2*idx] | tree[2*idx+1];
	     }  
	    else
	    {
		   tree[idx] = tree[2*idx] ^ tree[2*idx+1];
	     }
	}
}

int main()
{
	ll n,m;
	cin>>n>>m;
	ll el = pw(2,n);
	for(int i=0;i<el;i++)
	{
		cin>>ar[i];
	}
	build(0,el-1,1);
	while(m--)
	{
		ll idx,val;
		cin>>idx>>val;
		--idx;
		update(0,el-1,idx,1,val);
		cout<<tree[1]<<"\n";
	}
}