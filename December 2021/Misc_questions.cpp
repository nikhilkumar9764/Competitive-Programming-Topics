/* SDE-1 Konsberg Digital Hiring Challenge 

Given an array of N numbers , you need to make N/2 numbers square of some element and
the rest of N/2 elements such that they are not square of any element 
  1<=T<=10^3
  1<=N<=10^6
*/

#include<bits/stdc++.h>
using namespace std;
using ll  =long long int;
#define MOD (ll) (1e9+7)
 
ll equalizeIt (ll N, vector<ll> Arr) {
  vector<pair<ll,ll>> x;
  for(int i=0;i<N;i++)
  {
     long double vp = sqrt(Arr[i]);
     ll v1 = floor(vp);
     ll v2 = ceil(vp);
     ll myval = min(abs(Arr[i]-(v1*v1)), abs(Arr[i]-(v2*v2)));
     x.push_back({myval,i});
  }
  sort(x.begin(),x.end());
  ll su = 0;
  bool vis[N] = {false};
  for(int i=0;i<N/2;i++)
  {
      su+=x[i].first;
      vis[x[i].second] = true;
  }
  
  for(int i=0;i<N;i++)
  {
      if(vis[i] == false)
      {
          double vv = sqrt(Arr[i]);
          ll ob = floor(vv);
          if(ob*ob == Arr[i] && Arr[i] == 0)
          {
               su+=2;
          }
          else if(ob*ob == Arr[i] && Arr[i]>0)
          {
              su+=1;
          }
      }
  }
  return su; 
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> Arr(N);
        for(int i_Arr = 0; i_Arr < N; i_Arr++)
        {
        	cin >> Arr[i_Arr];
        }
 
        long long out_;
        out_ = equalizeIt(N, Arr);
        cout << out_;
        cout << "\n";
    }
}

/*Count the number of islands in the matrix */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

#define COL 3
void dfs(ll x,ll y,bool vis[][COL],ll ar[][COL],ll n)
{
	vis[x][y] = true;
	if((x-1)>=0 && !vis[x-1][y] && ar[x-1][y]==1)
	{
		dfs(x-1,y,vis,ar,n);
	}
	if((x+1)<n && !vis[x+1][y] && ar[x+1][y]==1)
	{
		dfs(x+1,y,vis,ar,n);
	}
	if((y-1)>=0 && !vis[x][y-1] && ar[x][y-1]==1)
	{
		dfs(x,y-1,vis,ar,n);
	}
	if((y+1)<n && !vis[x][y+1] && ar[x][y+1]==1)
	{
		dfs(x,y+1,vis,ar,n);
	}
}

int main()
{
	ll n;
	cin>>n;
	bool vis[n][COL] = {false};
	ll ar[n][COL];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ar[i][j];
		}
	}
	
	ll no_island = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		    if(!vis[i][j] && ar[i][j] == 1)
		    {
		        cout<<i<<" "<<j<<"\n";
		    	no_island++;
		    	dfs(i,j,vis,ar,n);
		    }
		    
		    for(int i=0;i<n;i++)
        	{
		      for(int j=0;j<n;j++)
		       {
		           cout<<vis[i][j]<<" ";
		       }
		       cout<<"\n";
            }
		}
	}
	cout<<no_island<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
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
    sort(ar,ar+n);
    vector<vector<ll>> vp;
    for(int i=0;i<n-1;i++)
    {
        vector<ll> r1;
        if(ar[i+1] == ar[i])
        {
            continue;
        }
        else
        {
            ll su = ar[i];
            ll lef = i+1,rig=n-1;
            while(lef<rig)
            {
                su+=(ar[lef]+ar[rig]);
                if(su>0)
                {
                    rig--;
                }
                else if(su<0)
                {
                    lef++;
                }
                else{
                    r1.push_back(ar[i]);
                    r1.push_back(ar[lef]);
                    r1.push_back(ar[rig]);
                }
            }
            r1.clear();
        }
    }
}

/*  C - Graph Isomorphism  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 300 points

Problem Statement
Takahashi and Aoki each have a toy made by attaching M cords to N balls.

In each toy, no cord ties a ball to itself, and no two balls are tied by two or more different cords.

Snuke is wondering whether the two toys have the same shape.
Here, they are said to have the same shape when there is a sequence P that satisfies the conditions below.

P is a permutation of (1,…,N).
For every pair of integers i,j between 1 and N (inclusive), the following holds.
 
Output
If the two toys have the same shape, print Yes; otherwise, print No.

Sample Input 1 
Copy
4 4
1 2
1 3
1 4
3 4
1 3
1 4
2 3
3 4
Sample Output 1 
Copy
Yes
 */

