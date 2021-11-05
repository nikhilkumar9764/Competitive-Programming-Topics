//  /*  I AM VERY BUSY*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

bool compare(const pair<ll,ll> &a , const pair<ll,ll> &b)
{
    return a.second<b.second;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>> vp;
        ll x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            vp.push_back({x,y});
        }
        sort(vp.begin(),vp.end(),compare);
        ll ct = 1;
        ll fi = vp[0].second;
        for(int i=1;i<n;i++)
        {
            if(vp[i].first >= fi)
            {
                fi = vp[i].second;
                ct++;
            }
        }
        cout<<ct<<"\n";
        vp.clear();
    }
}

// /* Biased Standings	 */

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// bool compare(const pair<string,ll> &a , const pair<string,ll> &b)
// {
//     return a.second<b.second;
// }

// int main()
// {
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll n;
//         cin>>n;
//         vector<pair<string,ll>> vp;
//         string x;
//         ll y;
//         for(int i=0;i<n;i++)
//         {
//             cin>>x>>y;
//             vp.push_back({x,y});
//         }
//         sort(vp.begin(),vp.end(),compare);
//         ll ans = 0;
//         for(int i=0;i<n;i++)
//         {
//            ans+=abs(vp[i].second-(i+1));
//         }
//         cout<<ans<<"\n";
//         vp.clear();
//     }
// }


/*  Load Balancing	*/

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long int;
// #define MOD (ll) (1e9+7)

// bool compare(const pair<string,ll> &a , const pair<string,ll> &b)
// {
//     return a.second<b.second;
// }

// int main()
// {
//     while(1)
//     {
//       ll n;
//       cin>>n;
//       if(n == -1)
//       {
//           exit(0);
//           break;
//       }
//       else{
//           ll ar[n];
//           ll su = 0;
//           for(int i=0;i<n;i++)
//           {
//               cin>>ar[i];
//               su+=ar[i];
//           }
//           if(su % n!=0)
//           {
//               cout<<-1<<"\n";
//           }
//           else{
//               ll load = su/n;
//                ll dif = 0;
//                ll max_load = INT_MIN;
//               for(int i=0;i<n;i++)
//               {
//                   dif+=(ar[i]-load);
//                   ll ans = max(dif,-dif);
//                   max_load = max(max_load,ans);
//               }
//               cout<<max_load<<"\n";
//           }
//       }
//     }
// }

/* Defense of a Kingdom 

O(N^2) 

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
    ll n,m,qq;
    cin>>n>>m>>qq;
    ll row[n+1] = {0};
    ll col[m+1] = {0};
    ll max_area = 0;
    ll last_x = 0,last_y = 0;
    while (qq--)
    {
        ll xx,yy;
        cin>>xx>>yy;
        row[xx]++;
        col[yy]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        ll dist_x = 0,dist_y = 0;
        if(row[i] == 1)
        {
            dist_x = i-last_x-1;
            last_x = i;
        }
        last_y = 0;
        for(int j = 1;j<=m;j++)
        {
            if(col[j] == 1)
            {
                dist_y = (j-last_y-1);
                last_y = j;
            }
            ll tmp = dist_x*dist_y;
            max_area = max(max_area,tmp);
        }
    }
    cout<<max_area<<"\n";
    }
}


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
    ll n,m,qq;
    cin>>n>>m>>qq;
    ll row[n+1] = {0};
    ll col[m+1] = {0};
    ll max_area = 0;
    ll last_x = 0,last_y = 0;
    while (qq--)
    {
        ll xx,yy;
        cin>>xx>>yy;
        row[xx]++;
        col[yy]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        ll dist_x = 0,dist_y = 0;
        if(row[i] == 1)
        {
            dist_x = i-last_x-1;
            last_x = i;
        }
        last_y = 0;
        for(int j = 1;j<=m;j++)
        {
            if(col[j] == 1)
            {
                dist_y = (j-last_y-1);
                last_y = j;
            }
            ll tmp = dist_x*dist_y;
            max_area = max(max_area,tmp);
        }
    }
    cout<<max_area<<"\n";
    }
}