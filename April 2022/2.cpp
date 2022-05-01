/* 
How many integer sequences of length N, A=(A[1] ,…,A[N]), satisfy all of the conditions below
1≤A[i]≤M (1≤i≤N)

i=1
∑  A[i] ≤K
​N

Since the count can get enormous, find it modulo 998244353.
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) 998244353

int main()
{
    ll n,m,K;
    cin>>n>>m>>K;
    ll dp[n+1][K+1];
    for(int i=0;i<=n;i++)
    {
        for(int k=0;k<=K;k++)
        {
            dp[i][k] = 0;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1)
            {
                dp[i][j] = 1;
            }
            else{
                for(int k=0;k<K;k++)
                {
                    if(j+k<=K)
                    {
                        dp[i][j+k]= (dp[i][j+k]+dp[i-1][k])%MOD;
                    }
                }
            }
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int k=0;k<=K;k++)
        {
            cout<<dp[i][k]<<" ";
        }
        cout<<"\n";
    }
    
    ll ans = 0;
    for(int j=1;j<=K;j++)
    {
        ans= (ans+dp[n][j])%MOD;
    }
    cout<<ans<<"\n";
}

/* Codejam 2022 Qualification Round -- Problem D (Chain Reactions) 

Dfs used */


#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

using namespace std;
using ll = long long;
using ul = unsigned long;

void f_io () {
	ios_base :: sync_with_stdio (false); cin.tie (nullptr);;
 	cout.tie (nullptr);
}

constexpr ll MOD = 998244353, MO = 1e9 + 7;
const ll INF = (1e18 + 10);
const int MAX = 2e5;
ll gc (ll a, ll b) {
	if (!a || !b) {
		return max (a, b);
	}
	assert (b != 0);
	ll r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

inline ll mult (ll a, ll b) {
	return (a  * 1LL * b) % MOD;
}

inline ll add (ll a, ll b) {
	b = (b % MOD + MOD) % MOD;
	return (a + b) % MOD;
}

ll pw (ll a, ll b) {
	if (b < 0) {
		return 1;
	}
	ll r = 1;
	while (b) {
		if (b & 1) {
			r = (a * r) % MOD;
		}
		b >>= 1;
		a =  (a  * a) % MOD;
	}
	return r;
}
int ar[MAX];
vector<int> gr[MAX];

int dfs (int node, uint64_t& an) {
	int mi = MO;
	for (auto x : gr[node]) {
		auto v = dfs (x, an);
		an += v;
		mi = min (mi, v);
	}
	if (mi != MO) {
		an -= mi;
		return max (mi, ar[node]);
	}
	return ar[node];
}
		
		

int main () {
	int tt = 0, t;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++tt << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> ar[i + 1];
			gr[i + 1].clear ();
		}
		vector<int> ve;
		for (int i = 1; i <= n; ++i) {	
			int p;
			cin >> p;
			if (p == 0) {
				ve.pb (i);
				continue;
			}
			gr[p].pb (i);
		}
		uint64_t ans = 0;
		for (auto x : ve) {
			ans += dfs (x, ans);
		}
		cout << ans << "\n";
	}
}


/*Codejam Round 1C-- Letter Blocks (Partial Solution) */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<":"<<" ";
        ll n;
        cin>>n;
        string a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        string an = "";
        ll fl = 0;
        do{
           string tmp = "";
           ll vv = 0;
           for(int j=0;j<n;j++)
           {
               tmp+=a[j];
           }
           vector<ll> pos[27];
           for(int p=0;p<tmp.size();p++)
           {
                 pos[tmp[p]-'A'].push_back(p);
           }
           for(int i=0;i<27;i++)
           {
               if(pos[i].size()>1)
               {
                   for(int l=1;l<pos[i].size();l++)
                   {
                       if(abs(pos[i][l]-pos[i][l-1])>1)
                       {
                           vv = 1;
                           break;
                       }
                   }
               }
           }
           if(vv==1)
           {
               continue;
           }
           else{
               fl = 1;
               an = tmp;
               break;
           }
        }while(next_permutation(a,a+n));
        
        if(an == "")
        {
            cout<<"IMPOSSIBLE\n";
        }
        else{
            cout<<an<<"\n";
        }
    }
}

/* Codejam Round 1C -- Squary(Partial solution) */

#include<bits/stdc++.h>
#include<random>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

using namespace std;
using ll = long long;
using ul = unsigned long;



int main () {
	int tt = 1, t = 1;
	cin >> t;
	while (t--) {
		cout << "Case #" << tt++ << ": ";
		int n, k;
		cin >> n >> k;
		vector<int> v (n);
		int su = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			su += v[i];
		}
		ll to = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				to += (v[i] * v[j]);
			}
		}
		if (su == 0 && to == 0)  {
			cout << "1\n";
		}
		else if (su && abs (to) % abs (su) == 0) {
			cout << -(to / su) << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}
}





/* GFG SDE-1 Hiring challenge question */

/* Question : X has an array A which he wants to give to his friend . His friend only likes an integer K and 
will only like the array if atleast K integers are divisible by K . X can perform any of the following operation 
before gifting the array to his friend : 

Increment / decrement each element by 1 

Input:
N = 5, K = 4
A = [4, 7, 9, 5, 2]
Output: 3
Explanation: 
In 3 operations we can convert the
array to: [4, 8, 8, 4, 2].
Now, 4 numbers are divisible by 4

1<=N<=2*10^5
1<=K<=N
1<=A[i]<=10^9
*/
class Solution {
  using ll = long long ;
  
  public:
    long long solve(int N, int K, vector<int> &A) {
        ll cnt = 0;
        int res[N]={0};
        for(int i=0;i<N;i++)
        {
            int v1 = ceil(A[i]/double(K));
            res[i] = min(A[i]%K , (v1*K)-A[i]);
        }
        sort(res,res+N);
        for(int j=0;j<N;j++)
        {
            if(res[j]==0)
            {
               K--;
            }
        }
        for(int j=0;j<N;j++)
        {
            if(cnt<K && res[j]>0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};




/* Amazon SDE-1 Hiring Challenge solution Hackerearth */

#include<bits/stdc++.h>
using namespace std;

int solve (int N, int M, vector<long long> A, vector<long long> B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int cnt = 0;
    int i=0,j=0;
    while(i<N && j<M)
    {
        if(B[j]<=A[i])
        {
            i++;
            j++;
            cnt++;
        }
        else if(B[j]>A[i])
        {
            i++;
        }
    }
    return cnt;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<long long> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        vector<long long> B(M);
        for(int i_B = 0; i_B < M; i_B++)
        {
        	cin >> B[i_B];
        }

        int out_;
        out_ = solve(N, M, A, B);
        cout << out_;
        cout << "\n";
    }
}