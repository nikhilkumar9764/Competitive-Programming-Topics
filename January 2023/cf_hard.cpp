/*
Sir Monocarp Hamilton is planning to paint his wall. The wall can be represented as a grid, consisting of 2 rows and m columns. Initially, the wall is completely white.

Monocarp wants to paint a black picture on the wall. In particular, he wants cell (i,j)
 (the j-th cell in the i-th row) to be colored black, if ci,j= 'B', and to be left white, if ci,j= 'W'. Additionally, he wants each column to have at least one black cell, so, for each j
, the following constraint is satisfied: c1,j, c2,j
 or both of them will be equal to 'B'.

In order for the picture to turn out smooth, Monocarp wants to place down a paint brush in some cell (x1,y1) and move it along the path (x1,y1),(x2,y2),…,(xk,yk)
 so that:

for each i, (xi,yi) and (xi+1,yi+1) share a common side;all black cells appear in the path exactly once;white cells don't appear in the path.
Determine if Monocarp can paint the wall.

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.
The first line of each testcase contains a single integer m (1≤m≤2⋅105) — the number of columns in the wall.

The i-th of the next two lines contains a string ci, consisting of m characters, where each character is either 'B' or 'W'. ci,j is 'B', if the cell (i,j) should be colored black, and 'W', if the cell (i,j)
 should be left white.

Additionally, for each j, the following constraint is satisfied: c1,j, c2,j or both of them are equal to 'B'.

The sum of m
 over all testcases doesn't exceed 2⋅105
.

Output
For each testcase, print "YES" if Monocarp can paint a wall. Otherwise, print "NO".

Example
inputCopy
6
3
WBB
BBW
1
B
B
5
BWBWB
BBBBB
2
BW
WB
5
BBBBW
BWBBB
6
BWBBWB
BBBBBB
output 
YES
YES
NO
NO
NO

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string ar[2];
        for(int i=0;i<2;i++)
        {
            cin>>ar[i];
        }
        ll fl = 0;
        ll pos = -1;
        for(int j=0;j<n;j++)
        {
            if(ar[0][j] != ar[1][j])
            {
                pos = j;
                break;
            }
        }
        
        if(pos == -1)
        {
             cout<<"YES\n";
             continue;
        }
        
        ll curr_row = (ar[0][pos] == 'B') ? 0 : 1;
        for(int j=pos+1;j<n;j++)
        {
            if(ar[curr_row][j] == 'W')
            {
                 fl = 1;
                 break;
            }
            if(ar[curr_row^1][j] == 'B')
            {
                curr_row = curr_row^1;
            }
        }
        
        curr_row = (ar[0][pos] == 'B' ? 0 : 1);
        for(int j=pos-1;j>=0;j--)
        {
            if(ar[curr_row][j] == 'W')
            {
                 fl = 1;
                 break;
            }
            if(ar[curr_row^1][j] == 'B')
            {
                curr_row = curr_row^1;
            }
        }
        
        if(fl)
        {
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}



/* Codeforces Round -- TypeDB Round 2023 Div2 

Question A : Exponential equation  
You are given an integer n
.Find any pair of integers (x,y)
 (1≤x,y≤n) such that xy⋅y+yx⋅x=n */


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll power(ll x, ll y, ll p)
{
 
    // Initialize answer
    ll res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x);
    }
    return res % p;
}

int main () 
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll sq = sqrt(n);
	    std::vector<ll> r1;
	    
	    ll org = n;
	    if(n%2 == 0)
	    {
	         r1.push_back(2);
	    }
	    while(n%2 == 0)
	    {
	        n = n/2;
	    }
	    
	    for(int i=3;i<=sq;i+=2)
	    {
	        if(n%i == 0)
	        {
	            r1.push_back(i);
	            while(n%i==0)
	            {
	                n = n/i;
	            }
	        }
	    }
	   
	    ll fl = 0;
	    for(int i=0;i<r1.size();i++)
	    {
	        for(int j=0;j<r1.size();j++)
	        {
	            if((power(r1[i],r1[j],MOD)*r1[j] + power(r1[j],r1[i],MOD)*r1[i]) == org)
	            {
	                 fl = 1;
	                 cout<<r1[i]<<" "<<r1[j]<<"\n";
	                 break;
	            }
	        }
	        if(fl==1)
	        {
	            break;
	        }
	    }
	    if(fl == 0)
	    {
	        cout<<-1<<"\n";
	    }
	}
}

/* Optimised solution */

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

ll power(ll x, ll y, ll p)
{
 
    // Initialize answer
    ll res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x);
    }
    return res % p;
}

int main () 
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    if(n%2 == 1)
	    {
	        cout<<-1<<"\n";
	    }
	    else{
	        cout<<1<<" "<<n/2<<"\n";
	    }
	}
}

/* Aesthetic Permutations (Trilogy Innovations Test question)
 Mr.Hola has an array A and integer b. The aesthetic value of array A is summation of |A[i]-A[i+b]| over all i from 1 to N-b .
You have to find the minimum aesthetic value for any permutation of array A .

Constraints :    2<=N<=3*10^5 
                1<=B<=min(5000,N-1)
*/






