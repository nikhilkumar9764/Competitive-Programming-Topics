#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll ar[n][m];
        bool vis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j] = false;
            }
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ar[i][j];
                if(ar[i][j] == 1)
                {
                    vis[i][j] = true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
           bool fl = false;
            for(int j=0;j<m;j++)
            {
                 if(ar[i][j] == 1)
                 {
                     fl = true;
                 }
                 else if(ar[i][j]== -1)
                 {
                     fl = false;
                 }
                 else if( fl == true)
                 {
                     vis[i][j] = true;
                 }
            }

            fl = false;
            for(int j=m-1;j>=0;j--)
            {
                 if(ar[i][j] == 1)
                 {
                     fl = true;
                 }
                 else if(ar[i][j]== -1)
                 {
                     fl = false;
                 }
                 else if(fl == true)
                 {
                     vis[i][j] = true;
                 }
            }
        }

        for(int i=0;i<m;i++)
        {
            bool fl = false;
            for(int j=0;j<n;j++)
            {
                 if(ar[j][i] == 1)
                 {
                     fl = true;
                 }
                 else if(ar[j][i]== -1)
                 {
                     fl = false;
                 }
                 else if(fl == true)
                 {
                     vis[j][i] = true;
                 }
            }

            fl = false;
            for(int j=n-1;j>=0;j--)
            {
                 if(ar[j][i] == 1)
                 {
                     fl = true;
                 }
                 else if(ar[j][i]== -1)
                 {
                     fl = false;
                 }
                 else if(fl == true)
                 {
                     vis[j][i] = true;
                 }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                {
                   ++cnt;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}