#include<bits/stdc++.h>
using namespace std;
int n,m,p[1000005];
int a[1005][1005],b[1005][1005];
bool true_check()
{
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
  	if((a[i][j]&&!b[p[i]][p[j]])||(a[i][j]&&!b[p[j]][p[i]]))return false;
  }
  return true;
}
bool check(){
  do{
    if(true_check())return true;
  }while(next_permutation(p+1,p+n+1));
  return false;
}
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)p[i]=i;
  for(int i=1;i<=m;i++){
  	int g,h;
  	cin>>g>>h;
  	a[g][h]=a[h][g]=1;
  }
  for(int i=1;i<=m;i++){
  	int g,h;
  	cin>>g>>h;
  	b[g][h]=b[h][g]=1;
  }
  cout<<(check()?"Yes":"No");
}


/*E. MEX and Increments
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dmitry has an array of n non-negative integers a1,a2,…,an.

In one operation, Dmitry can choose any index j (1≤j≤n) and increase the value of the element aj by 1. He can choose the same index j multiple times.

For each i from 0 to n, determine whether Dmitry can make the MEX of the array equal to exactly i. If it is possible, then determine the minimum number of operations to do it.

The MEX of the array is equal to the minimum non-negative integer that is not in the array. For example, the MEX of the array [3,1,0] is equal to 2, and the array [3,3,1,4] is equal to 0.

Input
The first line of input data contains a single integer t (1≤t≤104) — the number of test cases in the input.

The descriptions of the test cases follow.

The first line of the description of each test case contains a single integer n (1≤n≤2⋅105) — the length of the array a.

The second line of the description of each test case contains n integers a1,a2,…,an (0≤ai≤n) — elements of the array a.

It is guaranteed that the sum of the values n over all test cases in the test does not exceed 2⋅105.

Output
For each test case, output n+1 integer — i-th number is equal to the minimum number of operations for which you can make the array MEX equal to i (0≤i≤n), or -1 if this cannot be done.

Example
inputCopy
5
3
0 1 3
7
0 1 2 3 4 3 2
4
3 0 0 0
7
4 6 2 3 5 0 5
5
4 0 1 0 4
outputCopy
1 1 0 -1 
1 1 2 2 1 0 2 6 
3 0 1 4 3 
1 0 -1 -1 -1 -1 -1 -1 
2 1 0 2 -1 -1 
Note
In the first set of example inputs, n=3:

to get MEX=0, it is enough to perform one increment: a1++;
to get MEX=1, it is enough to perform one increment: a2++;
MEX=2 for a given array, so there is no need to perform increments;
it is impossible to get MEX=3 by performing increments.   */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
#define MAX (ll) (2e5+4)

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
      ll cnt[MAX] = {0};
      
      for(int i=0;i<n;i++)
      {
          cnt[ar[i]]++;
      }
      
      ll ans = 0;
      vector<ll> vp;
      for(int i=0;i<=n;i++)
      {
          ans+=cnt[i];
          cout<<ans<<" ";
          ans-=cnt[i];
          while(cnt[i] > 1)
          {
          	  vp.push_back(i);
          	  cnt[i]--;
          }
          if(cnt[i] == 0 && vp.size() == 0)
          {
              while(i<n)
              {
                  cout<<-1<<" ";
                  i++;
              }
              continue;
          }
          else if(cnt[i]==0)
          {
              ans+=(i-vp.back());
              cnt[i]++;
              vp.pop_back();
          }
      }
      cout<<"\n";
      vp.clear();
   }
} 


