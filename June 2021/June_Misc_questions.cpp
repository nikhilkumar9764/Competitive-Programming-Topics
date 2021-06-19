// Boston  numbers (Easy Version)

/*A Boston number is a composite number, the sum of whose digits is the sum of the digits of its prime factors obtained as a result of prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. Write a program to check whether a given integer is a Boston number.

Input Format
There will be only one line of input:N , the number which needs to be checked.

Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.

Sample Input
378
Sample Output
1
Explanation
Self Explanatory

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll pw(ll a,ll b)
{
    ll re = 1;
    while(b>0)
    {
        if(b%2 == 1)
        {
            re = re*a;
        }
        a = a*a;
        b = b>>1;
    }
    return re;
}

ll sum_dig(ll n)
{
    ll su = 0;
    while(n)
    {
        su+=n%10;
        n = n/10;
    }
    return su;
}

int main()
{
   ll n;
   cin>>n;
   ll tmp = n;
   vector<ll> pr;
   while(tmp % 2 == 0)
   {
       pr.push_back(2);
       tmp = tmp/2;
   }
   for(int i=3;i<=sqrt(tmp);i+=2)
   {
       while(tmp%i == 0)
       {
         pr.push_back(i);
         tmp = tmp/i;
       }
   }
   if(tmp > 2)
   {
       pr.push_back(tmp);
   }
   
   ll su1 = sum_dig(n);
   ll su2 = 0;
   for(int i=0;i<pr.size();i++)
   {
       su2+=sum_dig(pr[i]);
   }
 
   if(su1 == su2)
   {
       cout<<1<<"\n";
   }
   else
   {
       cout<<0<<"\n";
   }
}

/* Factorial problem 

Mike found an interesting problem. In this problem you are given two integers, n and k.
 You need to find the the maximum value of x, such that, n! % kx = 0.

Input Format
First line contains number of test cases, T. Each test case contains two integers each, n and k.

Constraints
1<=T<=20 1<=n<=10^8 2<=k<=10^8

Output Format
Print the value of x for each test case.

Sample Input
2
5 2
1000 2
Sample Output
3
994
Explanation
In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120.
 So, the answer should be 3.
*/


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll occ = 0;
        ll ans = INT_MAX;
        for(int i=2;i*i<=k;i++)
        {
            occ = 0;
            if(k%i == 0)
            {
                while(k%i == 0)
                {
                    occ++;
                    k = k/i;
                }
              ll tmp = i;
              ll cnt = 0;
              while(tmp<=n)
              {
                  cnt+=n/tmp;
                  tmp = tmp*i;
              }
              ans = min(ans, cnt/occ);
            }
        }
        if(k>1)
        {
            ll vv = k;
            ll ct = 0;
            while(vv<=n)
            {
                ct+=n/vv;
                vv = vv*k;
            }
            ans = min(ans,ct);
        }
        if(ans == INT_MAX)
		{
			cout<<0<<"\n";
		}
		else{
           cout<<ans<<"\n";
		}
        
    }
}


/* Not so easy math  (Medium problem)

After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n which are divisible by any of the prime numbers less than 20. Ironman being great at maths quickly answered the question but then Thor asked him to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are smart and can code this up easily. Can you do it?

Input Format
The first line consists of number of test cases t. then follow t lines which consists of number n for each test case.

Constraints:

1 <= test cases <= 10 1 <= n <= 10^18

Output Format
the answer to each test case each in different line

Sample Input
5
5
10
12
15
18
Sample Output
4
9
11
14
17
Explanation
for n = 5 2 and 4 are divisible by 2 and 3 is divisible by 3 and 5 by 5. hence ans = 4.
*/

// Approach used : Bitmasking + Mutual Inclusion- Exclusion Principle

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
int main()
{
    ll primes[8] = {2,3,5,7,11,13,17,19};
    ll n;
    cin>>n;
    while(n--)
    {
        ll val;
        cin>>val;
        ll ans = 0;
        for(int i=1;i<(1<<8);i++)
        {
            ll prod = 1;
            ll no_selection = __builtin_popcount(i);
            for(int j=0;j<8;j++)
            {
                ll msk = (1<<j);
                if(msk&i)
                {
                    prod = prod*primes[j];
                }
            }
            if(no_selection % 2 == 1)
            {
                ans+= val/prod;
            }
            else
            {
                ans-= val/prod;
            }
        }
        cout<<ans<<"\n";
    }
}




/* Aggressive Cows (Advanced Binary Search)

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll pw(ll a,ll b)
{
    ll re = 1;
    while(b>0)
    {
        if(b%2 == 1)
        {
            re = re*a;
        }
        a = a*a;
        b = b>>1;
    }
    return re;
}

ll sum_dig(ll n)
{
    ll su = 0;
    while(n)
    {
        su+=n%10;
        n = n/10;
    }
    return su;
}

void multiply(ll *a,ll &n,ll num)
{
    ll carry = 0;
    for(int i=0;i<n;i++)
    {
        ll prod = a[i]*num + carry;
        a[i] = prod%10;
        carry = prod/10;
    }
    
    while(carry>0)
    {
        a[n] = carry%10;
        carry = carry/10;
        ++n;
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        ll lo = 0, hi = 1e9+4;
        ll ans = -1;
        while(lo<=hi)
        {
            ll cnt = 1;
            ll mid = (lo+hi)/2;
            ll last = ar[0];
            for(int i=1;i<n;i++)
            {
                if((ar[i]-last)>=mid)
                {
                    last = ar[i];
                    ++cnt;
                }
            }
            if(cnt>=c)
            {
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}