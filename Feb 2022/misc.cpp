/* 
Amazon student program (SDE-1) Hiring -- 
Q1 . A hero is fighting a war . Given a list of stages which can be overcome by going to each one of them and 
then the power of robot reduces by strength at that stage and we are given an armour of power P which we can use at most one stage.
Also at any point of time during the game and after the game the strength of the robot should always be greater than zero.
Determine the minimum power of the robot which should be there at the starting of the game.

Expected time complexity : 1<=N<=10^5

Solution : sort the array and find the sum of the array ,
also find the  lower_bound on the vector for the armour power and answer would be 
sum-val(iterator of lower_bound)+abs(armour-iterator of lower_bound)
*/


/*Q2. Given an array of numbers , determine the minimum no of groups into which the array can be divided such that difference 
between any pair of numbers in any group is atmost K. 
N=7  array = [1,3,5,6,8,9,13] and k = 4

Time complexity : 1<=N<=10^5
                  1<=A[i]<=10^7

Answer : [1,3,5] ,[6,8,9] ,[13] are the 3 minimum no of groups. 

Solution : would be keep incrementing cnt variable and we would be finding until
  el = ar[0]
  while( upper_bound(el+k) != vec.end())
  {
        el = el+k;
        cnt++;
  }
  print(cnt)
*/



/* 
Question : 

Assume english alphabet letters can be given the values as a=1, b=2, c=3 and so on.
Given the two numbers n and k, where n is number of letters and k is the sum of their values, 
find the lexicographically smallest string with n letters and sum of letters as k.
Example 1: Input: n=3, k=27 Output: aay
Example 2: Input: n=5, k=73 Output: aaszz

[ GFG Medium question ] 
 */


/*
   Shortest distance from one node to another using BFS 
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

int main() 
{
    ll n;
    cin>>n;
    
    ll x,y,ww;
    vector<ll> adj[n+1];
    ll wt[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            wt[i][j] = 0;
        }
    }
    
    ll no_edges;
    cin>>no_edges;
    for(int i=0;i<no_edges;i++)
    {
        cin>>x>>y>>ww;
        adj[x].push_back(y);
        wt[x][y] = ww;
    }
     
    bool vis[n+1] = {false};
    ll dis[n+1];
    for(int i=1;i<=n;i++)
    {
        dis[i] = INT_MAX;
    }

ll st,en;
cin>>st>>en;
dis[st] = 0;
queue<int> q;
q.push(st);
vis[st] = true;

  while(!q.empty())
  {
    auto it = q.front();
    q.pop();
    for(auto pt:adj[it])
    {
      if(!vis[pt])
      { 
        vis[pt] = true;
        q.push(pt);
      }
        dis[pt] = min(dis[pt],wt[it][pt] + dis[it]);
    } 
  }
  
  for(int i=1;i<=n;i++)
  {
      cout<<dis[i]<<" ";
  }
  cout<<"\n";

}

/* Maximum sum path in 2 arrays */

#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
using ll = long long int;
ll dp[1048576][10] = {0};

int main()
{
    ll n,m;
    cin>>n>>m;
    ll ar[n],br[m];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>br[i];
    }
    ll su1=0,su2=0;
    ll su=0;
    ll i = 0,j=0;
    while(i<n && j<m)
    {
        if(ar[i]<br[j])
        {
            su1+=ar[i];
            i++;
        }
        else if(br[j]<ar[i])
        {
            su2+=br[j];
            j++;
        }
        else if(ar[i]==br[j])
        {
            su+=max(su1,su2);
            su+=ar[i];
            su1=0;
            su2=0;
            i++;
            j++;
        }
    }
    
    while(i<n)
    {
        su1+=ar[i];
        i++;
    }
    
    while(j<m)
    {
        su2+=br[j];
        j++;
    }
    
    su+=max(su1,su2);
    cout<<su<<"\n";
}


/* Longest pallindromic subsequence */
#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
using ll = long long int;
ll dp[1048576][10] = {0};

