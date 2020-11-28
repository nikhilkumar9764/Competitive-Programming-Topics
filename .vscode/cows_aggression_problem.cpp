
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)

int main()
{
    ll n;
    cin>>n;
    if(!check_prime(n))
    {
        cout<<"Not Prime\n";
    }
    else{
        cout<<"prime\n";
    }
}