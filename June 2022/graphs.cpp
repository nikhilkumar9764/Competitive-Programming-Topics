/* SRIB SW pro competency test question 

Given T test cases and in each test case n micrococussi are there and for each of them which are in circular form , center is given
(xi,yi) and their radii (ri) is given . In the given network find the network with largest intersecting micrococussi either overlapping 
or intersecting at a point on the circle and if 2 networks have same no of intersecting circles print the network with lower circle ID present 
in them.

Expected time complexity :    1<=N <=5*10^4  --> O(N) time complexity

Idea : Find the number of strongly connected components using DFS and simultaneously compute the no of elements in the largest 
network and smallest ID in that network component.

N = 5            
10 5 3
6 5 1
10 11 3
15 5 2
3 5 2

Output : 5 1  (output the network with largest no of nodes and smallest id of the node)
*/ 

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void dfs(vector<pair<pair<ll,ll>,ll>> v1, vector<bool> &vis, ll curr,ll &cnt,ll &node)
{
    vis[curr] = true;
    ll x1 = v1[curr-1].first.first , y1 = v1[curr-1].first.second , r1 = v1[curr-1].second;
    for(int i=1;i<=v1.size();i++)
    {
        if(i!=curr && !vis[i])
        {
            ll x2= v1[i-1].first.first , y2 = v1[i-1].first.second , r2 = v1[i-1].second;
            ll d1 = pow((x1-x2),2) + pow((y1-y2),2);
            ll d2 = (r1-r2)*(r1-r2);
            if(d1<=d2)
            {
                cnt++;
                ll vv = i;
                node = min(node,vv);
                dfs(v1,vis,i,cnt,node);
            }
        }
    }
}

int main() 
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       vector<pair<pair<ll,ll>,ll>> v1;
       ll x,y,r;
       for(int i=0;i<n;i++)
       {
           cin>>x>>y>>r;
           v1.push_back({{x,y},r});
       }
       vector<bool> vis(n+2);
       for(int j=0;j<n+2;j++)
       {
           vis[j] = false;
       }
       
       ll max_cnt = 0 , smallest_id = INT_MAX;
       vector<pair<ll,ll>> res;
       for(int j=1;j<=n;j++)
       {
           if(!vis[j])
           {
               ll cc = 0;
               ll node = INT_MAX;
               dfs(v1, vis, j ,cc,node);
               res.push_back({cc,node});
           }
       }
       for(auto it : res)
       {
           cout<<it.first<<" "<<it.second<<"\n";
       }
       cout<<"\n";
   }
}





/* Amazon SDE-1 Hackerearth OA question 
Given a tree of N nodes whose vertices are numbered from 1 to N. We need to remove two edges from tree to form three 
connected components. And we want to minimize the difference of maximum of xors and minimum of xors of the vertices of the
 connected components.
For eg. our graph is as follows:
N= 4
Edges E are as follows:
1 2
2 3
4 1
if we remove 2-3 and 1-2 then are connected components are:
2 (xor = 2)
3 (xor=3)
1-4 (xor=5)
and then for for this case difference of xors is max(2,3,5) - min(2,3,5) = 5 - 2 = 3 and we need to minimize this difference.

First line of input is T = number of test cases. Then for each test case we take input N = number of vertices, then following N-1 lines takes input for edges of the tree.

Constraints:
1<=T<=10
N<=3000 

Idea : Calculate subtree xor at each vertex for its subtree 
*/


Let's try to divide the problem into sub-problems, since N is in the range of 10^3, we can use O(N^2) approach here.

Let's check each pair of the vertex as the root of each connected component and the remaining tree be the third component.

But now the problem is how to find the xor of the components?

We could just find the xor of the current pairs and we could then use the xor of the whole tree to find the xor of the remaining tree.

Find the Xor of each subtree
void dfs(int curr, int par) {
    inTime[curr] = ++currTime;
    subtreeXor[curr] = curr;
    
    for(auto child : adj[curr]) {
        if(child != par) {
           dfs(child, curr);
           subtreeXor[curr] ^= subtreeXor[child];
        }
    }
    
    outTime[curr] = ++currTime;
}
For each pair of vertex, each being in the different connected component, find the xor of third component
    dfs(1, -1);
    int xorTree = subtreeXor[1];
    int ans = INT_MAX;
    for(int i = 2; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int a, b, c;
            
            if(!sameSubtree(i, j) && !sameSubtree(j, i)) {
                a = subtreeXor[i], b = subtreeXor[j];
            } else if(sameSubtree(i, j)) {
                a = subtreeXor[j], b = (a ^ subtreeXor[i]);
            } else if(sameSubtree(j, i)) {
                a = subtreeXor[i], b = (a ^ subtreeXor[j]);
            }
            
            c = (xorTree ^ a ^ b);
            ans = min(ans, max({a, b, c}) - min({a, b, c}));
        }
    }
Check in constant time whether a vertex lies in subtree of other vertex.
// b is in subtree of a.
bool sameSubtree(int a, int b) {
    return (inTime[a] <= inTime[b]) && (outTime[b] <= outTime[a]);
}


/*A Tree can be defined as an undirected acyclic graph , with nodes numbered froom 0 to n-1,
 The tree is described in an array of parents where each parents[i] is the parent node for node i .
  The root node 0 has no parent, indicated by parent[0] = -1,

Each node has a value equal to the node number . These values are to be summed over the course of a tree traversal . Start at some node, StartPoint[i] . Then jump up the tree by a number of levels , jumpLength[i] , collecting values at each node visited until there are not jumplength[i] levels remaining . For a list of queries, each with a startPoint[i] and jumpLength[i] , determine the sum of the values of visited nodes along the path, Return a list of integer answers in query order.
Sample Input
6
[-1,0,1,1,2,4]
2
startPoint[] : 5 4
2
jumpLength[] : 1 2
image

Sample Output
12
5   */





/* Find Count of Single Valued Subtrees

Given a binary tree, write a program to count the number of Single Valued Subtrees.
 A Single Valued Subtree is one in which all the nodes have same value. Expected time complexity is O(n).

Example: 
Input: root of below tree
              5
             / \
            1   5
           / \   \
          5   5   5
Output: 4
There are 4 subtrees with single values.


Input: root of below tree
              5
             / \
            4   5
           / \   \
          4   4   5                
Output: 5
There are five subtrees with single values.  */

class Solution
{
    public:
    
    bool count_nodes(Node *root,int &cc)
    {
          if(root == NULL)
          {
              return true;
          }
          
          bool left_exists = count_nodes(root->left,cc);
          bool right_exists = count_nodes(root->right,cc);
          
          if(left_exists== false || right_exists==false)
          {
              return false;
          }
          
          if(root->left && root->left->data!=root->data)
          {
              return false;
          }
          
          if(root->right && root->right->data!=root->data)
          {
              return false;
          }
          cc++;
          return true;
    }
    
    
    int singlevalued(Node *root)
    {
        int cc =0;
        count_nodes(root,cc);
        return cc;
    }
    
};



