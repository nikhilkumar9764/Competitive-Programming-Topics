/* Atcoder Beginner 245-E 

Takahashi has N pieces of chocolate. The i-th piece has a rectangular shape with a width of A[i] 
centimeters and a length of B[i] centimeters.
He also has M boxes. The i-th box has a rectangular shape with a width of C 
i centimeters and a length of D[i] centimeters.

Determine whether it is possible to put the N pieces of chocolate in the boxes under the conditions below.

A box can contain at most one piece of chocolate.
A[i]≤C[j]
​
  must hold when putting the i-th piece of chocolate in the j-th box (they cannot be rotated).*/


/* Leetcode Biweekly contest 80
The score of an array is defined as the product of its sum and its length.
For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.
A subarray is a contiguous sequence of elements within an array.
Example 1:
Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
*/


class Solution {
    using ll = long long;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll sz = nums.size();
        ll pre[sz+1];
        pre[0] = nums[0];
        for(int i=1;i<sz;i++)
        {
            pre[i] = pre[i-1]+nums[i];
        }
        ll ans = 0;
        for(int i=0;i<sz;i++)
        {
            ll low = i,hi = sz-1;
            ll an1 = -1;
            while(low<=hi)
            {
                ll mid = (low+hi)/2;
                ll val1;
                if((i-1)>=0)
                {
                   val1 = pre[mid]-pre[i-1];
                }
                else{
                     val1 = pre[mid];
                 }
                val1*= (mid-i+1);
                if(val1 >=k)
                {
                    hi = mid-1;
                }
                else{
                    an1 = mid;
                    low = mid+1;
                }
            }
            if(an1!=-1)
            {
                ans+=(an1-i+1);
            }
        }
           return ans;
    }
};

/* Codechef starters 38 -- A bit easy(Bit masking) 
  Chef was impressed by an array A of N non-negative integers. But, he was asked to solve the following problem in order to get this array.

Given a non-negative integer k, find the number of pairs (i,j) (1≤i<j≤N) such that the following condition holds true:
(Ai | Aj) + (Ai⊕Aj) + (Ai & Aj) =k +Aj, where

(Ai|Aj) denotes Bitwise OR operation,
(Ai ⊕ Aj) denotes Bitwise XOR operation,
(Ai & Aj) denotes Bitwise AND operation.
You, being Chef's friend, help him get this array 
 
  Constraints :
1≤T≤200
1≤N≤105
0≤k≤1018
0≤Ai≤1018
Sum of N over all test cases does not exceed 3⋅105.

 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

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
        map<ll,ll> ma;
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
           ans+=ma[ar[i]];
           ll val1 = (k-ar[i])^ar[i];
           ma[val1]++;
        }
        cout<<ans<<"\n";
    }
}

/* 
You are given a simple connected undirected graph with N vertices and M edges.
Edge i connects Vertex A[i] and Vertex B[i], and has a length of C[i]
Let us delete some number of edges while satisfying the conditions below. Find the maximum number of edges that can be deleted.
The graph is still connected after the deletion.For every pair of vertices (s,t), the distance between s and t remains the same before and after the deletion. */


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

typedef struct 
{
   ll a,b,c;
}tr;

int main() 
{
    ll n,m;
    cin>>n>>m;
    vector<tr> v1;
    ll x,y,z;
    
    ll adj[550][550];
    for(int i=1;i<=n+2;i++)
    {
        for(int j=1;j<=(n+2);j++)
        {
            adj[i][j] = 1e10;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        v1.push_back({x,y,z});
        adj[x][y] = z;
        adj[y][x] = z;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(adj[j][i] +adj[i][k] < adj[j][k])
                {
                    adj[j][k] = adj[j][i]+adj[i][k];
                }
            }
        }
    }
    
    ll ans = 0;
    for(auto j : v1)
    {
        ll fl = 0;
        for(int p=1;p<=n;p++)
        {
            if(j.a!=p && j.b!=p && adj[j.a][p]+adj[p][j.b]<=j.c)
            {
                fl = 1;
                break;
            }
        }
        if(fl)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}

