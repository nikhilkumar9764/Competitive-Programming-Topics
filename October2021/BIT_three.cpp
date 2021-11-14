/*
Problem Name : LIS Modified Coding blocks 
You are given a sequence of N integers A denoted by A[1] , A[2]…..A[N].
Each integer in the sequence has a value associated with it W[1],W[2]…. W[N].
You have to select a subsequence of given array A such that all the elements in A are in strictly increasing order and sum of values of elements in this selected subsequence is maximum. You have to print this maximum value.

Input Format:
The first line of input contains a single integer T. T test-cases follow. The first line of each test-case contains an integer N. The next line contains a1, a2 ,… , aN separated by a single space. The next line contains w1, w2, …, wN separated by a single space.

Constraints:
1 <= T <= 5 1 <= N <= 200000 1 <= a[i] <= 10^9, where i ∈ [1..N] 1 <= w[i] <= 10^9, where i ∈ [1..N]
SS

Output Format:
For each test-case output a single integer: The maximum sum of values of increasing subsequences of the given sequence.

Sample Input
2
4
1 2 3 4
100 200 300 400
3
4 2 3
100 30 20
Sample Output
1000
100
Explanation
In the first test case we will take the sequence as whole array hence answer is 1000. In the second test case if we take only first element we get sum as 100.

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
#define MOD (ll) (1e9+7)
ll bit[MAX];

void add(ll idx,ll val)
{
    while(idx<=MAX)
    {
        bit[idx] = max(bit[idx],val);
        idx+=(idx&(-idx));
    }
}

ll query(ll idx)
{
    ll su = 0;
    while(idx>0)
    {
        su = max(su,bit[idx]);
        idx-=(idx&(-idx));
    }
    return su;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n];
        set<ll> se;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            se.insert(ar[i]);
        }
        ll wt[n];
        for(int i=0;i<n;i++)
        {
            cin>>wt[i];
        }
        ll cc = 1;
        memset(bit,0,sizeof(bit));
        map<ll,ll> ma;
        for(auto it : se)
        {
            ma[it] = cc;
            cc++;
        }
        ll qp[n+4];
        for(int i=0;i<n;i++)
        {
            qp[i] = ma[ar[i]];
        }
        ll an = 0;
        for(int i=0;i<n;i++)
        {
            ll ff = query(qp[i]-1) + wt[i];
            an = max(an,ff);
            add(qp[i],ff);
        }
        cout<<an<<"\n";
        ma.clear();
        se.clear();
    }
}

/* Shil and pallindrome research
Shil got interested in palindrome research. For that he needs some research data for a particular string S. To obtain this data he has some queries of following type:

1 L x - update Lth character of string to x
2 L R - find if all the character of string from index L to R can be rearranged such that they can form a palindrome. If they can print "yes", else print "no".
Since you decided to help Shil with his research, its your responsibililty to make this data available as soon as possible. The original problem can be found here

Input Format
First line of input consists of two integers N and Q denoting length of string S and total number of queries. Next line consists of N lowercase english characters ('a' - 'z') . Next Q lines consists of queries. If the query is 1st type, then it will consists of two integers and a character x and if its of the 2nd type, it will consist of three integers.

Constraints
1 <= N <= 100000 1 <= Q <= 100000 1 <= L,R <= N All the characters in string S will be lowercase english letters ('a'-'z').

Output Format
For each query of 2nd type, output "yes" or "no" without the quotes.

Sample Input :
5 4
ababb
2 2 3
1 3 b
2 1 4
2 1 5

Sample Output :
no
no
yes

Explanation: 
For 1st query , 'b' and 'a' can't be rearranged to form the palindrome. 
For 3rd query , 'a' , 'b' , 'b' , 'b' can't be rearranged to form the palindrome. 
For 4th query , all the characters can be rearranged like this "bbabb" to form a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
#define MOD (ll) (1e9+7)


class Fenwick {
public : 
ll bit[MAX];    
void add(ll idx,ll val)
{
    while(idx<=MAX)
    {
        bit[idx]+= val;
        idx+=(idx&(-idx));
    }
}

ll query(ll idx)
{
    ll su = 0;
    while(idx>0)
    {
        su+=bit[idx];
        idx-=(idx&(-idx));
    }
    return su;
}

}fn[27];

int main()
{
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        fn[s[i]-'a'].add(i+1,1);
    }
    while(q--)
    {
        ll ch;
        cin>>ch;
        ll lef;
        cin>>lef;
        if(ch == 1)
        {
            char x;
            cin>>x;
            fn[s[lef-1]-'a'].add(lef,-1);
            s[lef-1] = x;
            fn[x-'a'].add(lef,1);
        }
        else{
            ll rr;
            cin>>rr;
            ll cc = 0;
            for(int i=0;i<26;i++)
            {
                ll an1;
                if(lef-1 == 0)
                {
                    an1 = fn[i].query(rr);
                }
                else{
                 an1 = fn[i].query(rr)-fn[i].query(lef-1);
                }
                if(an1%2 == 1)
                {
                    cc++;
                }
            }
            if(cc>1)
            {
                cout<<"no\n";
            }
            else{
                cout<<"yes\n";
            }
        }
    }
}

/* UPDATE IT (Spoj) 
You have an array containing n elements initially all 0. You need to do a number of update operations on it. 
In each update you specify l, r and val which are the starting index, ending index and value to be added. 
After each update, you add the 'val' to all elements from index l to r. After 'u' updates are over, 
there will be q queries each containing an index for which you have to print the element at that index.

Input
First line consists of t, the number of test cases. (1 <= t <= 10)
Each test case consists of "n u",number of elements in the array and the number of update operations, in the first line (1 <= n <= 10000 and 1 <= u <= 100000)
Then follow u lines each of the format "l r val" (0 <= l,r < n, 0 <= val <=10000)
Next line contains q, the number of queries. (1 <= q <= 10000)
Next q lines contain an index (0 <= index < n)

Output
For each test case, output the answers to the corresponding queries in separate lines.

Example
Input:
1
5 3
0 1 7
2 4 6
1 3 2
3
0
3
4

Output:
7
8
6
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
#define MOD (ll) (1e9+7)

void add(ll *bit,ll idx,ll val)
{
    while(idx<=MAX)
    {
        bit[idx]+= val;
        idx+=(idx&(-idx));
    }
}

ll query(ll *bit,ll idx)
{
    ll su = 0;
    while(idx>0)
    {
        su+=bit[idx];
        idx-=(idx&(-idx));
    }
    return su;
}


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
      ll n,uu;
      cin>>n>>uu;
      ll bit[MAX];
      memset(bit,0,sizeof(bit));
      while(uu--)
      {
    	 ll lo,hi,vv;
    	 cin>>lo>>hi>>vv;
    	 add(bit,lo+1,vv);
    	 add(bit,hi+2,-vv);
      }
    
      ll q;
      cin>>q;
      while(q--)
      {
      	 ll pt;
      	 cin>>pt;
      	 ll ans = query(bit,pt+1);
      	 cout<<ans<<"\n";
      }
	}
}

/* BUY AND SELL (Coding Blocks)
A good and robust is always difficult to design, however, its benefits are unlimited and is much better in the long term.
Today, you need to do just the same, i.e. you need to create a system to successfully process the incoming 
and outgoing stock of a retail outlet.The outlet stocks and sells N types of items. Each item has a name and a price per unit 
associated with it. The name of each item on sale is guaranteed to be unique. You shall be given the names and prices for each of the N items.
Now, based on this list of items, You need to process 3 types of queries:

+X : Given a String X, add one unit of item X to the available stock. It is guaranteed that item X shall be among the list of items the shop trades in.
−X: If item X exists in the available stock, remove one occurrence of it from the available stock.
? Y : Now, you need to find the summation of available units of each item having price strictly greater than Y.

Initially the stock list is empty. For each query of the 3rd type, you need to print the answer on a new line.

Input Format
The first line contains a single integers N denoting the number of items the shop trades in. Each of the next N lines contains a String Xi and an integer ki where the ith line denotes that the ith item has name Xi and price ki. The next line contains a single integer Q. Each of the next Q lines contains either of the 3 types of queries. The first symbol of each query denotes the type of query. A symbol '+' denotes the first type of query, '-' denotes a query of the second type, '?' of the third respectively.

Constraints
1 <= N <= 100000 1 <= Q <= 100000 1 <= |Xi| <= 10 1 <= K <= 100000 0 <= Y <= 100000
Note : The name of each item on sale shall consist of lowercase English alphabets only

Output Format
For each query of the 3rd type, print the answer on a new line

Sample Input
5
banana 10
biscuit 5
apple 10
mango 1
juice 14
5
+ banana
+ apple
? 1
+ mango
? 0
Sample Output
2
3
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
#define MOD (ll) (1e9+7)

void update(int *bit,int idx,int val)
{
    while(idx>0)
    {
        bit[idx]+=val;
        idx-=idx &(-idx);
    }
}

int query(int *bit,int maxi,int i)
{

    int ansss=0;
    while(i<=maxi)
    {
        ansss+=bit[i];
        i+=i&(-i);
    }
    return ansss;
}

int32_t main()
{
    fast();

    int t=1;    //change t if required
    //cin>>t;
    while(t--)
    {
		int n,maxi=0;
        map<string,int>price;
        map<string,int>quant;
        cin>>n;
        int bit[MAX];
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            int pp;
            cin>>pp;
            maxi=max(maxi,pp);
            price[s]=pp;
        }

        int q;
        cin>>q;
        while(q--)
        {
            char c;
            cin>>c;
            if(c=='+')
            {
                string s;
                cin>>s;
                quant[s]++;
                update(bit,price[s],1);
            }

            else if(c=='-')
            {
                string s;
                cin>>s;
                if(quant[s]>0)
                {
                    update(bit,price[s],-1);
                    quant[s]--;
                }

            }
            else if(c=='?')
            {
                int i;
                cin>>i;
                cout<<query(bit,maxi,i+1)<<endl;
            }
        }
    }
}

void fast()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}



/* Question Name : Cover them All (HARD)
There are N soldiers located on our X-AXIS. The point at which soldier is located also has some number of bombs.
The war is near and every soldier wants to communicate with every other soldier.
If the ith soldier has b number of bombs and is located at position X then the cost of communicating with any other soldier j having c number of bombs located at position Y is defined as |X-Y|*max(b,c).
Find the sum of costs of communication if every soldier wants to communicate with every other soldier.
NOTE :- You have to consider pair(i,j) only once in sum of costs.

Input Format
First line consists of number of test cases T. Each test case consists of three lines. The first line indicates the number of soldiers (N). The second line indicates the coordinates of the N soldiers ( X[i] ). The third line contains the number of bombs at every soldiers location ( B[i] ) . The x-coordinates needn't be in increasing order in the input.

Constraints
1 <= T <= 20 1 <= N <= 200000 1 <= X[i] <= 1000000000 1 <= B[i] <= 10000

Output Format
The total cost modulo 10^9+7.

Sample Input
1
3  
1 3 6  
10 20 30  
Sample Output
280
Explanation
there are 3 pairs (1,2) -> cost = abs(3-1) * 20 = 40 (1,3) -> cost = abs(1-6) * 30 = 150 (2,3) -> cost = abs(3-6) * 30 = 90 sum = 40 + 150 + 90 = 280
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(cont) cont.begin(), cont.end()
#define size 200010ll
#define mod 1000000007


bool mycomp(const pair<pair<ll, ll>, ll>&a, const pair<pair<ll, ll>, ll>&b)
{
    return a.fi.se < b.fi.se;
}


struct BIT
{
    ll tree[size+1];
    void clear()
    {
        for (ll i = 0; i < size; i++)
            tree[i] = 0;
    }
    int query(int idx)                  
    {
        int retval = 0;
        idx++;
        while (idx )
        {
            retval = (retval + tree[idx]) % mod;
            idx -= (idx & (-idx));
        }
        return retval;
    }
    void update(int idx, int val)   
    {   idx++;
        while (idx < size)
        {    
            tree[idx] = (val + tree[idx]) % mod;
            idx += (idx & (-idx));
        }
    }
} BIT1, BIT2;


int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {

        cin >> n;
        vector<pair<pair<int,int>, int>> arr(n);
        vector<int>compress(n);    

        for (ll i = 0; i < n; i++)
        {
            cin >> compress[i];
            (arr[i].fi).fi = compress[i];
        }

        for (ll i = 0; i < n; i++)
            cin >> (arr[i].fi).se;

        sort(all(compress));
        ll m = unique(all(compress)) - compress.begin();
        compress.resize(m);

        for (ll i = 0; i < n; i++)
            arr[i].se = (lower_bound(all(compress), (arr[i].fi).fi) - compress.begin()) + 1;

        sort(all(arr), mycomp);

        BIT1.clear();
        BIT2.clear();
        BIT1.update(arr[0].se, arr[0].fi.fi);
        BIT2.update(arr[0].se, 1);

        ll ans = 0;
        for (ll i = 1; i < n; i++)
        {
            ll greatersum = BIT1.query(size - 3) - BIT1.query(arr[i].se);
            greatersum=(greatersum+mod)%mod;
            ll greatercount = BIT2.query(size - 3) - BIT2.query(arr[i].se);
            greatercount=(greatercount+mod)%mod;
           
            ll lessersum = BIT1.query(arr[i].se - 1);
            ll lessercount = BIT2.query(arr[i].se - 1);
           
            ll val = arr[i].fi.fi;
            ll aaa =( ( greatersum - ( (val * greatercount) % mod) )+mod) % mod;
            ll bbb = (( ( (val * lessercount) % mod) - lessersum )+mod) % mod;
            
            aaa = (aaa+mod)%mod;
            bbb = (bbb+mod)%mod;
            ll multi = arr[i].fi.se;

            ll curr = ( (aaa * multi) % mod + (bbb * multi) % mod ) % mod;
            ans = (ans + curr) % mod;

            BIT1.update(arr[i].se, arr[i].fi.fi);
            BIT2.update(arr[i].se, 1);
        }
        cout << ans%mod<< endl;
  
    } 
}
