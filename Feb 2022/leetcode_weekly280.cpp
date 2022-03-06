/*
Minimum no of operations to make it alternating : 

You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.

Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        int len1,len2;
        if(len%2 == 1)
        {
            len1 = (len/2)+1;
            len2 = (len/2);
        }
        else{
            len1 = (len/2);
            len2 = (len/2);
        }
        
        map<int,int> m1,m2;
        for(int j=0;j<nums.size();j+=2)
        {
            m1[nums[j]]++;
        }
        for(int j=1;j<nums.size();j+=2)
        {
            m2[nums[j]]++;
        }
        int k1 = 0,v1 = 0,k2=0,v2= 0;
        
        int n1 = 0,j1 = 0,n2=0,j2= 0;
        
        for(auto it: m1)
        {
            if(it.second>v1)
            {
                v1 = it.second;
                k1 = it.first;
            }
        }
        for(auto it: m1)
        {
            if(it.second>v2 && it.second<=v1 && it.first!=k1)
            {
                v2 = it.second;
                k2 = it.first;
            }
        }
        
        for(auto it: m2)
        {
            if(it.second>j1)
            {
                j1 = it.second;
                n1 = it.first;
            }
        }
        for(auto it: m2)
        {
            if(it.second>j2 && it.second<=j1 && it.first!=n1)
            {
                j2 = it.second;
                n2 = it.first;
            }
        }
      
        if(k1 == n1)
        {
            if(k2==0 && n2==0)
            {
                cnt+=(len/2);
            }
            else{
                int aa = min((len1-v2)+(len2-j1) , (len2-j2)+(len1-v1));
                cnt+=aa;
            }
        }
        else{
            cnt+=((len1)-v1);
            cnt+=((len2)-j1);
        }
        return cnt;
    }
};

/* Atcoder Beginner 242 
Given an integer N, find the number of integers X that satisfy all of the following conditions, modulo 998244353.

X is an N-digit positive integer.
​
 ∣≤1 for all integers 1≤i≤N−1.
Constraints
N is an integer.
2≤N≤10 
6 */

#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
using ll = long long int;
ll dp[1048576][10] = {0};

int main(){
    /* dp[len][char] means no of permutations of length len ending with digit char*/
    
    ll n;
    cin>>n;
    for(int i=1;i<=9;i++)
    {
        dp[1][i] = 1;
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=max(i-1,1);j<=min(i+1,9);j++)
            {
                dp[len][j]+=dp[len-1][i];
                dp[len][j]%=mod;
            }
        }
    }
    ll su = 0;
    for(int i=1;i<=9;i++)
    {
        su+=dp[n][i];
        su=su%mod;
    }
    cout<<su<<"\n";
}
