/* Scramble strings */






/* Amount of time for binary tree to be infected*/
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
public:
    map<TreeNode*,TreeNode*> ma;
    bool vis[100005] = {false};
    int strt = -1,ans=0;
    TreeNode* curr;
    int amountOfTime(TreeNode* root, int start) 
    {
        strt = start;
        find_parents(root);
        dfs(curr,0);
        return ans;
    }
    
    void dfs(TreeNode* root , int lev)
    {
         vis[root->val] = true;
        if(root->left && !vis[root->left->val])
        {
            dfs(root->left , lev+1);
        }
        if(root->right && !vis[root->right->val])
        {
            dfs(root->right , lev+1);
        }
        if(ma.count(root) && !vis[ma[root]->val])
        {
             dfs(ma[root] , lev+1);
        }
        ans = max(ans,lev);
    }
    
    void find_parents(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        if(strt == root->val)
        {
            curr = root;
        }
        if(root->left)
        {
            ma[root->left] = root;
        }
        if(root->right)
        {
            ma[root->right] = root;
        }
        find_parents(root->left);
        find_parents(root->right);
    }
};

/* Google Kickstart round D - TOUCHBAR TYPING*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (2505)

vector<ll> s(MAX+1),k(MAX+1);
vector<vector<ll>> pref(MAX+1 , vector<ll> (MAX+1,-1));
vector<vector<ll>> suf(MAX+1 , vector<ll> (MAX+1,-1));
ll n,m;


ll MinCostTyping(ll i, ll j, vector<vector<ll>> &dp){
    if(i == n){
        return 0;
    }
 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = 1e18;
 
    if(pref[j][s[i]] != -1){
        ll cost = abs(j - pref[j][s[i]]);
        ans = min(ans, cost + MinCostTyping(i + 1, pref[j][s[i]], dp));
    }
 
    if(suf[j][s[i]] != -1){
        ll cost = abs(j - suf[j][s[i]]);
        ans = min(ans, cost + MinCostTyping(i + 1, suf[j][s[i]], dp));
    }
 
    return dp[i][j] = ans;
}

int main()
{
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
      
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        cin>>m;
        ll mx = -1;
        for(int i=0;i<m;i++)
        {
            cin>>k[i];
            mx = max(mx,k[i]);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=mx;j++)
            {
                pref[i][j] = suf[i][j] = -1;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            pref[i][k[i]] = suf[i][k[i]] = i;
        }
        
        for(int i=0;i<=mx;i++)
        {
            ll last = -1;
            for(int j=0;j<m;j++)
            {
                if(pref[j][i]!=-1)
                {
                    last = pref[j][i];
                }
                pref[j][i] = last;
            }
            
             last = -1;
            for(int j=m-1;j>=0;j--)
            {
                if(suf[j][i]!=-1)
                {
                    last = suf[j][i];
                }
                suf[j][i] = last;
            }
        }
        ll ans = 1e18;
        vector<vector<ll>> dp(n , vector<ll> (m+1,-1));
        for(int i=0;i<m;i++)
        {
            ans = min(ans, MinCostTyping(0,i,dp));
        }
        cout<<"Case #"<<i<<":"<<" ";
        cout<<ans<<"\n";
    }
}

/* Div 3 -E (Add modulo 10) */