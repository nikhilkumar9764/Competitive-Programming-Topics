/*
Binary search tree related operations (Insert , print , delete, search) */
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

// Node* insert(Node* root, int val)
// {
//     if(root == NULL)
//     {
//         root = newNode(val);
//     }
//    else if(root->data<=val)
//     {
//         root->right = insert(root->right,val);
//     }
//     else
//     {
//         root->left = insert(root->left,val);
//     }
//     return root;
// }

// bool search_node(Node* root, int val)
// {
//     if(root == NULL)
//     {
//         return false;
//     }
//     if(root->data == val)
//     {
//         return true;
//     } 
//     else if(val<=root->data)
//     {
//         return search_node(root->left,val);
//     }
//     else{
//         return search_node(root->right,val);
//     }
// }

// Node* find_min(Node* root)
// {
//     Node* temp = root;
//     while(temp && temp->left!=NULL)
//     {
//         temp = temp->left;
//     }
//     return temp;
// }

// Node* delete_node(Node* root , int val)
// {
//     if(root == NULL)
//     {
//         return root;
//     }

//     if(val<root->data)
//     {
//        root->left = delete_node(root->left,val);
//     }
//     else if(val>root->data)
//     {
//         root->right = delete_node(root->right,val);
//     }
//     else{
//          // right and left are to be NULL
//          if(root->right== NULL && root->left ==NULL)
//          {
//              return NULL;
//          }
//          else if(root->left == NULL) // only right child
//          {
//              Node* tmp = root->right;
//              delete root;
//              return tmp;
//          }
//          else if(root->right == NULL)
//          {
//              Node* tmp = root->left;
//              delete root;
//              return tmp;
//          }
//          else{
//              Node* vv = find_min(root->right);
//              root->data = vv->data;
//              root->right = delete_node(root->right,vv->data);
//          }
//     }
//     return root;
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

// int main()
// {
//     Node* root = NULL;
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root =  insert(root, 80);
//     inorder(root);
//     cout<<"\n";

//     ll el;
//     cin>>el;
//     if(search_node(root,el))
//     {
//         cout<<"Element found in the tree\n";
//     }
//     else{
//         cout<<"Element not found in the tree\n";
//     }

//     int vp;
//     cin>>vp;
//     root = delete_node(root,vp);
//     inorder(root);
// }


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

// Node* insert(Node* root, int val)
// {
//     if(root == NULL)
//     {
//         root = newNode(val);
//     }
//    else if(root->data<=val)
//     {
//         root->right = insert(root->right,val);
//     }
//     else
//     {
//         root->left = insert(root->left,val);
//     }
//     return root;
// }


// void level_order(Node* root)
// {
//     queue<Node*> q;
//     q.push(root);
    
//     while(!q.empty())
//     {
//        Node* vv = q.front();
//        int vp = vv->data;
//        cout<<vp<<" ";
//        q.pop();
//        q.push(vv->left);
//        q.push(vv->right);
//     }
// }

// void zig_zag_order(Node* root)
// {
//     queue<Node*> q;
//     q.push(root);
//     ll tmp =0;
//     vector<vector<int>> res;
//     while(!q.empty())
//     {
//       vector<int> v;
//       tmp++;
//       int sz = q.size();
//       cout<<sz<<"\n";
//       for(int i=0;i<sz;i++)
//       {
//           Node* vv = q.front();
//           int vp = vv->data;
//           v.push_back(vp);
//           q.pop();
//           if(vv->left!=NULL)
//           {
//              q.push(vv->left);
//           }
//           if(vv->right!=NULL)
//           {
//              q.push(vv->right);
//           }
//       }
//       if(tmp%2 == 0)
//       {
//           reverse(v.begin(),v.end());
//       }
//       res.push_back(v);
//       v.clear();
//     }
//     cout<<res.size()<<"\n";
//     int sa = res.size();
//     for(int i=0;i<sa;i++)
//     {
//         for(int j=0;j<res[i].size();j++)
//         {
//             cout<<res[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
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

// int main()
// {
//     Node* root = NULL;
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root =  insert(root, 80);
//     inorder(root);
//     cout<<"\n";
//     zig_zag_order(root);
// }

/*
Printing the diagonal wise traversal of the tree
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

// Node* insert(Node* root, int val)
// {
//     if(root == NULL)
//     {
//         root = newNode(val);
//     }
//    else if(root->data<=val)
//     {
//         root->right = insert(root->right,val);
//     }
//     else
//     {
//         root->left = insert(root->left,val);
//     }
//     return root;
// }

// void print_diag(Node* root,ll lev,map<ll,vector<ll>> &diag)
// {
//     if(!root)
//     {
//         return;
//     }
//     diag[lev].push_back(root->data);
//     print_diag(root->left,lev+1,diag);
//     print_diag(root->right,lev,diag);
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

// int main()
// {
//     Node* root = NULL;
//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 70);
//     root = insert(root, 60);
//     root =  insert(root, 80);
//     inorder(root);
//     cout<<"\n";
//     map<ll,vector<ll>> da;
//     print_diag(root,0,da);
//     for(auto it : da)
//     {
//         ll sz = it.second.size();
//         for(int i=0;i<sz;i++)
//         {
//             cout<<it.second[i]<<" ";
//         }
//         cout<<"\n";
//     }
// }

/* Boundary traversal of a binary tree */
// class Solution {
// public:
//    void left_boundary(Node *root , vector<int> &p)
//    {
//        if(root == NULL || root->left==NULL && root->right ==NULL)
//        {
//            return;
//        }
//        p.push_back(root->data);
//        if(root->left)
//        {
//            left_boundary(root->left,p);
//        }
//        else{
//            left_boundary(root->right,p);
//        }
//    }
    
//    void leaves_boundary(Node *root , vector<int> &x)
//    {
//        if(root == NULL)
//        {
//            return;
//        }
//        if(root->left==NULL && root->right ==NULL)
//        {
//            x.push_back(root->data);
//            return;
//        }
//        leaves_boundary(root->left,x);
//        leaves_boundary(root->right,x);
//    }   
    
//    void right_boundary(Node *root , vector<int> &vp)
//    {
//         if(root == NULL || root->left==NULL && root->right ==NULL)
//        {
//            return;
//        }
//        vp.push_back(root->data);
//        if(root->right)
//        {
//           right_boundary(root->right,vp);
//        }
//        else{
//           right_boundary(root->left,vp);
//        }
//    } 
   
//     vector <int> boundary(Node *root)
//     {
//         vector<int> res;
//         vector<int> xy;
//         res.push_back(root->data);
//         left_boundary(root->left,res);
//         leaves_boundary(root,res);
//         right_boundary(root->right,xy);
//         reverse(xy.begin(),xy.end());
//         for(auto it : xy)
//         {
//             res.push_back(it);
//         }
//         return res;
//     }
// };

