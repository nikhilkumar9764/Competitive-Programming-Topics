/* KMP String matching algorithm */
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

int main() 
{
    string txt, pat;
    cin>>txt>>pat;
    ll s1 = pat.size();
    ll lps[s1+1] = {0};
    ll len = 0,i=1;
    while(i<s1)
    {
    	if(pat[len] == pat[i])
    	{
    		len++;
    		lps[i] = len;
    		i++;
    	}
    	else{
    		if(len!=0)
    		{
    			len = lps[len-1];
    		}
    		else{
    			lps[i] = 0;
    			i++;
    		}
    	}
    }
    ll s2 = txt.size();
    ll p = 0,q=0;
    while((s2-p)>=(s1-q))
    {
    	 if(txt[p] == pat[q])
    	 {
    	 	 p++;
    	 	 q++;
    	 }
    	 if(q == s1)
    	 {
    	 	cout<<"Found at position : "<<p-q<<"\n";
    	 	q = lps[q-1];
    	 }
    	 else if(p<s2 && txt[p]!=pat[q])
    	 {
    	 	if(q!=0)
    	 	{
    	 		q = lps[q-1];
    	 	}
    	 	else{
    	 		p++;
    	 	}
    	 }
    }
}


/* z- alogrithm */





/* Sum of scores of built strings */

class Solution {
public:
    int Z[100005];
    long long sumScores(string str) 
    {
        int n = str.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;

            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            
            k = i-L;
 

            if (Z[k] < R-i+1)
                Z[i] = Z[k];
 
            
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
     }
        
      long long sc = 0;
        for(int i=0;i<=n;i++)
        {
            sc+=Z[i];
        }
        return sc+n;
    }
};

/* Biweekly 86 -- hard problem : last D problem*/

class Solution {
public:
    using ll =long long;
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
          int sz = chargeTimes.size();
          int i=0,j=0;
        ll cost = 0;
        deque<int> dq;
        ll ans = 0 , val = 0;
        while(j<sz)
        {
            cost+=runningCosts[j];
            while(!dq.empty() && dq.back()<chargeTimes[j])
            {
                dq.pop_back();
            }
            dq.push_back(chargeTimes[j]);
            
            val = (j-i+1)*cost + dq.front();
            cout<<val<<"\n";
            if(val<=budget)
            {
                ll pos = (j-i+1);
                ans = max(ans,pos);
            }
            else{
                while(val>budget)
                {
                    cost=cost-runningCosts[i];
                    if(chargeTimes[i] == dq.front())
                    {
                        dq.pop_front();
                    }
                     i++;
                    val = (j-i+1)*cost + dq.front();
                }
            }
            j++;
        }
        return ans;
    }
};

/* 2392. Build a Matrix With Conditions (LC hard) */

class Solution {
public:
    
    vector<int> topoSort(int V, vector<int> adj[], vector<int> &ans) 
	{
	    queue<int> q;
	    vector<int> indeg(V+1,0);
	    for(int i=1; i<=V; i++){
	        for(int c : adj[i])
	            indeg[c]++;
	    }
	    for(int i=1; i<=V; i++){
	        if(indeg[i]==0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int x = q.front(); q.pop();
	        ans.push_back(x);
	        for(int c: adj[x]){
	            if(--indeg[c] == 0){
	                q.push(c);
	            }
	        }
	    }
	    return ans;
	}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int> graph1[k+1];
        vector<int> graph2[k+1];
        
        for(auto x:rc) {
            graph1[x[0]].push_back(x[1]);
        }
        for(auto x:cc) {
            graph2[x[0]].push_back(x[1]);
        }
        vector<int> ans1; 
        vector<int> ans2;
        
        topoSort(k, graph1, ans1);
        topoSort(k, graph2, ans2);
    
        if(ans1.size() != k or ans2.size() != k) return {};
        
        vector<vector<int>> ans(k, vector<int>(k));
        
        map<int, int> m;
        for(int i = 0; i < k; i++) {
            m[ans2[i]] = i;
        }
        
        for(int i = 0; i < k; i++) {
            ans[i][m[ans1[i]]] = ans1[i];
        }
        
        return ans;
    }
};


// Stephen is doing an internship for N days . On each day he is paid x for easy and y for hard task. On a given day if he does hard
// task only if he has done no task on previous day . The hard task money is always more than easy task.


#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll maxn = 2e5+8;

