// Counting the number of subarrays in an array that XOR give a particular value

// #include<bits/stdc++.h>
// using namespace std;
// using ll =long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     ll n,k;
//     cin>>n>>k;
//     ll ar[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>ar[i];
//     }
//     ll pref[n];
//     pref[0] = ar[0];
//     for(int i=1;i<n;i++)
//     {
//         pref[i] = ar[i]^pref[i-1];
//     }
//     ll ans = 0;
//     map<ll,ll> ma;
//     for(int i=0;i<n;i++)
//     {
//        ll tmp = pref[i]^k;
//        ans+=ma[tmp];
//        if(tmp == 0)
//        {
//            ++ans;
//        }
//        ma[tmp]++;
//     }
//     cout<<ans<<"\n";
// }


// Longest substring of a string with no repeated characters.
// #include<bits/stdc++.h>
// using namespace std;
// using ll =long long int;
// #define MOD (ll) (1e9+7)
// int main()
// {
//     string s;
//     cin>>s;
//     ll si = s.size();
//     map<char,int> ma;
//     ll st = 0;
//     ll ans = INT_MIN;
//     ll inc = 1;
//     for(int i=0;i<si;i++)
//     {
//         if(ma[s[i]]>=0)
//         {
//            st = max(st,ma[s[i]]+inc);
//         }
//         ma[s[i]] = i;
//         ans = max(ans,(i-st)+1);
//     }
//     cout<<ans<<"\n";
//     cout<<s.substr(st,si-st)<<"\n";
// }

// Longest consecutive sequence O(n)
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
    set<ll> se;
    for(int i=0;i<n;i++)
    {
        se.insert(ar[i]);
    }
    map<ll,ll> ma;
    for(auto it:se)
    {
        if(ma[it-1])
        {
            ma[it] = ma[it-1]+1;
        }
        else
        {
           ma[it] = 1;
        }
    }
    ll maxi = INT_MIN;
    for(auto it:ma)
    {
        maxi = max(maxi,it.second);
    }
    cout<<maxi<<"\n";
}