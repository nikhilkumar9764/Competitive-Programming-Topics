#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
ll ht,width;
bool visited[1000][1000];
bool blocked[1000][1000];
bool valid(ll x,ll y)
{
    if(x<0 || y<0 || x>=ht || y>=width || visited[x][y] || blocked[x][y])
    {
        return false;
    }
    return true;
}

bool find_path(ll x,ll y,ll ex,ll ey)
{
    if(!valid(x,y))
    {
        return false;
    }
    visited[x][y] = 1;
    if(x==ex && y==ey)
    {
        return true;
    }
    bool found = false;
    if(find_path(x,y+1,ex,ey))
    {
        found = true;
    }
    if(find_path(x,y-1,ex,ey))
    {
        found = true;
    }
    if(find_path(x-1,y,ex,ey))
    {
        found = true;
    }
    if(find_path(x+1,y,ex,ey))
    {
        found = true;
    }
    return found;
}

int main()
{
	cin>>ht>>width;
    for(int i=0;i<ht;i++)
    {
        for(int j=0;j<width;j++)
        {
            cin>>blocked[i][j];
        }
    }
    ll srcx,srcy;
    cin>>srcx>>srcy;
    ll destx,desty;
    cin>>destx>>desty;

    for(int i=0;i<ht;i++)
    {
        for(int j=0;j<width;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
    if(find_path(srcx,srcy,destx,desty))
    {
        cout<<"There exists a path from source to destination\n";
    }
    else{
        cout<<"No such path exists\n";
    }
}