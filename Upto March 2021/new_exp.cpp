#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
#define ROW  5
#define COL  5
bool safe(int i,int j,int n,int m,vector<vector<int>> &ar,vector<vector<bool>> &visited)
{
	if(i>=0 && i<n && j>=0 && j<m && ar[i][j]>0 && !visited[i][j])
	{
		return true;
	}
	else{
		return false;
	}
}
void dfs(int i,int j,int n,int m,vector<vector<int>> &ar,vector<vector<bool>> &visited)
{
	int cnt = 0;
	int obtx[8]= {1,-1,0,0,1,1,-1,-1};
	int obty[8]= {0,0,1,-1,1,-1,-1,1};
	visited[i][j] = true;
	for(int p=0;p<8;p++)
	{
		if(safe(i+obtx[p],j+obty[p],n,m,ar,visited))
		{
			dfs(i+obtx[p],j+obty[p],n,m,ar,visited);
		}
	}
}
int main()
{
    int n,m;
    cin>>n>>m;
	vector<vector<int>> ar(n,vector<int>(m));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ar[i][j];
		}
	}
    vector<vector<bool>> visited(n,vector<bool>(m));
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visited[i][j] = false;
		}
	}
	ll cnt = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		    if(ar[i][j] && !visited[i][j])
		    {
		    	dfs(i,j,n,m,ar,visited);
		    	 ++cnt;
		    }
		}
	}
	cout<<cnt<<"\n";
}

