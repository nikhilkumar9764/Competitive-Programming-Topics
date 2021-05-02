// Consecutive Primes
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
const int MAX = 10000000005;
vector<int> pr,p;

void simpleSieve(int limit, vector<int> &prime)
{
    vector<bool> mark(limit + 1, true);
 
    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            pr.push_back(p);
        }
    }
}
 
void seg_sieve()
{
    int limit = floor(sqrt(MAX))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);

    int low = limit;
    int high = 2*limit;
 
    while (low < MAX)
    {
        if (high >= MAX)
           high = MAX;
         
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        for (int i = low; i<high; i++)
        {
            if (mark[i - low] == true)
             {
             	 pr.push_back(i);
             }
        }
        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}
 
int main()
{
	seg_sieve();
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    	 ll num;
    	 cin>>num;
    	 ll an = 0;
    	 for(int i=1;i<pr.size() && pr[i]*1LL*pr[i-1]<=num;i++)
    	 {
    	 	an = pr[i]*1LL*pr[i-1];
    	 }
    	 cout<<"Case #"<<i<<":"<<" "<<an<<"\n";
    }
}