// SEQ Question SPOJ 

/*

Sequence (ai) of natural numbers is defined as follows:
ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + … + ckai-k (for i > k)
where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.
For stricter evaluation of your code, try submitting your problem on SPOJ.

Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)

Output
Exactly C lines, one for each test case: an modulo 109

Example
Input:
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

Output:
8 
714 
257599514
*/


// Below approach helps us find the nth number in O(k^3 * log(n))

#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define MOD (ll) (1e9)

vector<ll> a,b,c;
ll k;

vector<vector<ll>> mul(vector<vector<ll>> A ,vector<vector<ll>> B)
{
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
           for(int x=1;x<=k;x++)
           {
               C[i][j] = (C[i][j]+ (A[i][x]*B[x][j])%MOD)%MOD;                
           } 
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> t, ll p)
{
    if(p == 1)
    {
        return t;
    }
    if(p&1)
    {
        return mul(t,pow(t,p-1));
    }
    vector<vector<ll>> X = pow(t,p/2);
    return mul(X,X);
}

ll calc(ll n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n<=k)
    {
        return b[n-1];
    }
    vector<ll> f;
    for(int i=1;i<=k;i++)
    {
        f.push_back(b[i-1]);
    }
    vector<vector<ll>> t(k+1,vector<ll>(k+1));
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j == i+1)
                {
                  t[i][j] = 1;
                }
                else{
                    t[i][j] = 0;
                }
            }
            else 
            {
                t[i][j] = c[k-j];
            }
        }
    }
    
    t = pow(t,n-1);
    ll ans = 0;
    for(int i=1;i<=k;i++)
    {
        ans=(ans + (t[1][i] * f[i-1])%MOD)%MOD;
    }
    return ans;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       cin>>k;
       ll x;
       for(int i=0;i<k;i++)
       {
           cin>>x;
           b.push_back(x);
       }
       for(int i=0;i<k;i++)
       {
           cin>>x;
           c.push_back(x);
       }
       ll n;
       cin>>n;
       cout<<calc(n)<<"\n";
       b.clear();
       c.clear();
    }
}


// SPP (Version II of SEQ) - Spoj

/*
Sequence (ai) of natural numbers is defined as follows:

ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and output it modulo a given positive integer p.

Input
On the first row there is the number C of test cases (equal to about 50).
Each test contains four lines:
k - number of elements of (c) and (b) (1 <= k <= 15)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
m, n, p - natural numbers separated by spaces (1 <= m <= n <= 1018, 1<= p <= 108)
Output
Exactly C lines, one for each test case: (am + am+1 + am+2 + ... + an) modulo p.

Example
Input:
1
2
1 1
1 1
2 10 1000003

Output:
142

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define MOD (ll) (1e9)

vector<ll> a,b,c;
ll k;

ll vv;
vector<vector<ll>> mul(vector<vector<ll>> A ,vector<vector<ll>> B)
{
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
           for(int x=0;x<=k;x++)
           {
               C[i][j] = (C[i][j]+ (A[i][x]*B[x][j])%vv)%vv;                
           } 
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> t, ll p)
{
    if(p == 1)
    {
        return t;
    }
    if(p&1)
    {
        return mul(t,pow(t,p-1));
    }
    vector<vector<ll>> X = pow(t,p/2);
    return mul(X,X);
}

ll calc(ll n)
{
    vector<vector<ll>> t(k+1,vector<ll>(k+1));
    
    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            if(i!=0 && i!=k)
            {
                if(j == i+1)
                {
                  t[i][j] = 1;
                }
                else
                {
                    t[i][j] = 0;
                }
            }
            else 
            {
                if(i==0 && j==0)
                {
                   t[i][j] = 1;
                }
                else if(i == k && j==0)
                {
                    t[i][j] = 0;
                }
                else
                {
                    t[i][j] = c[k-j];
                }
            }
        }
    }
    
    t = pow(t,n-k);
   
    ll ans = 0;
    ll su = accumulate(b.begin(),b.end(),0);
    for(int i=0;i<k+1;i++)
    {
        if(i == 0)
        {
            ans=(ans + (t[0][0]*su)%MOD)%MOD;
        }
        else
        {
           ans=(ans + (t[0][i]*b[i-1])%MOD)%MOD;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
       cin>>k;
       ll x;
       for(int i=0;i<k;i++)
       {
           cin>>x;
           b.push_back(x);
       }
       for(int i=0;i<k;i++)
       {
           cin>>x;
           c.push_back(x);
       }
       ll m,n;
       cin>>m>>n>>vv;
       
       ll t1 = 0,t2 = 0;
       if(m<=k)
       {
           t1 = accumulate(b.begin(),b.begin()+m-1,0);
       }
       else{
            t1 = calc(m-1);
       } 
       
       if(n<=k)
       {
           t2 = accumulate(b.begin(),b.begin()+n,0);
       }
       else
       {
            t2 = calc(n);
       } 
       ll an = ((t2-t1)%vv+vv)%vv;
       cout<<an<<"\n";
    }
}

/* Find the nth fibbonacci number using matrix exponentiation 

O(log(n)) */

#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
#define MOD (ll) (1e9)

vector<ll> a,b,c;
ll k = 2;

vector<vector<ll>> mul(vector<vector<ll>> A ,vector<vector<ll>> B)
{
    vector<vector<ll>> C(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
           for(int x=1;x<=k;x++)
           {
               C[i][j] = (C[i][j]+ (A[i][x]*B[x][j])%MOD)%MOD;                
           } 
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> t, ll p)
{
    if(p == 1)
    {
        return t;
    }
    if(p&1)
    {
        return mul(t,pow(t,p-1));
    }
    vector<vector<ll>> X = pow(t,p/2);
    return mul(X,X);
}

ll calc(ll n)
{
    if(n<=2)
    {
        return b[n-1];
    }
   
    vector<vector<ll>> t(k+1,vector<ll>(k+1));
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j == i+1)
                {
                  t[i][j] = 1;
                }
                else{
                    t[i][j] = 0;
                }
            }
            else 
            {
                t[i][j] = 1;
            }
        }
    }
    
    t = pow(t,n-1);
    
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
           cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    ll ans = 0;
    
    for(int i=1;i<=k;i++)
    {
        ans=(ans + (t[1][i] * b[i-1])%MOD)%MOD;
    }
    return ans;
}

int main()
{
      b.push_back(0);
      b.push_back(1);
      ll n;
      cin>>n;
      cout<<calc(n)<<"\n";
      b.clear();
}