int main()
{
    string s ;
    cin>>s;
    ll si = s.size();
    ll dp[si][si];
    for(int i=0;i<si;i++)
    {
        for(int j=0;j<si;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<si;i++)
    {
        dp[i][i] = 1;
    }
    for(int len=2;len<=si;len++)
    {
        for(int i=0;i<(si-len+1);i++)
        {
            int j=i+len-1;
            if(s[i] == s[j] && len==2)
            {
                dp[i][j] = 2;
            }
            else if(s[i]==s[j])
            {
                dp[i][j] = 2+dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][si-1]<<"\n";
}


#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
using ll = long long int;
ll dp[1048576][10] = {0};

// Preorder , post order and inorder traversal
struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};

// void preorder(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }


void all_traversal(Node* root)
{
    vector<int> post,pre,in;
    stack<pair<Node*,int>> stck;
    int ty = 1;
    stck.push({root,ty});
    while(!stck.empty())
    {
        auto it = stck.top();
        stck.pop();
        int t1 = it.second;
        if(t1 == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            stck.push(it);
            if(it.first->left)
            {
                stck.push({it.first->left,1});
            }
        }
        else if(t1==2)
        {
            in.push_back(it.first->data);
            it.second++;
            stck.push(it);
            if(it.first->right)
            {
                stck.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    
    for(auto it : pre)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
     for(auto it : in)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    
    for(auto it : post)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
      Node* root = new Node(1);
      root->left = new Node(5);
      root->left->left = new Node(3);
      root->left->right = new Node(7);
      root->right = new Node(8);
      root->right->right = new Node(9);
      all_traversal(root);
}

/* Find the Maximum k frequency elements in a stream */

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
	ll n,k;
	cin>>n>>k;
	ll ar[n];
	for(int i=0;i<n;i++)
	{
	    cin>>ar[i];
	}
	
	priority_queue<pair<int,int>> pq;
	map<int,int> ma;
	for(int i=0;i<n;i++)
	{
	   ma[ar[i]]++;
	}
	
	for(auto it : ma)
	{
	    pq.push({it.second,it.first});
	}
	
	while(!pq.empty() && k>0)
	{
	    cout<<pq.top().second<<" ";
	    pq.pop();
	    k-=1;
	}
}

// Print LCA of 2 nodes in a binary tree 

/* Store the path from the root to the nodes and then find the first uncommon node in their paths
and print the one just before the uncommon node */




/* Print all nodes at k distance from a target node */
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

Node* newNode(int val)
{
	Node* tmp = new Node();
	tmp->data = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void markParents(Node* root,unordered_map<Node*,Node*> &ma)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
	    auto el = q.front();
	    q.pop();
	    if(el->left !=NULL)
	    {
	    	ma[el->left] = el;
	    	q.push(el->left);
	    }
	    if(el->right !=NULL)
	    {
	    	ma[el->right] = el;
	    	q.push(el->right);
	    }
	}
}

vector<int> get_nodes_level(Node* root,Node* target, int k)
{
   unordered_map<Node*,Node*> ma;
   markParents(root,ma);
   queue<Node*> q;
   set<Node*> se;
   q.push(target);
   se.insert(target);
   int curr_level = 0;
   while(!q.empty())
   {
       if(curr_level == k)
	     {
	   	    break;
	     }
   	   int sz = q.size();
   	   for(int j=0;j<sz;j++)
   	   {
   	     auto el = q.front();
	     q.pop();
	     
	     if(el->left && se.find(el->left)==se.end())
	     {
	        se.insert(el->left);
	        q.push(el->left);
	     }
	     if(el->right  && se.find(el->right)==se.end())
	     {
	        se.insert(el->right);
	        q.push(el->right);
	     }
	     if(ma[el] && se.find(ma[el])==se.end())
	     {
	   	   se.insert(ma[el]);
	       q.push(ma[el]);
	     }
   	   }
   	    curr_level++;
   }
    vector<int> res;
   while(!q.empty())
   {
      auto it = q.front();
   	  res.push_back(it->data);
   	  q.pop();
   }
   return res;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->left->right->left = newNode(5);
	root->right = newNode(2);
	root->right->right = newNode(7);
	root->right->left = newNode(8);
	Node* targ = root->left;
	int k;
	cin>>k;
	vector<int> r1 = get_nodes_level(root,targ,k);
	for(auto i : r1)
	{
	    cout<<i<<" ";
	}
	cout<<"\n";
}

