/* OA assesment question : Given an array of N candles and capcacity of each candle is K i.e it can light candles 
from i-k to i+k . Find the minimum no of candles to light up such that entire row gets lit up.

*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Node {
   int data;
   struct Node* right;
   struct Node* left;
};

Node* newNode(int dat)
{
    Node* tmp = new Node();
    tmp->data = dat;
    tmp->left = tmp->right = NULL;
    return tmp;
}

int get_sum(Node* root, int &r1)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root-> left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int ls = get_sum(root->left, r1);
    int rs = get_sum(root->right, r1);
    if(root->left && root->right)
    {
        r1 = max(r1, root->data+ls+rs);
        return max(ls,rs)+root->data;
    }
    if(root->left == NULL)
    {
        return rs+root->data;
    }
    if(root->right == NULL)
    {
        return ls+root->data;
    }
}

int maxSum(Node* root)
{
    int val = INT_MIN;
    int r1 = get_sum(root,val);
    if(val == INT_MIN)
    {
        return r1;
    }
    return val;
}

int main()
{
   struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is "<< maxSum(root)<<"\n";
}
