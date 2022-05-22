/* Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
 

Example 1: Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
      void func(TreeNode* head,int &sc,int &no_nodes)
      {
            if(head == NULL)
            {
                return;
            }
            func(head->left,sc,no_nodes);
            sc+=head->val;
            no_nodes+=1;
            func(head->right,sc,no_nodes);
      }
    
public:
    
    int averageOfSubtree(TreeNode* root) {
         queue<TreeNode*> q;
         int cnt = 0;
         q.push(root);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int tot_score = 0,no_nodes = 0;
            func(it,tot_score,no_nodes);
            int avg = tot_score / no_nodes;
            if(it->val == avg)
            {
                 cnt++;
            }
            
            if(it->left)
            {
                q.push(it->left);
            }
            
            if(it->right)
            {
                 q.push(it->right);
            }
        }
        return cnt;
    }
};

/* GFG Hiring Challenge question :

There are N tiles arranged in a row . Each tile has A[i] units of gold on it. To collect the gold you need to present on it.
You can start from any tile. In one operation you can move from a tile i to tile j if (i+j) is odd. Collect the maximum amount of
gold that you can collect.

Example: 
1. N = 5 , K = 2      2.  N= 10 ,K=4                          3. N=3 ,K=2
   A = [5,2,4,3,5]        A =[6,10,8,23,31,13,20,36,10,14]       A=[2,3,1]
*/ 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)

ll solve(ll N,ll K,ll A[])
{
    vector<ll> odd,even;
    for(int i=0;i<N;i++)
    {
        if(i%2==0)
        {
           even.push_back(A[i]);
        }
        else{
            odd.push_back(A[i]);
        }
    }
    sort(even.begin(),even.end(),greater<ll>());
    sort(odd.begin(),odd.end(),greater<ll>());
    if(K == 0)
    {
        if(N==1)
        {
          return A[0];
        }
        else{
            return max(even[0],odd[0]);
        }
    }
    else
    {
        ll el = K+1;
        ll half = el/2;
        ll rem = el-half;
        ll sc1 = 0, sc2 = 0;
            
        if(even.size()>=half)
        {
          for(int i=0;i<half;i++)
           {
           	sc1+=even[i];
            }
        }
            
       if(odd.size()>=half)
        {
          for(int i=0;i<half;i++)
          {
        	sc2+=odd[i];
          }
        }
        
        if(odd.size()>=rem)
        {
          for(int i=0;i<(rem);i++)
          {
          	sc1+=odd[i];
          }
        }
            
        if(even.size()>=rem)
        {
         for(int i=0;i<rem;i++)
         {
        	sc2+=even[i];
         }
        }
        return max(sc1,sc2);
    }
}

int main()
{
   	ll N,k;
    cin>>N>>k;
    ll A[N];
    for(int i = 0; i < N; i++) 
    {
       cin>>A[i];
    }
    ll r1 = solve(N,k,A);
    cout<<r1<<"\n";
}

/* Leetcode 292 --Count number of texts (DP Question) 
Alice is texting Bob using her phone. The mapping of digits to letters is shown in the figure below.


In order to add a letter, Alice has to press the key of the corresponding digit i times, where i is the position of the letter in the key.

For example, to add the letter 's', Alice has to press '7' four times. Similarly, to add the letter 'k', Alice has to press '5' twice.
Note that the digits '0' and '1' do not map to any letters, so Alice does not use them.
However, due to an error in transmission, Bob did not receive Alice's text message but received a string of pressed keys instead.

For example, when Alice sent the message "bob", Bob received the string "2266622".
Given a string pressedKeys representing the string received by Bob, return the total number of possible text messages Alice could have sent.

Since the answer may be very large, return it modulo (10^9 + 7).
Input: pressedKeys = "22233"
Output: 8
Explanation:
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.
*/

class Solution {
    using ll = long long int;
    #define MOD (ll) (1e9+7)
public: 
    ll countTexts(string pressedKeys) {
        ll sz = pressedKeys.size();
        ll dp[sz+1];
        dp[0] = 1;
        for(int i=1;i<(sz+1);i++)
        {
            dp[i] = dp[i-1];
            ll len;
            if(pressedKeys[i-1] == '7' || pressedKeys[i-1] == '9')
            {
                len = 4;
            }
            else{
                len = 3;
            }
            for(int j=i-2;j>=0 && j>=(i-len) && pressedKeys[j] == pressedKeys[i-1];j--)
            {
                dp[i] = (dp[i]+dp[j])%MOD;
            }
        }
        return dp[sz];
    }
};
