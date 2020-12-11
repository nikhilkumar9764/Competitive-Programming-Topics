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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<k;i++)
        {
            if(s[i] == '?')
            {
                for(int j=i+k;j<n;j+=k)
                {
                    if(s[j] != '?')
                    {
                        s[i] = s[j];
                        break;
                    }
                }
            }
        }
        ll fl = 0;
        for(int i=0;i<k;i++)
        {
            if(s[i] != '?')
            {
                for(int j=i+k;j<n;j+=k)
                {
                    if(s[j] == '?')
                    {
                        s[j] = s[i];
                    }
                    else if(s[i] == s[j])
                    {
                        continue;
                    }
                    else{
                        fl = 1;
                        break;
                    }
                }
            }
        }
       if(fl)
       {
           cout<<"NO\n";
       }
       else
       {
           ll no_one = 0,no_zero = 0;
           for(int i=0;i<k;i++)
           {
               if(s[i] == '1')
               {
                   no_one++;
               }
               else if(s[i] == '0'){
                    no_zero++;
               }
           }
           if(no_one <=(k/2) && no_zero<=(k/2))
           {
               cout<<"YES\n";
           }
           else{
               cout<<"NO\n";
           }
       }

    }
}