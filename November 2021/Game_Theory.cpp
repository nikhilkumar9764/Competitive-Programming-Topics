/*
Given a certain number of piles each of them containing some number of coins. 2 players are playing a game optimally ,
and in one move they can remove   [a,b] = [1,3] no of coins inclusive from any of the piles. We have to tell who will win

Soln : Calculate Sprague-grundy numbers upto n and then check XOR(G(A[i]^G(A[i+1])^......G(A[n]))
and if XOR!=0 -->First player wins the contest
XOR == 0 --> Second player wins the contest
*/





/*Game theory -1 

You are given N piles of stones.
Each pile has same number of stones M.
Two players 1 and 2 play a game in which player 1 always moves first.
The rules are :-

Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
You have to find the winner.
Input Format
First line consists of number of test cases T. Each test case consists of two integers N and M.

Constraints
1 <= T <= 100
1 <= N,M <= 1000000

Output Format
Print 1 if player 1 wins else print 2.

Sample Input
2
2 2
1 4
Sample Output
2
1
*/


// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// ll calc_mex(set<ll> se)
// {
//     ll vv = 0;
//     while(se.find(vv)!=se.end())
//     {
//     	vv++;
//     }
//     return vv;
// }

// std::set<ll> get_divisors(ll n)
// {
//     set<ll> se;
//     for(int i=2;i<=sqrt(n);i++)
//     {
//         if(n>0 && n%i == 0)
//         {
//               while(n%i==0)
//               {
//                   n = n/i;
//                   se.insert(n/i);
//                   se.insert(i);
//               }
//         }
//     }
//     se.insert(1);
//     return se;
// }

// ll calc_grundy(ll num)
// {
//        if(num==0)
//        {
//            return 0;
//        }
//        if(num==1)
//        {
//            return 0;
//        }
//        set<ll> sp = get_divisors(num);
//        set<ll> res;
//        for(auto it : sp)
//        {
//            res.insert(calc_grundy(it));
//        }
//        return calc_mex(res);
// }

// int main()
// {
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//        ll n,m;
//     cin>>n>>m;
//     ll an = calc_grundy(m);
//     if(n%2 == 0)
//     {
//         cout<<2<<"\n";
//     }
//     else{
//         if(an!=0)
//         {
//            cout<<1<<"\n";
//         }
//         else{
//             cout<<2<<"\n";
//         }
//     }
//     }
	
// }

/* Game theory-II 
You are given N piles of stones.
Each pile has some number of stones Mi.
Two players 1 and 2 play a game in which player 1 always moves first.
The rules are :-
1.Player will randomly choose 1 pile whose height is A and reduce the number of stones in that pile to B such that B is a divisor of A and B != A ( 1<= B < A).
2.Player who cannot make a move looses that is if all the piles are of size 1 the player will loose.
You have to find the winner.

Input Format
First line consists of number of test cases T. Each test case consists of an integer N. Then follow N integers denoting number of stones in ith pile.

Constraints
1 <= T <= 100
1 <= N <= 100
1 <= Mi <= 1000000

Output Format
First line consists of number of test cases T. Each test case consists of two integers N and M.

Sample Input
2
2 
1 2
3 
1 2 3
Sample Output
1
2*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int output[1000005];
void findfactor(int n,vector<int>& v){
    v.push_back(1);
    for(int i=2;i<=sqrt(n);i++){
         if(n%i==0)
         {
             if(i==(n/i))
             {
                 v.push_back(i);
             }
             else
             {
                 v.push_back(i);
                 v.push_back(n/i);
             }
         }
    }
}
int mexnumber(set<int> s){
    int mex=0;
    while(s.find(mex)!=s.end())
        mex++;
    return mex;
}
int grundnumber(int n){
    if(n==1)
       return 0;
    if(output[n]!=-1)
       return output[n];
    vector<int> v;
    findfactor(n,v);
    set<int> s;
    for(int i=0;i<v.size();i++){
      s.insert(grundnumber(v[i]));
    }
    return output[n] = mexnumber(s);
}
void winnerofgame(int* arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=grundnumber(arr[i]);
    }
    if(ans!=0)
       cout<<"1"<<endl;
    else 
       cout<<"2"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         memset(output,-1,sizeof(output));
         int* pilesize=new int[n];
         for(int i=0;i<n;i++)
            cin>>pilesize[i];
         winnerofgame(pilesize,n);

    }
    return 0;
}