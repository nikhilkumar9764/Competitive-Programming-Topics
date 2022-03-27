/* Codeforces Round 767 - Div 1 

Mihai has just learned about the MEX concept and since he liked it so much, he decided to use it right away.
Given an array a of n non-negative integers, Mihai wants to create a new array b that is formed in the following way:
While a is not empty:

Choose an integer k (1≤k≤|a|).
Append the MEX of the first k numbers of the array a to the end of array b and erase them from the array a, shifting the positions of the remaining numbers in a.
But, since Mihai loves big arrays as much as the MEX concept, he wants the new array b to be the lexicographically maximum. So, Mihai asks you to tell him what the maximum array b that can be created by constructing the array optimally is.

An array x is lexicographically greater than an array y if in the first position where x and y differ xi>yi or if |x|>|y| and y is a prefix of x (where |x| denotes the size of the array x).
The MEX of a set of non-negative integers is the minimal non-negative integer such that it is not in the set. For example, MEX({1,2,3}) =0 and MEX({0,1,2,4,5}) =3.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of elements in the array a.
The second line of each test case contains n non-negative integers a1,…,an (0≤ai≤n), where ai is the i-th integer from the array a.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case print m — the length of the maximum array b Mihai can create, followed by m integers denoting the elements of the array b.  */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n];
        ll cnt[200005] = {0};
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            cnt[ar[i]]++;
        }
        ll mex = 0;
        vector<ll> res;
        set<ll> se;
        for(int i=0;i<n;i++)
        {
            se.insert(ar[i]);
            cnt[ar[i]]--;
            while(1)
            {
                if(se.find(mex)==se.end())
                {
                   break;
                }
                mex++;
            }
            if(cnt[mex] == 0)
            {
                res.push_back(mex);
                se.clear();
                mex = 0;
            }
        }
        cout<<res.size()<<"\n";
        for(auto it : res)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}

/* Leetcode contest weekly 286

2216. Minimum Deletions to Make Array Beautiful

Difficulty:Medium
You are given a 0-indexed integer array nums. The array nums is beautiful if:

nums.length is even.
nums[i] != nums[i + 1] for all i % 2 == 0.
Note that an empty array is considered beautiful.

You can delete any number of elements from nums. When you delete an element, all the elements to the right of the deleted element will be shifted one unit to the left to fill the gap created and all the elements to the left of the deleted element will remain unchanged.

Return the minimum number of elements to delete from nums to make it beautiful. 
Input: nums = [1,1,2,2,3,3]
Output: 2
Explanation: You can delete nums[0] and nums[5] to make nums = [1,2,2,3] which is beautiful. It can be proven you need at least 2 deletions to make nums beautiful.
 */

class Solution {
public:
    
    
    int minDeletion(vector<int>& nums)
    {
        int res=0,n=nums.size(),i;
        int flag=1;
            for(i=0;i<nums.size()-1;i++){
                    if(i%2==0 and nums[i]==nums[i+1]  and flag){
                        res++;
                        flag=0;
                    }
                    else if(i%2==1 and nums[i]==nums[i+1] and flag==0){
                        res++;
                        flag=1;
                    }
                }
        int x=n-res;
        if(x%2==0){
            return res;
        }
        return res+1;
    }
};

/* Samsung Hackerearth Hiring Test
Given an array of integers of size N , choose a strictly increasing subsequence and compute its bitwise OR and 
chosen subsequence should have el1 < el2 < el3 <... <elN . Compute all possible bitwise OR of all such subsequences 
and put it in an array 

Example : N = 4 
ar[] = [4,2,4,1]  --> [0,2,4,1,6]
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> solve (int N, vector<int> arr) {
   vector<int> res;
   set<int> s1;
   s1.insert(0);
   vector<int> adj[550];
   for(int i=0;i<arr.size();i++)
   {
       adj[arr[i]].push_back(i);
   }
   for(int i=0;i<=505;i++)
   {
       sort(adj[i].begin(),adj[i].end());
   }
   set<int> tmp;
   for(int j=1;j<505;j++)
   {
       if(adj[j].size()>0)
       {
           int idx = adj[j][0];
           tmp.insert(j);
           for(int i=0;i<j;i++)
           {
               if(adj[i].size()>0 && adj[i][0]<idx && i<j)
               {
                   for(auto pt : tmp)
                   {
                       tmp.insert(pt|i);
                   }
                   tmp.insert(i);
               }
           }
           for(auto kk : tmp)
           {
               s1.insert(kk);
           }
       }
       tmp.clear();
   }
   for(auto a : s1)
   {
       res.push_back(a);
   }
   return res;
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
        vector<int> arr(N);
        for(int i_arr = 0; i_arr < N; i_arr++)
        {
        	cin >> arr[i_arr];
        }

        vector<int> out_;
        out_ = solve(N, arr);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}