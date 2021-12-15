/*
Print all paths having sum k in a binary tree (the elements need not be root or leaf)
The paths should all be downwards only. 
*/
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// struct Node{
//    int data;

//    Node* left;
//    Node* right;
// };

// Node* newNode(int val)
// {
//     Node* x = new Node();
//     x->data = val;
//     x->left = NULL;
//     x->right = NULL;
//     return x;
// }

// void inorder(Node* root)
// {
//     if(!root)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// void print_path(vector<ll> &ans,ll i)
// {
//     for(int j=i;j<ans.size();j++)
//     {
//         cout<<ans[j]<<" ";
//     }
//     cout<<"\n";
// }

// void print_k_sum(Node *root ,ll k,vector<ll> &vp)
// {
//       if(root == NULL)
//       {
//           return;
//       }
//       vp.push_back(root->data);
//       print_k_sum(root->left,k,vp);
//       print_k_sum(root->right,k,vp);
//       ll su = 0;
//       for(int p=vp.size()-1;p>=0;p--)
//       {
//           su+=vp[p];
//           if(su == k)
//           {
//               print_path(vp,p);
//           }
//       }
//       vp.pop_back();
// }

// int main()
// {
//     Node* root = newNode(1);
//     root->left = newNode(3);
//     root->left->left = newNode(2);
//     root->left->right = newNode(1);
//     root->left->right->left = newNode(1);
//     root->right = newNode(-1);
//     root->right->left = newNode(4);
//     root->right->left->left = newNode(1);
//     root->right->left->right = newNode(2);
//     root->right->right = newNode(5);
//     root->right->right->right = newNode(2);
//     ll k;
//     cin>>k;
//     vector<ll> an;
//     print_k_sum(root,k,an);
// }

/* Print all the ancestor of a given node in a binary tree */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// struct Node{
//    int data;
//    Node* left;
//    Node* right;
// };

// Node* newNode(int val)
// {
//     Node* x = new Node();
//     x->data = val;
//     x->left = NULL;
//     x->right = NULL;
//     return x;
// }

// void inorder(Node* root)
// {
//     if(!root)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// void print_path(vector<ll> &ans,ll i)
// {
//     for(int j=i;j<ans.size();j++)
//     {
//         cout<<ans[j]<<" ";
//     }
//     cout<<"\n";
// }

// bool print_ancestors(Node *root ,ll target)
// {
//       if(root == NULL)
//       {
//           return false;
//       }
//       if(root->data == target)
//       {
//           return true;
//       }
//       if(print_ancestors(root->left,target) || print_ancestors(root->right,target))
//       {
//           cout<<root->data<<" ";
//            return true;
//       }
//       return false;
// }

// int main()
// {
//     Node* root = newNode(2);
//     root->left = newNode(4);
//     root->left->left = newNode(5);
//     root->left->right = newNode(6);
//     root->left->right->left = newNode(1);
//     root->right = newNode(-1);
//     root->right->left = newNode(7);
//     root->right->left->left = newNode(10);
//     root->right->left->right = newNode(11);
//     root->right->right = newNode(8);
//     root->right->right->right = newNode(12);
//     ll k;
//     cin>>k;
//     vector<ll> an;
//     print_ancestors(root,k);
// }

/*Print the maximum sum between any 2 leaf nodes in a binary tree */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// struct Node{
//    int data;
//    Node* left;
//    Node* right;
// };

// Node* newNode(int val)
// {
//     Node* x = new Node();
//     x->data = val;
//     x->left = NULL;
//     x->right = NULL;
//     return x;
// }

// void inorder(Node* root)
// {
//     if(!root)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// void print_path(vector<ll> &ans,ll i)
// {
//     for(int j=i;j<ans.size();j++)
//     {
//         cout<<ans[j]<<" ";
//     }
//     cout<<"\n";
// }

// ll max_sum_between_leaves(Node *root ,ll &ans)
// {
//      if(root == NULL)
//      {
//         return 0;
//      }
//      if(!max_sum_between_leaves(root->left,ans) && !max_sum_between_leaves(root->right,ans))
//      {
//          return root->data;
//      }
//      ll lef_ht = max_sum_between_leaves(root->left,ans);
//      ll right_ht = max_sum_between_leaves(root->right,ans);
     
//      if(root->left && root->right)
//      {
//           ans = max(ans , lef_ht+right_ht+root->data);
//           return max(lef_ht,right_ht)+root->data;
//      }
    
//     return (!root->left) ? right_ht+root->data:lef_ht+root->data;
// }

// int main()
// {
//     Node* root = newNode(2);
//     root->left = newNode(4);
//     root->left->left = newNode(5);
//     root->left->right = newNode(6);
//     root->left->right->left = newNode(1);
//     root->right = newNode(-1);
//     root->right->left = newNode(7);
//     root->right->left->left = newNode(10);
//     root->right->left->right = newNode(11);
//     root->right->right = newNode(8);
//     root->right->right->right = newNode(12);
//     ll su = 0;
//     max_sum_between_leaves(root,su);
//     cout<<su<<"\n";
// }

/* Print all the path from root which has a specified sum */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

struct Node{
   int data;
   Node* left;
   Node* right;
};

Node* newNode(int val)
{
    Node* x = new Node();
    x->data = val;
    x->left = NULL;
    x->right = NULL;
    return x;
}

void inorder(Node* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void print_path(vector<ll> &ans)
{
    for(int j=0;j<ans.size();j++)
    {
        cout<<ans[j]<<" ";
    }
    cout<<"\n";
}

void print_path_sum_k(Node *root ,vector<ll> &an,ll target)
{
    if(root == NULL)
    {
        return;
    }
    an.push_back(root->data);
    print_path_sum_k(root->left,an,target);
    print_path_sum_k(root->right,an,target);
    ll su = 0;
    for(int i=an.size()-1;i>=0;i--)
    {
        su+=an[i];
    }
    if(su == target)
    {
        print_path(an);
    }
    an.pop_back();
}

int main()
{
    Node* root = newNode(2);
    root->left = newNode(2);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(7);
    root->right->left->left = newNode(10);
    root->right->left->right = newNode(11);
    root->right->right = newNode(8);
    root->right->right->right = newNode(12);
    ll k;
    cin>>k;
    vector<ll> an;
    print_path_sum_k(root,an,k);
}