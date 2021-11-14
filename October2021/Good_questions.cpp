/*
A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).
The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).
Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.

Input
The first line of the input contains an integer t representing the number of test cases. Then t test cases follow. Each test case has the follwing form:
Line 1: A single integer, N
Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
Line N+2: Two space-separated integers, L and P

Output
For each test case, output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

Example
Input:
1
4
4 4
5 2
11 5
15 10
25 10

Output:
2

Input details
The truck is 25 units away from the town; the truck has 10 units
of fuel.  Along the road, there are 4 fuel stops at distances 4,
5, 11, and 15 from the town (so these are initially at distances
21, 20, 14, and 10 from the truck).  These fuel stops can supply
up to 4, 2, 5, and 10 units of fuel, respectively.

Output details:
Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more
units, stop to acquire 5 more units of fuel, then drive to the town.

*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)


// bool compare(const pair<ll,ll> &a , const pair<ll,ll> &b)
// {
//     return a.first > b.first;
// }

// int main()
// {
//      ll t;
//      cin>>t;
//      while(t--)
//      {
//      	 ll n;
//      	 cin>>n;
//      	 ll x,y;
//      	 vector<pair<ll,ll>> vp;
//      	 for(int i=0;i<n;i++)
//      	 {
//      	 	 cin>>x>>y;
//         	 vp.push_back({x,y});
//      	 }
//      	 ll dis,cap;
//      	 cin>>dis>>cap;
//      	 priority_queue<ll> pq;
//      	 sort(vp.begin(),vp.end(),compare);
//      	 for(int i=0;i<n;i++)
//      	 {
//      	     vp[i].first = dis-vp[i].first;
//      	 }

//      	 ll pt = 0,prev= 0;
//      	 ll ans = 0;
//      	 ll fl = 0;
//      	 while(pt < n)
//      	 {
//      	     if(cap>=(vp[pt].first-prev))
//      	     {
//      	         cap = cap-(vp[pt].first-prev);
//      	         prev = vp[pt].first;
//      	         pq.push(vp[pt].second);
//      	     }
//      	     else{
//      	         if(pq.empty())
//      	         {
//      	             fl =1;
//      	             break;
//      	         }
//      	         cap+=pq.top();
//      	         pq.pop();
//      	         ans+=1;
//      	         continue;
//      	     }
//      	     pt++;
//      	 }
     	 
    
//      	 if(fl == 1)
//      	 {
//      	     cout<<-1<<"\n";
//      	     continue;
//      	 }
     	 
//      	 dis = dis-vp[n-1].first;
//      	 if(cap >=dis)
//      	 {
//      	     cout<<ans<<"\n";
//      	     continue;
//      	 }
     	 
//      	 while(cap < dis)
//      	 {
//      	     if(pq.empty())
//      	     {
//      	         fl = 1;
//      	         break;
//      	     }
//      	     cap+=pq.top();
//      	     pq.pop();
//      	     ans+=1;
//      	 }
     	 
//      	 if(fl == 1)
//      	 {
//      	     cout<<-1<<"\n";
//      	     continue;
//      	 }
//      	 cout<<ans<<"\n";
//      }
// }

/*
Kreditbee Hiring challenge : 

 You are given an array A consisting of N non-negative integers.
In one operation you can select any one element from the array and increment it by 1. 

Task : You need to answer Q queries . In each query you are given 2 integers L,R , you need to 
determine the minimum no of operations you need to perform such that (A[L]&A[L+1]&A[L+2].....&A[R]) is strictly 
greater than 0 (where & is the bitwise AND operator) 

Notes : Each query is independent which means it does not change the array A.
1 based indexing is followed.

Example : Assumptions --> N = 6
A =[1,0,3,2,4,6]
Q = 2  query = [[1,3],[3,6]]

Output : 1 2

N<=10^5
Q<=10^5
*/


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// ll pw(ll a,ll b)
// {
//     ll res = 1;
//     while(b)
//     {
//         if(b%2 == 1)
//         {
//             res = (res *a)%MOD;
//         }
//         a = (a*a)%MOD;
//         b>>=1;
//     }
//     return res;
// }

