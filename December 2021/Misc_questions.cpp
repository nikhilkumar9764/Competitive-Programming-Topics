/* SDE-1 Konsberg Digital Hiring Challenge 

Given an array of N numbers , you need to make N/2 numbers square of some element and
the rest of N/2 elements such that they are not square of any element 
  1<=T<=10^3
  1<=N<=10^6
*/

#include<bits/stdc++.h>
using namespace std;
using ll  =long long int;
#define MOD (ll) (1e9+7)
 
ll equalizeIt (ll N, vector<ll> Arr) {
  vector<pair<ll,ll>> x;
  for(int i=0;i<N;i++)
  {
     long double vp = sqrt(Arr[i]);
     ll v1 = floor(vp);
     ll v2 = ceil(vp);
     ll myval = min(abs(Arr[i]-(v1*v1)), abs(Arr[i]-(v2*v2)));
     x.push_back({myval,i});
  }
  sort(x.begin(),x.end());
  ll su = 0;
  bool vis[N] = {false};
  for(int i=0;i<N/2;i++)
  {
      su+=x[i].first;
      vis[x[i].second] = true;
  }
  
  for(int i=0;i<N;i++)
  {
      if(vis[i] == false)
      {
          double vv = sqrt(Arr[i]);
          ll ob = floor(vv);
          if(ob*ob == Arr[i] && Arr[i] == 0)
          {
               su+=2;
          }
          else if(ob*ob == Arr[i] && Arr[i]>0)
          {
              su+=1;
          }
      }
  }
  return su; 
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<long long> Arr(N);
        for(int i_Arr = 0; i_Arr < N; i_Arr++)
        {
        	cin >> Arr[i_Arr];
        }
 
        long long out_;
        out_ = equalizeIt(N, Arr);
        cout << out_;
        cout << "\n";
    }
}

/*Count the number of islands in the matrix */

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

#define COL 3
void dfs(ll x,ll y,bool vis[][COL],ll ar[][COL],ll n)
{
	vis[x][y] = true;
	if((x-1)>=0 && !vis[x-1][y] && ar[x-1][y]==1)
	{
		dfs(x-1,y,vis,ar,n);
	}
	if((x+1)<n && !vis[x+1][y] && ar[x+1][y]==1)
	{
		dfs(x+1,y,vis,ar,n);
	}
	if((y-1)>=0 && !vis[x][y-1] && ar[x][y-1]==1)
	{
		dfs(x,y-1,vis,ar,n);
	}
	if((y+1)<n && !vis[x][y+1] && ar[x][y+1]==1)
	{
		dfs(x,y+1,vis,ar,n);
	}
}

int main()
{
	ll n;
	cin>>n;
	bool vis[n][COL] = {false};
	ll ar[n][COL];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ar[i][j];
		}
	}
	
	ll no_island = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		    if(!vis[i][j] && ar[i][j] == 1)
		    {
		        cout<<i<<" "<<j<<"\n";
		    	no_island++;
		    	dfs(i,j,vis,ar,n);
		    }
		    
		    for(int i=0;i<n;i++)
        	{
		      for(int j=0;j<n;j++)
		       {
		           cout<<vis[i][j]<<" ";
		       }
		       cout<<"\n";
            }
		}
	}
	cout<<no_island<<"\n";
}