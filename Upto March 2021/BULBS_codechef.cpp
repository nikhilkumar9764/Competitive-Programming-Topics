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
        string st;
        cin>>st;
        ll cnt = 0;
        vector<ll> end,bw; 
        ll pos1 = 0,pos2 = 0;
        for(int i=0;i<st.size();i++)
        {
            if(st[i] == '0')
            {
                ++cnt;
            }
            else if(st[i] == '1'){
                pos1 = i;
                break;
            }
        }
        if(cnt == n)
        {
            cout<<0<<"\n";
            continue;
        }
        end.push_back(cnt);
        cnt = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(st[i] == '0')
            {
                ++cnt;
            }
            else  if(st[i] == '1'){
                pos2 = i;
                break;
            }
        }
        end.push_back(cnt);
        cnt = 0;
        for(int i=pos1+1;i<pos2;i++)
        {
            if(st[i] == '0')
            {
                ++cnt;
            }
            else if(st[i] == '1'){
                if(cnt>0)
                {
                bw.push_back(cnt);
                cnt = 0;
                }
            }
        }
        if(bw.size() == 0)
        {
            cout<<0<<"\n";
            continue;
        }
        sort(end.begin(),end.end(),greater<ll>());
        sort(bw.begin(),bw.end(),greater<ll>());
        ll s1 = accumulate(end.begin(),end.end(),0);
        ll s2 = accumulate(bw.begin(),bw.end(),0);
        ll tot = s1+s2;
           if(k == 0)
            {
                cout<<tot<<"\n";
            }
            else{
                ll sm = 0;
                ll te_ind = 0;
                ll p = 0;
                 if(k%2 == 1)
                 {
                      k = k-1;
                     if(end.size()>0)
                     {
                       sm+=end[0];
                       te_ind++;
                     }
                 }
                for(p=0;p<bw.size();p++)
                {
                    if(k>2)
                    {
                        sm+=bw[p];
                        k = k-2;
                    }
                    else{
                        break;
                    }
                }

                if(k>=2)
                {
                     ll sk =0;
                     if(te_ind == 0)
                     {
                         sk+= end[0]+end[1];
                     }
                     else{
                         sk+=end[1];
                     }
                    if(p<bw.size())
                    {
                        sm+=max(bw[p],sk);
                    }
                    else{
                        sm+=sk;
                    }
                }
                ll fin_ans = tot-sm;
                cout<<fin_ans<<"\n";
            }
        end.clear();
        bw.clear();
    }
}