// int main()
// {
//      ll n;
//      cin>>n;
//      ll ar[n];
//      for(int i=0;i<n;i++)
//      {
//          cin>>ar[i];
//      }
//      ll bits[n][32];
//       for(int i=0;i<n;i++)
//      {
//          for(int j=0;j<32;j++)
//          {
//              bits[i][j] = 0;
//          } 
//      }
     
//      for(int i=0;i<n;i++)
//      {
//          for(int j=0;j<32;j++)
//          {
//               if((ar[i]&(1<<j))>0 && i==0)
//               {
//                   bits[i][j]+=1;
//               }
//               else if((ar[i]&(1<<j))>0 && i>0)
//               {
//                    bits[i][j] = bits[i-1][j]+1;
//               }
//               else if((ar[i]&(1<<j)) == 0 && i>0)
//               {
//                   bits[i][j] = bits[i-1][j];
//               }
//          } 
//      }
     
//      for(int i=0;i<n;i++)
//      {
//          for(int j=0;j<32;j++)
//          {
//               cout<<bits[i][j]<<" ";
//          } 
//          cout<<"\n";
//      }
//      cout<<"\n";
//      ll q;
//      cin>>q;
//      while(q--)
//      {
//          ll lef,rig;
//          cin>>lef>>rig;
//          ll no_el = rig-lef+1;
//          --lef;
//          --rig;
//          ll an = LLONG_MAX;
//          if(lef  == 0)
//          {
//              for(int i=0;i<32;i++)
//              {
//                  if(bits[rig][i] > 0)
//                  {
//                    ll rem = no_el-bits[rig][i];
//                    an= min(an,(rem*pw(2,i))%MOD);
//                  }
//              }
//          }
//          else{
//              for(int i=0;i<32;i++)
//              {
//                  if((bits[rig][i]-bits[lef-1][i]) > 0 )
//                  {
//                    ll rem = no_el-(bits[rig][i]-bits[lef-1][i]);
//                    an= min(an,(rem*pw(2,i))%MOD);
//                  }
//              }
//          }
//          cout<<an<<"\n";
//      }
// }

/*Natwest Hiring challenge 

Given an array of N integers and Q queries . Each query consists of 4 integers : [L,R,a,d] where a is first element of AP and d is
the common difference . Now we need to do a update on the range [L,R] i.e in each query you have add the AP sum within the  given range.
N = 6 [4,3,5,7,4,1]

Q = 1  [2,4,1,3]
       [l,r,a,d]

Output after processing all queries : [4,4,8,14,4,1]

To be solved using segment trees (Not yet solved yet).
*/


/*
Given a string S of length N and an integer K, the task is to find the minimum character replacements required to make the string palindromic as well as K-periodic.

A K-periodic string can be made only by concatenating several palindromic strings having length K.
All the characters at positions i, K – i – 1, i + K, 2K – i – 1, i + 2K, 3K – i – 1, i + 3K, … for all 0 ≤ i < K, are equal.
The problem reduces to making all the characters equal to the one which appears the maximum number of times at these positions in the given string.
 Follow the steps below to solve the above problem: 
Initialize a variable ans with 0 that stores the minimum changes required to satisfy the given condition.
Iterate over the range [0, K / 2] using the variable i.
Create a hashmap, mp to store the frequency of each character.
Iterate over the characters in the string starting from i in intervals of K using a variable j and store the frequency of each character.
Iterate the string in reverse, starting from (N – i – 1) in intervals of K using a variable j and store the frequency of each character. If K is odd and i = K / 2, then break out of the loop.
Find the maximum frequency of a character among the visited one and store it in a variable, say curr_max.
After the above steps, if K is odd and i = K/2, then increment ans by (N/K – curr_max)Otherwise, increment ans by (N/K – 2*curr_max).
After the above steps, print the value of ans as the result. */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// int main()
// {
//     string s;
//     cin>>s;
//     ll k;
//     cin>>k;
//     ll n = s.size();
//     ll ans = 0;
//     for(int i=0;i<(k+1)/2;i++)
//     {
//            map<ll,ll> ma;
//            for(int j=i;j<n;j+=k)
//            {
//                   ma[s[j]]++;
//            }
//            for(int j=n-1-i;j>=0;j-=k)
//            {
//                   if(k%2==1 && i==(k/2))
//                   {
//                          break;
//                   }
//                   ma[s[j]]++;
//            }
//            ll maxi = INT_MIN;
//            for(auto it : ma)
//            {
//                   maxi = max(maxi,it.second);
//            }
//            if(k%2 == 1 && i==k/2)
//            {
//                ans+=(n/k)-maxi;
//            }
//            else{
//               ans+=(n/k)*2-maxi;
//            }
//            ma.clear();
//     }
//     cout<<ans<<"\n";
// }

