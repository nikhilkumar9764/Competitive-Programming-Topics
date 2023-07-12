/* given  a 2d grid in which 0 denotes house and 1 denotes vaccination center .
It requires one unit of fuel to go from a cell to another in the grid. 
 find the minimum fuel required for each house to reach the nearest vaccination center . 

 grid : [0, 1, 0
        1, 0, 0
        1, 0, 1]

Solution : Apply bfs from each house to the nearest vaccine center .
 */
  
from collections import deque

def min_fuel(grid):
    n_rows, n_cols = len(grid), len(grid[0])
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    queue = deque()
    fuel = [[float('inf') for _ in range(n_cols)] for _ in range(n_rows)]

    for row in range(n_rows):
        for col in range(n_cols):
            if grid[row][col] == 0:
                queue.append((row, col, 0))
    
    while queue:
        row, col, curr_fuel = queue.popleft()

        if grid[row][col] == 1:
            fuel[row][col] = min(fuel[row][col], curr_fuel)

        for d in directions:
            r, c = row + d[0], col + d[1]
            if r < 0 or r >= n_rows or c < 0 or c >= n_cols:
                continue
            if curr_fuel + 1 < fuel[r][c]:
                fuel[r][c] = curr_fuel + 1
                queue.append((r, c, curr_fuel + 1))
    
    max_fuel = -float('inf')
    for row in range(n_rows):
        for col in range(n_cols):
            if grid[row][col] == 0:
                max_fuel = max(max_fuel, fuel[row][col])
    
    return max_fuel



/*
Given a list of transactions where transaction[I] = [user1, user2] indicates user1 sent money to user2. 
A self transaction is one when user1 sends to user2 and user2 to user1. A series of back to back self transaction is called round
 tripping. Given a list of transaction and queries where queries[I] = [user1, user2] , determine if the transaction is round tripping
 or not . 

 N = 5 
 1 2 
 2 1
 1 3
 2 4
 4 2
 4 5

 Q = 2
 1 5 
 3 5 

 Output : YES , NO

  Idea : DFS to be applied on user1 node and check if node 2 is reachable from node 1.
 */







/*  Given a box of crayons with different colors represented by different alphabets . In one move you remove several continuous 
crayons of the same color . You may perform this several times till box is empty . Each time you choose the crayon set , they must 
be continuous and of the same color . After removing them you will get x*x points . 
  
 ar = [a,b,c,c,c,b,a,b,a] , answer is 21
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
	ll n;
	cin>>n;
	vector<char> v1;
	char x;
	map<char, vector<int>> ma;
	for(int j=0;j<n;j++)
	{
	    cin>>x;
	    v1.push_back(x);
	    ma[x].push_back(j);
	}
	
    	ll score = 0;
	    vector<char> tmp = v1;
	    while(1)
	    {
	        if(tmp.size() == 0)
	        {
	            break;
	        }
	    
    	    ll cc = 0;
    	    ll max_len = 0, least_diff = 10000;
    	    char to_remove ;
    	    for(auto it: ma)
    	    {
    	        char vv = it.first;
    	        vector<int> ss = it.second;
    	        ll cc = 0;
    	        for(int j=0;j<ss.size()-1;j++)
    	        {
    	            cc+=abs(ss[j+1]-ss[j]);
    	        }
    	        if(cc<least_diff && ss.size()>=max_len)
    	        {
    	            max_len = ss.size();
    	            least_diff = cc;
    	            to_remove = it.first;
    	        }
    	    }
    	    vector<int> r1 = ma[to_remove];
    	    if(r1.size() > 1)
    	    {
    	         score+=r1.size()*r1.size();
        	        for(int j=0;j<r1.size()-1;j++)
        	    {
        	        int st=r1[j] , en = r1[j+1];
        	        for(int p=st;j==r1.size()-2 ? p<=en : p<en;p++)
        	        {
        	           if(p>0 && v1[p]!=v1[p-1] && v1[p]!=to_remove)
        	           {
        	               score+=1;
        	           }
        	            auto it = find(ma[v1[p]].begin() ,ma[v1[p]].end() ,p);
            	        ma[v1[p]].erase(it);
            	        if(ma[v1[p]].size() == 0)
            	        {
            	            ma.erase(v1[p]);
            	        }
            	        auto it2 = find(tmp.begin() , tmp.end() , v1[p]);
            	        tmp.erase(it2);
        	        }
        	    }
        	    v1 = tmp;
        	    ma.clear();
        	    for(int i=0;i<v1.size();i++)
        	    {
        	        ma[v1[i]].push_back(i);
        	    }
    	    }
    	    else{
    	        score+=1;
    	        ma[to_remove].clear();
    	        auto it2 = find(tmp.begin() , tmp.end() , to_remove);
            	tmp.erase(it2);
    	    }
	  }
    	cout<<score<<"\n";
}


/* Given some resources in form of a linked list , you have to cancel out all the nodes whose sum up to zero and return the
remaining list */





/* Given a list of integers in an array A , find the number of pairs (i,j) such that A[i]^A[j] > A[i]&A[j] 
To be done in linear time */

#include <bits/stdc++.h>
#define debug cout<< "here" <<'\n';
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define rep(i,a,b) for(int i = a; i <= b; i ++ )
#define per(i,a,b) for(int i = a; i >= b; i -- )
#define aurep(i,u) for(auto& i : u)

typedef long long ll;

using namespace std;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

unordered_map<int,int> vp1;
unordered_map<int,int> vp2;

ll C(int x) {
	if(x <= 0) return 0;
	return 1ll * (x + 1) * x / 2;
}

void solve() {
	int n; cin >> n;	
	rep(i, 1, n) {
		int tmp; cin >> tmp;
		vp1[tmp] = i;
	}
	rep(i, 1, n) {
		int tmp; cin >> tmp;
		vp2[tmp] = i;
	}
	
	int L = min(vp1[1], vp2[1]), R = max(vp1[1], vp2[1]);
	ll ans = C(L - 1) + C(R - L - 1) + C(n - R);
	rep(i, 2, n) {
		int x = vp1[i], y = vp2[i];
		if((x < L && y < L)) {
			ans += 1ll * (n - R + 1) * (L - max(x, y));
		}
		if(x > R && y > R) {
			ans += 1ll * L * (min(x, y) - R);
		}
		if((x < L && y > R) || (x > R && y < L)) {
			ans += 1ll * (L - min(x, y)) * (max(x, y) - R);
		}
		L = min(L, min(x, y));
		R = max(R, max(x, y));
	}	
	cout << ans + 1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0), cout.tie(0);
	int t = 1;// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
