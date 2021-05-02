#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> vp;
        int n,m;
        cin>>n>>m;
        int x,y;
        for(int i =0;i<n;i++){
            cin>>x>>y;
            vp.push_back(make_pair(x,y));
        }
        sort(vp.begin(),vp.end());
        while(m--){
            int val;
            cin>>val;
            int it = lower_bound(vp.begin(),vp.end() , make_pair(val,0))-vp.begin();
            if(it == 0)
          {
              cout<<vp[it].first - val<<"\n";
          }
         else
         {
             if(val<vp[it-1].second)
             {
                 cout<<0<<"\n";
             }
             else if(it<vp.size())
             {
                 cout<<vp[it].first-val<<"\n";
             }
             else{
                 cout<<-1<<"\n";
             }
         }
        }
    }
}