/* Snackdown Online Round 1A --Problem D : 
The beauty of an (non-empty) array of integers is defined as the difference between its largest and smallest element.

For example, the beauty of the array [2,3,4,4,6] is 6−2=4.

An array A is said to be good if it is possible to partition the elements of A into two non-empty arrays B1 and B2 such that

B1 and B2 have the same beauty.
Each element of array A should be in exactly one array: either in B1 or in B2.
For example, the array [6,2,4,4,4] is good because its elements can be partitioned into two arrays B1=[6,4,4] and B2=[2,4], where both B1 and B2 have the same beauty (6−4=4−2=2).

You are given an array A of length N. In one move you can:

Select an index i (1≤i≤N) and either increase Ai by 1 or decrease Ai by 1.
Find the minimum number of moves required to make the array A good.


1≤T≤105
2≤N≤105
−109≤Ai≤109
Sum of N does not exceeds 5⋅105 over all testcases

2
3
4 2 6
4
-2 4 -2 4
  */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
#define MAX (ll) (2e5+4)

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
      ll n;
      cin>>n;
      vector<ll> vp(n+2);
      multiset<ll> m1,m2;
      for(int i=1;i<=n;i++)
      {
          cin>>vp[i];
          m1.insert(vp[i]);
          m2.insert(-1*vp[i]);
      }
      sort(vp.begin()+1,vp.end());
      if(n==2)
      {
          cout<<0<<"\n";
      }
      else if(n==3)
      {
          cout<<min(abs(vp[1]-vp[2]),abs(vp[2]-vp[3]))<<"\n";
      }
      else
      {
          //Edge case 1 --> max(B1) = a[n] , min(B1)=a[1]
          ll ans = (vp[n]-vp[1])-(vp[n-1]-vp[2]);
          
          //Edge case 2--> B1 = {a[1]} , B2 = {a[2],a[3],....a[n]}
          ll med = vp[(n+1)/2 +1];
          ll su = 0;
          for(int i=2;i<=n;i++)
          {
              su+=abs(vp[i]-med);
          }
          ans = min(ans,su);
          
          //Edge case 3--> B1 = {a[n]} , B2 = {a[1],a[2],a[3]...a[n-1]}
          med = vp[(n+1)/2];
          ll s1 = 0;
          for(int i=1;i<n;i++)
          {
              s1+=abs(vp[i]-med);
          }
          ans = min(ans,s1);
          
          for(int i=2;i<n;i++)
          {
              m1.erase(m1.find(vp[1]));
              m1.erase(m1.find(vp[n]));
              m1.erase(m1.find(vp[i]));
              
              m2.erase(m2.find(-vp[1]));
              m2.erase(m2.find(-vp[n]));
              m2.erase(m2.find(-vp[i]));
              
              auto it1 = lower_bound(m1.begin(),m1.end(),(vp[n]+vp[1]-vp[i]));
              auto it2 = lower_bound(m2.begin(),m2.end(),-(vp[n]+vp[1]-vp[i]));
              
              if(it2!=m2.end())
              {
                  ll less = -(*(it2));
                  less = max(less,vp[i-1]);
                  ans = min(ans,abs((vp[n]-vp[i])-(less-vp[1])));
              }
              
              if(it1!=m1.end())
              {
                  ll greater = (*(it1));
                  greater = max(greater,vp[i-1]);
                  ans= min(ans,abs((vp[n]-vp[i])-(greater-vp[1])));
              }
              
              m1.insert(vp[1]);
              m1.insert(vp[n]);
              m1.insert(vp[i]);
              
              m2.insert(-vp[1]);
              m2.insert(-vp[n]);
              m2.insert(-vp[i]);
          }
          cout<<ans<<"\n";
      }
   }
} 

/* Educational Codeforces Round 120(Div2)--> Rated 
Problem C : https://codeforces.com/contest/1622/problem/C
Name: Set or Decrease
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
#define MAX (ll) (2e5+4)

int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll n,k;
       cin>>n>>k;
       ll ar[n];
       for(int i=0;i<n;i++)
       {
           cin>>ar[i];
       }
       sort(ar,ar+n);
       vector<ll> pre(n + 1);
	   for (ll i = 1; i < n; i++)
	    	pre[i] = pre[i - 1] + ar[i];

	    ll ans = 2e18;
	  for (ll i = n - 1; i >= 0; i--)
	   {
		ll sum = pre[i];
		ll cnt = n - i;
		ll req = k - sum;
		req = req / cnt;
 
		for (ll x = req - 5; x <= req + 5; x++)
		{
			if (sum + cnt * x > k) continue;
			ll curr = 0;
			if (x <= ar[0])
				curr += ar[0] - x;
			curr += cnt - 1;
			ans = min(ans, curr);
		}
	}
       cout<<ans<<"\n";
   }
} 