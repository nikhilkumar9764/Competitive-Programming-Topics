/* Wines distribution problem 
Given a list of wines [a1,a2,a3.....an] which are their associated prices. 
In each year we can also sell one bottle i.e either first or last bottle.
The prices of the bottle selected will be (yth year * a[i])--> y = y+1
*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// ll dp[1000][1000];

// ll calc_cost(ll *ar,ll i,ll j,ll n,ll cc)
// {
//     if(i>j)
//     {
//         return 0;
//     }
//     if(dp[i][j]!=0)
//     {
//         return dp[i][j];
//     }
//     ll op1 = ar[i]*cc+calc_cost(ar,i+1,j,n,cc+1);
//     ll op2 = ar[j]*cc+calc_cost(ar,i,j-1,n,cc+1);
//     return (dp[i][j] = max(op1,op2));
// }

// int main() 
// {
//     ll n;
//     cin>>n;
//     ll ar[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>ar[i];
//     }
//     ll ans = calc_cost(ar,0,n-1,n,1);
//     cout<<ans<<"\n";
// }

/*  Maximum sum subarray problem */
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     ll n;
//     cin>>n;
//     ll ar[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>ar[i];
//     }
//     ll max_so_far = ar[0];
//     ll dp[n] = {0};
//     dp[0] = ar[0] > 0 ? ar[0] : 0;
//     for(int i=1;i<n;i++)
//     {
//         dp[i]= ar[i] + dp[i-1];
//         if(dp[i]<0)
//         {
//             dp[i] = 0;
//         }
//         max_so_far = max(max_so_far, dp[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<dp[i]<<" ";
//     }
//     cout<<"\n";
//     cout<<max_so_far<<"\n";
// }

/* Ladders problem using DP ----> (O(n) approach)
Ques : Given a ladder of n steps and an integer k , we can only climb steps upto 1,2,3....k in one move.
 We have to tell minimum of steps to climb the stairs to reach the nth staircase.
*/
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     ll n,k;
//     cin>>n>>k;
//     ll dp[n+2] = {0};
//     dp[0] = 1;
//     dp[1] = 1;
//     for(int i=2;i<=k;i++)
//     {
//         dp[i] = 2*dp[i-1];
//     }
//     for(int i=k+1;i<=n;i++)
//     {
//         dp[i]= (2*dp[i-1])-dp[i-k-1];
//     }
//     for(int i=0;i<=n;i++)
//     {
//         cout<<dp[i]<<" ";
//     }
//     cout<<"\n";
//     cout<<dp[n]<<"\n";
// }

/* Stock trading. O(n.k).
You are a trader who wants to earn profit by selling stocks. 
Also, you are given an array 'a' which tells you about the stock price for a particular stock for upcoming n days.

In between these n days, you can make at most 'k' transactions of buying and selling , such that no transaction overlap each other.

Input Format
1st Line: t, number of test cases Next t lines will have, k, denoting the number of transactions n, denoting the length of array 'a' space separated values of array 'a'

Constraints
1<= t,k,n <=100 1<= Ai <= 1000

Output Format
Maximum profit earned by the trader

Sample Input
1 
1 5 23 4 5 9 20
Sample Output
16
Explanation
you will purchase at day 2(Rs 4) and sell at day 5(Rs.20) */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll n,k;
//         cin>>k>>n;
//         ll pr[n];
//         for(int i=0;i<n;i++)
//         {
//             cin>>pr[i];
//         }
//         ll dp[k+1][n+1];
//         for(int i=0;i<=k;i++)
//         {
//             dp[i][0] = 0;
//         }
//         for(int i=0;i<=n;i++)
//         {
//             dp[0][i] = 0;
//         }
//         for(int i=1;i<=k;i++)
//         {
//             ll max_dif = INT_MIN;
//             for(int j=1;j<n;j++)
//             {
//                  max_dif = max(max_dif, dp[i-1][j-1]-pr[j-1]);
//                  dp[i][j] = max(dp[i][j-1] , max_dif+pr[j]);
//             }
//         }
//         cout<<dp[k][n-1]<<"\n";
//     }
    
// }

/* Rod cutting problem 

Given a rod of length n and different prices at cut 1,2,3,.....n as p[1],p[2],p[3].....p[n]. 
Find the minimum cost of cutting the rod of different pieces.
*/


/*
 Printing any LCS from a pair of strings p,q with length m,n 
Time complexity : O (m*n) --> Any string can be printed
*/
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// bool sortinrev(const pair<ll,pair<ll,ll>> &a , const pair<ll,pair<ll,ll>> &b)
// {
//     return a.first > b.first;
// }

// int main() 
// {
//     string p,q;
//     cin>>p>>q;
//     ll l1 = p.size(),l2 = q.size();
//     ll dp[l1+1][l2+1];
//     for(int i=0;i<=l2;i++)
//     {
//         dp[0][i] = 0;
//     }
//     for(int i=0;i<=l1;i++)
//     {
//         dp[i][0] = 0;
//     }
//     for(int i=1;i<=l1;i++)
//     {
//         for(int j=1;j<=l2;j++)
//         {
//              if(p[i-1] == q[j-1])
//              {
//                  dp[i][j] = dp[i-1][j-1] + 1;
//              }
//              else{
//                  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//              }
//         }
//     }
    
