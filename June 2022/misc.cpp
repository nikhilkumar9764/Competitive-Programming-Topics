/*  Find next greater number with same set of digits 

Given a number N = 2839 
output should be : 2893

Given number : N = 35276 
output should be 35627
*/





/* Amazon Alexa SDE question 
Given 3*N fighters . Each fighter being given a roll no from 1 to 3*N. An array A of length 3*N is such that ith element denotes the 
strength of fighter with ith roll number.From these fighters N will be removed. The remaining 2*N will be divided into 2 groups i.e based on their roll numbers.
N fighters with the smallest roll number will be in the group1 and N fighters with the largest roll number will be in the group2.
The two groups will then fight with each other.

Let total sum of strength of group1 be S1 and that of group2 be S2.Find the maximum value of S1-S2.
N = 2
A[] = {1, 3, 5, 2, 1, 1}
Output: 6

N = 2
A[] = {1, 1, 5, 3, 7, 7}
Output: -4 
*/


class Solution 
{
 public:
    using ll = long long int;
   long long colosseum(int N, vector<int> a) {

      vector<long long> L(N * 3 + 1), R(N * 3 + 1); // create 
      for (int i = 0; i <= 3 * N; ++i) {
         L[i] = -1e18, R[i] = 1e18;
      }

      priority_queue<long long, vector<long long>, greater<long long> > minHeap;

      long long sum = 0;
      for (int i = 0; i < 3 * N; ++i) {
         minHeap.push(a[i]);// push in queue untill the priority_queue size is less than or equal to N
         sum += a[i];
         if(minHeap.size() > N) { // now pop the top of priority_queue if size exceed 
            long long v = minHeap.top();
            minHeap.pop();
            sum -= v;
         }
         if(minHeap.size() == N) L[i + 1] = sum;
      }

      priority_queue<long long> maxHeap;
      sum = 0;
      for (int j = 0; j < 3 * N; ++j) { // same thing we will do here from back
         int i = 3 * N - 1 - j;
         maxHeap.push(a[i]);
         sum += a[i];
         if(maxHeap.size() > N) {
            long long v = maxHeap.top();
            maxHeap.pop();
            sum -= v;
         }
         if(maxHeap.size() == N) R[j + 1] = sum;
      }
     
     long long ans = -1e18;
      // iterate over L and R and find the maximum possible value
      for (int a = 0; a <= 3 * N; ++a)
      {
         int b = 3 * N - a;
         ans=max(ans,L[a] - R[b]);
      }
      return ans;
   }
};




/*  
There is a road of length 100 km which you travelled. There are different speed limits for different segments of the road. 
There are N such segments. And if one were to describe your driving, you drove in M segments. In each segment, you maintained a constant speed. 
You want to find out the maximum amount you went over the speed limit.

Input
Two integers N M on the first line.
N lines follow, where the i-th line of these describes the i-th segment. Each line has two integers, the first one describes the length of the segment and the second describes the maximum speed limit of this segment.
M lines follow, where the j-th line of these describes the j-th segment. Each line has two integers, the first one describes the length of the segment and the second describes the speed at which you travelled in this segment.

Constraints : 
The lengths of all N segements add up to 100.
The lengths of all M segments add up to 100.
All lengths are positive integers.
The speed limit of any segment is between 1 and 100 inclusive.
Your speed in any segment is between 1 and 100 inclusive.

Output
One integer --- the maximum amount you went over the speed limit. If you never went over the speed limit, output 0.

Example 1
Input
3 3
40 75
50 35
10 45
40 76
20 30
40 40
Output
5
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vp1,vp2;
    ll x,y;
    ll ar1[100] = {0};
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        vp1.push_back({x,y});
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        vp2.push_back({x,y});
    }
    
    ll cur1 = 0;
    for(int i=0;i<n-1;i++)
    {
        ll fi = cur1+ vp1[i].first;
        ar1[fi-1] = vp1[i].second;
        ar1[fi] = vp1[i+1].second;
        cur1 = fi;
    }
    ar1[99] = vp1[n-1].second;
    
    ll occ = vp1[0].first;
    for(int j=0;j<occ-1;j++)
    {
        ar1[j] = vp1[0].second;
    }
    for(int j=occ;j<100;j++)
    {
       if(ar1[j+1]==0 && ar1[j+1]!=ar1[j])
       {
           ar1[j+1] = ar1[j];
       }
    }
    
    
    ll ans= INT_MIN;
    ll ar2[100] = {0};
    ll curr2 = 0;
    for(int i=0;i<m-1;i++)
    {
        ll fi = curr2+ vp2[i].first;
        ar2[fi-1] = vp2[i].second;
        ar2[fi] = vp2[i+1].second;
        curr2 = fi;
    }
    ar2[99] = vp2[n-1].second;
    
    occ = vp2[0].first;
    for(int j=0;j<occ-1;j++)
    {
        ar2[j] = vp2[0].second;
    }
    for(int j=occ;j<100;j++)
    {
       if(ar2[j+1]==0 && ar2[j+1]!=ar2[j])
       {
           ar2[j+1] = ar2[j];
       }
    }
    
    for(int j=0;j<100;j++)
    {
        if((ar2[j]-ar1[j])>0)
        {
            ans = max(ans,(ar2[j]-ar1[j]));
        }
    }
    
    if(ans == INT_MIN)
    {
        cout<<0<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }
}

/* You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. 
If this is not possible, return -1.
Note that an integer x divides y if y % x == 0 
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) 
    {
         map<int,int> ma;
         for(auto it : nums)
         {
             ma[it]++;
         }
        
        int del = 0;
        sort(numsDivide.begin(),numsDivide.end());
        int val = numsDivide[0];
        set<int> ss;
    
        int x1= numsDivide.size();
                
        for(int p=1;p*p<=val;p++)
        {
           if(val%p == 0)
           {
                int ff = 0;
                int sec = val/p;
                for(int j=0;j<x1;j++)
                {
                    if((numsDivide[j]%p)!=0)
                    {
                        ff+=1;
                        break;
                    }
                }

                for(int j=0;j<x1;j++)
                {
                    if((numsDivide[j]%sec)!=0)
                    {
                        ff+=2;
                        break;
                    }
                }

                if(ff == 0)
                {
                    ss.insert(p);
                    ss.insert(sec);
                }
                else if(ff == 1)
                {
                    ss.insert(sec);
                }
                else if(ff == 2)
                {
                    ss.insert(p);
                }
           }
        }
        
        cout<<ss.size()<<"\n";
        for(auto j : ma)
        {
            int v1 = j.first;
            if(ss.find(v1) != ss.end())
            {
                break;
            }
            else{
                del+=j.second;
            }
        }
        
        if(del == nums.size())
        {
            return -1;
        }
        else{
            return del;
        }
        
    }
};