/* 
Codeforces question (Remove the brackets)

RSJ has a sequence a of n integers a1,a2,…,an and an integer s
. For each of a2,a3,…,an−1, he chose a pair of non-negative integers xi and yi such that xi+yi=ai and (xi−s)⋅(yi−s)≥0.

Now he is interested in the value
F=a1⋅x2+y2⋅x3+y3⋅x4+…+yn−2⋅xn−1+yn−1⋅an.
Please help him find the minimum possible value F he can get by choosing xi and yi optimally. It can be shown that there is always at least one valid way to choose them.
*/


#include <bits/stdc++.h>
using namespace std;
 
#define watch(x) cout << (#x) << " = " << (x) << endl
#define MOD 1000000007
 
long long a[200005], x[200005], y[200005], dp[200005][2];
long long n;
 
long long solve(long long index, long long next, int turn)  {
    if(index == n)  {
        return next * a[n];
    }
    if(dp[index][turn] != -1)   {
        return dp[index][turn];
    }
    
    long long ans = (next * x[index]) + solve(index+1, y[index], 0);
    long long ans1= (next * y[index]) + solve(index+1, x[index], 1);
    return dp[index][turn] = min(ans, ans1);
}
 
int main()  {
    long long t;
    cin >> t;
    while(t--)  {
        long long s;
        cin >> n >> s;
        for(long long i = 1; i <= n; i++)  {
            cin >> a[i];
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        for(long long i = 2; i <= (n-1); i++) {
            if(a[i] >= 2*s) {
                x[i] = s;
                y[i] = a[i] - s;
            } else if(a[i] >= s && a[i] < (2*s))    {
                x[i] = a[i] - s;
                y[i] = s;
            } else {
                x[i] = 0;
                y[i] = a[i];
            }
        }
        long long ans = (a[1] * x[2]) + solve(3, y[2], 0);
        long long ans1 = (a[1] * y[2]) + solve(3, x[2], 1);
        
        cout << min(ans, ans1) << "\n";
    }
    return 0;
} 

/* Given a number n , find out the lexicographically largest sequence of numbers ( 0<=x<=n-1) such that for each index
i , element at that index x , x+i is prime or x==1 or x==0 

For example : 
n = 9
output should be : [7 6 5 8 3 2 1 4 0]
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

vector<ll> pp ;
bool check_prime(ll n)
{
    bool isp = true;
    for(int j=2;j*j<=n;j++)
    {
        if(n%j == 0)
        {
            isp = false;
            break;
        }
    }
    return isp;
}


void calc_primes(ll val)
{
    bool primes[100005];
    for(int j=1;j<=100005;j++)
    {
        primes[j] = true;
    }
    for(int j=2;j*j<=val;j++)
    {
       for(int k=j*2;k<=val;k+=j)
       {
           primes[k] = false;
       }
    }
    for(int p=2;p<=val;p++)
    {
        if(primes[p] == true)
        {
            pp.push_back(p);
        }
    }
}

int main() 
{
    ll n;
    cin>>n;
    calc_primes(100005);
    vector<ll> v1;
    auto it = *(upper_bound(pp.begin(),pp.end(),n));
    auto it1 = *(lower_bound(pp.begin(),pp.end(),n)-1);
    
    bool vis[n+1] = {false};
    for(int j=0;j<=n-1;j++)
    {
        int vv = it-j;
        int vv2 = it1-j;
        if((!vis[vv] && vv<=n-1) && (!vis[vv2] && vv2<=n-1))
        {
            v1.push_back(vv);
            vis[vv] = true;
        }
        else if(vv2>0 && !vis[vv2] && vv2<=n-1)
        {
            v1.push_back(vv2);
            vis[vv2] = true;
        }
        else{
            ll v1p = n-1-j;
            cout<<v1p<<"\n";
            v1.push_back(v1p);
            vis[v1p] = true;
        }
    }
    
    for(auto it : v1)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
  
}



/* GP Hiring contest q1 -- building servers*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

bool cmp(const pair<ll,ll> &p1 , const pair<ll,ll>& p2)
{
    return p1.first > p2.first;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll c[n] ,f[n];
    for(int j=0;j<n;j++)
    {
        cin>>c[j];
    }
    for(int j=0;j<n;j++)
    {
        cin>>f[j];
    }
    
    vector<pair<ll,ll>> vp;
    // answer will be picking up first m elements from the vector and calculating total_power as well as versatility in it, 
    // or adding up to top m versatile elements from the vector and then picking up the remaining elements for maximizing total_power
    
    ll su1 = 0 , su2 = 0;
    for(int i=0;i<n;i++)
    {
        vp.push_back({c[i],f[i]});
    }
    
    sort(vp.begin(),vp.end(),cmp);
    set<ll> se1, se2;
    bool vis[n+1] = {false};
    for(int j=0;j<m;j++)
    {
        su1+=vp[j].first;
        se1.insert(vp[j].second);
    }
    
    su1+=pow(se1.size(),2);
    
    for(int j=0;j<n;j++)
    {
        if(se2.find(vp[j].second) == se2.end() && se2.size()<m)
        {
            su2+=vp[j].first;
            se2.insert(vp[j].second);
            vis[j] = true;
        }
    }
    
    ll rem = m-se2.size();
    for(int j=0;j<n;j++)
    {
        if(!vis[j] && se2.size()<m)
        {
            su2+=vp[j].first;
            se2.insert(vp[j].second);
            vis[j] = true;
        }
    }
    su2+=pow(se2.size(),2);
    
    cout<<su1<<" "<<su2<<"\n";
    ll ans = max(su1,su2);
    cout<<ans<<"\n";
}


