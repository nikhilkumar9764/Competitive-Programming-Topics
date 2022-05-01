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

/* GFG Question : 
Given an array of integers having size N , find a subsequence of length M such that minimum difference between any 2 pair 
of integers is maximum. 

Can be solved in NlogN time using Binary search.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool can_place(ll ar[],ll n,ll b,ll vv)
{
    ll curr = ar[0];
    ll cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(abs(ar[i]-curr)>=vv)
        {
            curr = ar[i];
            cnt++;
        }
        if(cnt == b)
        {
            return true;
        }
    }
    return false;
}

int main()
{
	ll n,b;
	cin>>n>>b;
	ll ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+n);
	ll low = 0,hi =*max_element(ar,ar+n);
	ll ans = -1;
	while(low<=hi)
	{
	    ll mid = (low+hi)/2;
	    if(can_place(ar,n,b,mid))
	    {
	        ans = mid;
	        low = mid+1;
	    }
	    else{
	        hi = mid-1;
	    }
	}
	cout<<"Answer is :"<<ans<<"\n";
}
