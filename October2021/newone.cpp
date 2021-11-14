/* Amazon SDE-1 Hiring test

Minimum Operations 
Given a number N , split the number into 2 numbers p1,p2 such that sum is minimum possible. this means that digits of the 
original number can belong to any one of the 2 numbers(p1,p2).

Constraints :   1<=T<=10^3
                1<=N<=1e18

Number N = 2435 will give the result as 59 (25+34).
*/
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

//     ll n;
//     cin>>n;
//     string st = to_string(n);
//     sort(st.begin(),st.end());
//     ll su = 0;
//      string s1 ;
//      string s2 ;
//     for(int i=0;i<st.size()/2;i++)
//     {
//          s1+=st[i];
//     }
    
//     for(int i=st.size()/2;i<st.size();i++)
//     {
//          s2+=st[i];
//     }
//     ll n1 = stoll(s1,nullptr,10);
//     ll n2 = stoll(s2,nullptr,10);
//     su = n1+n2;
//     do{
//        ll tmp = 0;
//        string xy = "" , xp = "";
//        for(int i=0;i<st.size()/2;i++)
//     {
//          xy+=st[i];
//     }
    
//     for(int i=st.size()/2;i<st.size();i++)
//     {
//          xp+=st[i];
//     }
//        ll n1 = stoll(xy,nullptr,10);
//        ll n2 = stoll(xp,nullptr,10);
//        tmp = n1+n2;
//        su = min(su,tmp);
//     }while(next_permutation(st.begin(),st.end()));

//     cout<<su<<"\n";
//     }
// }

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)


