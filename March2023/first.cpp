/* 
Thoughtworks Hiring Challenge 
Given a number N and M pair of numbers denoting the element at a particular index by the pair 
(index , element) . Find out the array of numbers which will satisfy the below condition :
for any subarray of length k , the XOR of all numbers in the subarray should be the same. 


Solution: Initialize a variable curr = 0
 would be to read all the M pair of numbers and put (index%K) as the element in a 
dictionary and then for all the indexes which are not present in the dictionary the element at that 
index would be the value of curr , then increment curr by 1 . 
*/


/* Given an array of N numbers , find among all subsequences of length M the minimum most product of first and last 
element of the chosen subsequence . 

 1<= T<=10
 1<=N<=10^5 ;  1<=A[i]<=10^6

 Example : N = 7 , M = 5 , A =[2,3,4,1,3,3,9]
 Output should be 6 for the subsequence [2,3,4,1,3]. 

 Solution would be to find prefix and suffix arrays consisting of minimum element found so far from the left or right end 
 Then from 0 to N-M find the minimum most product of pref[i]*suffix[i+M] and that would be the answer .
*/


/* Given 2 numbers N,M find the number at which sum of elements from 1 to number exceeds sum of elements 
i.e in each day we remove that number of stones from N or M ,find the day number at which you cannot perform this operation

 1 <= N,M <= 1e9
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ll n,m;
    cin>>n>>m;
    
    ll tot = n+m;
    ll ans , lo = 1,hi=1e9;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        ll su = (mid*(mid+1))/2;
        
        if(su>tot)
        {
            ans = mid;
            hi = mid-1;
        }
        
        if(su<=tot)
        {
            lo = mid+1;
        }
    }
    ans-=1;
    ll vv = (ans*(ans+1))/2;
    ll res = tot-vv;
    cout<<ans+1<<" "<<0<<" "<<res<<"\n";
}