//     ll idx = dp[l1][l2];
//     char res[idx+1];
//     res[idx] = '\0';
//     ll i = l1,j = l2;
//     while(i>0 && j>0)
//     {
//         if(p[i-1] == q[j-1])
//         {
//             res[idx-1] = p[i-1];
//             idx--;
//             i--;
//             j--;
//         }
//         else if(dp[i-1][j]>dp[i][j-1])
//         {
//             i--;
//         }
//         else 
//         {
//             j--;
//         }
//     }
//     cout<<res<<"\n";
// }

/*
 Variation of LCS : Printing all possible strings which are LCS from pair of strings p,q of 
length m,n  */


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// ll dp[1000][1000];
// set<string> printLCS(string p,string q,ll n,ll m)
// {
//     set<string> s;
//     if(n == 0|| m==0)
//     {
//         s.insert("");
//         return s;
//     }

//     if(p[n-1] == q[m-1])
//     {
//         set<string> tmp = printLCS(p,q,n-1,m-1);
//         for(auto it : tmp)
//         {
//             s.insert(it+p[n-1]);
//         }
//     }
//     else{
//         if(dp[n-1][m] >=dp[n][m-1])
//         {
//             s = printLCS(p,q,n-1,m);
//         }
        
//         if(dp[n][m-1]>=dp[n-1][m])
//         {
//             set<string> tmp = printLCS(p,q,n,m-1);
//             s.insert(tmp.begin(),tmp.end());
//         }
//     }
//     return s;
// } 

// int main() 
// {
//     string p,q;
//     cin>>p>>q;
//     ll l1 = p.size(),l2 = q.size();
//     for(int i=0;i<=l2;i++)
//     {
//         dp[0][i] = 0;
//     }
//     for(int i=0;i<=l1;i++)
//     {
//         dp[i][0] = 0;
//     }
//     for(int i=1;i<=l1;i++)
//     {
//         for(int j=1;j<=l2;j++)
//         {
//              if(p[i-1] == q[j-1])
//              {
//                  dp[i][j] = dp[i-1][j-1] + 1;
//              }
//              else{
//                  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//              }
//         }
//     }
    
//     ll idx = dp[l1][l2];
//     set<string> res = printLCS(p,q,l1,l2);
//     for(auto it :res)
//     {
//         cout<<it<<"\n";
//     }
//     cout<<"\n";
// }



/* Job for Bounties (Coding Blocks) 
 Mike’s boss gave him a string of opening and closing parenthesis asked him to find a valid parenthesis substring in it. He will get number of bounties equal to the length of substring he finds in return. What is the maximum amount of number of bounties he can get?

Input Format
The input file has a single line which contains a single string str that Mike's boss gave to him.

Constraints
1 <= |str| <= 100000

Output Format
Print, in a single line, the maximum amount of number of bounties Mike can get

Sample Input
(()(()()
Sample Output
4
*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     string s;
//     cin>>s;
//     stack<ll> stck;
//     stck.push(-1);
//     ll n = s.size();
//     ll res = 0;
//     for(int i=0;i<n;i++)
//     {
//          if(s[i] == '(')
//          {
//              stck.push(i);
//          }
//          else{
//              if(!stck.empty())
//              {
//                  stck.pop();
//              }

//              if(!stck.empty())
//              {
//                  res = max(res,i-stck.top());
//              }
//              else{
//                  stck.push(i);
//              }
//          }
//     }
//     cout<<res<<"\n";
// }

/* LIS (Longest increasing subsequence) --> 
O(Nlog(N)) time complexity using Binary search 
*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// int main() 
// {
//      ll n;
//      cin>>n;
//      ll ar[n];
//      for(int i=0;i<n;i++)
//      {
//          cin>>ar[i];
//      }
//      vector<ll> dp(n+1);
//      dp[0] = INT_MIN;
//      for(int i=1;i<=n;i++)
//      {
//          dp[i] = INT_MAX;
//      }

//      for(int i=0;i<n;i++)
//      {
//          ll vv = upper_bound(dp.begin(),dp.begin()+n+1,ar[i])-dp.begin();
//          if(dp[vv-1]<ar[i] && ar[i]<dp[vv])
//          {
//              dp[vv] = ar[i];
//         }
//      }
//      ll le = 0;
//      for(int i=1;i<=n;i++)
//      {
//          if(dp[i]!=INT_MAX)
//          {
//              le = i;
//          }
//      }
//      cout<<le<<"\n";
// }

/* Catalan Numbers 
(Find the number of BST's which can be formed using 0,1,2,3,....n) nodes.

Catalan numbers : for n=0,1,2,3,4..... --->  1,1,2,5,14,42,....
given a number n , calculate the number of BST that can be formed
 */
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// int main() 
// {
//      ll n;
//      cin>>n;
//      ll dp[n+1] = {0};
//      dp[0] = 1;
//      dp[1] = 1;
//      for(int i=2;i<=n;i++)
//      {
//          for(int j=1;j<=i;j++)
//          {
//              dp[i] = (dp[i] + (dp[j-1]*dp[i-j])%MOD)%MOD;
//          }
//      }
//      for(int i=0;i<=n;i++)
//      {
//          cout<<dp[i]<<" ";
//      }
//      cout<<"\n";
//      cout<<dp[n]<<"\n";
// }