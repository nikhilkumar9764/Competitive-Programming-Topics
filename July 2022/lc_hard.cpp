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