int main() 
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        ll num;
        cin>>num;
        vector<pair<pair<ll,ll>,ll>> vp;
        ll x,y,z;
        for(int i=0;i<num;i++)
        {
            cin>>x>>y>>z;
            vp.push_back({{x,y},z});
        }
        ll ar[m+1][n+1] = {0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<num;k++)
                {
                    ll v1 = vp[k].first.first;
                    ll v2 = vp[k].first.second;
                    ll rr = vp[k].second;
                    if(sqrt(pow(abs(v1-i-1),2) + pow(abs(v2-j-1),2)) <=rr)
                    {
                        ar[i][j]=-1;
                    }
                }
            }
        }
        if (rect[0][0] == -1)
        return false;
 
    vector<vector<int> > qu;
 
    rect[0][0] = 1;
    qu.push_back({ 0, 0 });
 
    // Discover cells until queue is not empty
    while (!qu.empty()) {
        vector<int> arr = qu.front();
        qu.erase(qu.begin());
        int elex = arr[0];
        int eley = arr[1];
 
        // Discover the eight adjacent nodes.
        // check top-left cell
        if ((elex > 0) && (eley > 0)
            && (rect[elex - 1][eley - 1] == 0)) {
            rect[elex - 1][eley - 1] = 1;
            vector<int> v = { elex - 1, eley - 1 };
            qu.push_back(v);
        }
 
        // check top cell
        if ((elex > 0) && (rect[elex - 1][eley] == 0)) {
            rect[elex - 1][eley] = 1;
            vector<int> v = { elex - 1, eley };
            qu.push_back(v);
        }
 
        // check top-right cell
        if ((elex > 0) && (eley < n - 1)
            && (rect[elex - 1][eley + 1] == 0)) {
            rect[elex - 1][eley + 1] = 1;
            vector<int> v = { elex - 1, eley + 1 };
            qu.push_back(v);
        }
 
        // check left cell
        if ((eley > 0) && (rect[elex][eley - 1] == 0)) {
            rect[elex][eley - 1] = 1;
            vector<int> v = { elex, eley - 1 };
            qu.push_back(v);
        }
 
        // check right cell
        if ((eley < n - 1) && (rect[elex][eley + 1] == 0)) {
            rect[elex][eley + 1] = 1;
            vector<int> v = { elex, eley + 1 };
            qu.push_back(v);
        }
 
        // check bottom-left cell
        if ((elex < m - 1) && (eley > 0)
            && (rect[elex + 1][eley - 1] == 0)) {
            rect[elex + 1][eley - 1] = 1;
            vector<int> v = { elex + 1, eley - 1 };
            qu.push_back(v);
        }
 
        // check bottom cell
        if ((elex < m - 1) && (rect[elex + 1][eley] == 0)) {
            rect[elex + 1][eley] = 1;
            vector<int> v = { elex + 1, eley };
            qu.push_back(v);
        }
 
        // check bottom-right cell
        if ((elex < m - 1) && (eley < n - 1)
            && (rect[elex + 1][eley + 1] == 0)) {
            rect[elex + 1][eley + 1] = 1;
            vector<int> v = { elex + 1, eley + 1 };
            qu.push_back(v);
        }
    }
 
    // Now if the end cell (i.e. bottom right cell)
    // is 1(reachable) then we will send true.
    return (rect[m - 1][n - 1] == 1);
    }
}




/* -> There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;
-> At each index you are supposed to pick up an element either from array 'C' or array 'B'
->You have to maximize the final sum of all elements

->Condition : You cannot select 3 or more than 3 element consecutively from the same array.

Example :

3
5 10
3 10
4 10

Output : 25
1<=N<=100000
1<=B[i];C[i]<=10000000000
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll dp[100000+5][5][5];

ll mxi(ll x,ll y,ll z){
    
    
    return max(x,max(y,z));
    
}

ll mx(ll x,ll y,ll z,ll g){
    
    return max(max(x,g),max(y,z));
}

int main() {
    
    ll n;
    cin>>n ; 
    
    ll i = 1 ; ll b[n+1] = {0};
    ll d[n+1] = {0};
    while(i<=n){
        cin>>b[i];
        cin>>d[i];
        i++;
    }
    
    //base-cases
    dp[1][1][1] = b[1] ; 
    dp[1][1][2] = b[1] ; 
    dp[1][2][1] = d[1] ; 
    dp[1][2][2] = d[1] ; 
    
    
    //dp[index][][]
    
    
    i = 2 ; 
    while(i<=n){
        
        dp[i][1][1] = b[i] + b[i-1] + max(dp[i-2][2][2],dp[i-2][2][1]);
        dp[i][1][2] = b[i] + d[i-1] + mxi(dp[i-2][1][1],dp[i-2][1][2],dp[i-2][2][1]);
        dp[i][2][1] = d[i] + b[i-1] + mxi(dp[i-2][2][1],dp[i-2][2][2],dp[i-2][1][2]);
        dp[i][2][2] = d[i] + d[i-1] + max(dp[i-2][1][2],dp[i-2][1][1]);
        
        i++;
    }
    
    cout<<mx(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1]); 
    return 0 ; 
}