/* Given a string consisting of '0','1','?'  where ? denotes empty space  and an integer k. 
Fill the blank spaces in such a manner such that the string s becomes k periodic and print the string .
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{ 
    ll t;
    cin>>t;
    while(t--)
    {

    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll n = s.size();
    ll ans = 0;
    for(int i=0;i<(k);i++)
    {
           map<ll,ll> ma;
           for(int j=i;j<n;j+=k)
           {
                  ma[s[j]]++;
           }
          
           char x;
           ll maxi = INT_MIN;
           for(auto it : ma)
           {
                  if((it.first)!='?' && it.second > maxi)
                  {
                       maxi = max(maxi,it.second);
                       x = it.first;
                  }  
           }
           if(maxi == INT_MIN)
           {
               for(int j=i;j<n;j+=k)
               {
                   s[j] = '1';
               }   
           }
           else{
                for(int j=i;j<n;j+=k)
                {
                   if(s[j] == '?')
                   {
                          s[j] = x;
                   } 
                } 
           }
           ma.clear();
    }
    cout<<s<<"\n";
    }
}

/* 
Tara Capital Quant Developer Hiring Challenge 
There is an array A of N integers and we need to process Q queries . 
In each query is of form [L,R] and we need to find in each query between L,R 
if there exists a subsequence such that the length of the subsequence is equal to largest element present
in the subsequence , then final answer of each query is XOR the elements of all such subsequences.

Constraints  :  1<=N<=10^5
                1<=Q<=10^5

suppose N=5
[2,1,3,4,2] and Q =2

Q1 : [1,3] : there are subsequences [1],[2,1],[2,1,3] answer would be : 1^2^1^2^1^3 = 2.
Q2 : [2,5] : there is only one subsequence [1,3,4,2] .. answer would be : 1^3^4^2 = 4.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main()
{
        ll n;
        cin>>n;
        ll ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        ll pos[n+2]={0};
        for(int i=0;i<n;i++)
        {
            pos[ar[i]] = i+1;
        }
        ll maxi[n+2]={0} , mini[n+2]={0};
        maxi[1] = pos[1];
        mini[1] = pos[1];
        for(int i=2;i<=n;i++)
        {
            maxi[i] = max(pos[i],maxi[i-1]);
            mini[i] = min(pos[i],mini[i-1]);
        }
        
        for(int i=1;i<=n;i++)
        {
            cout<<mini[i]<<" ";
        }
        cout<<"\n";
        
        for(int i=1;i<=n;i++)
        {
            cout<<maxi[i]<<" ";
        }
        cout<<"\n";
        vector<ll> res;
        ll q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            ll l,r;
            cin>>l>>r;
            ll lef = 1,rig = n;
            ll ans = 0;
            while(lef<=rig)
            {
                ll mid = (lef+rig)>>1;
                if(mini[mid]>=l && maxi[mid]<=r)
                {
                    ans = mid;
                    lef = mid+1;
                }
                else{
                    rig = mid-1;
                }
            }
            cout<<ans<<"\n";
            res.push_back(ans);
        }
        map<ll,vector<ll>> ma;
        for(int i=0;i<res.size();i++)
        {
            ma[res[i]].push_back(i);
        }
       ll ev = 0,odd = 0;
        for(int i=1;i<=n;i++)
        {
             if(i%2 == 1)
             {
                 odd^=i;
             } 
             else{
                 ev^=i;
             }
             ll curr_xor = ev;
             if(i%2 == 1)
             {
                 curr_xor = odd;
             }  
             for(auto pt : ma[i])
             {
                 res[pt] = curr_xor;
             }         
        }
        for(auto it : res)
        {
        	cout<<it<<" ";
        }
        cout<<"\n";
}
