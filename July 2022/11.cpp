/*Leetcode weekly 307 (Minimum no of Hours training to win a competition) */

class Solution {
public:
    string largestPalindromic(string num)
    {
        int cnt[10] = {0};
        for(int i=0;i<num.size();i++)
        {
            cnt[num[i]-'0']++;
        }
        string front = "";
        for(int i=9;i>=0;i--)
        {
            if(i==0 && front.empty())
            {
                continue;
            }
            if(cnt[i]>1)
            {
                while(cnt[i]>1)
                {
                    front+=to_string(i);
                    cnt[i]-=2;
                }
            }
        }
        string fi = front;
        reverse(front.begin(),front.end());
        string rev = front;
        for(int i=9;i>=0;i--)
        {
            if(cnt[i]>0)
            {
                return fi+to_string(i)+rev;
            }
        }
        return fi+rev;
    }
};


/* Corona Problem (Algouniversity)

Corona has affected the country of IslandLand and people need to practice social distancing.
 IslandLand is a country on the X-Axis with M islands floating on water. 
There are N people living in this country.
You have been given the start and end coordinates Li and Ri of all the M islands. 
Suppose the government arranges the people in IslandLand in such a way that all the people have their feet on some island segment.
Your task is to find the largest possible value of the minimum distance between any two people and report it to the government so that the government can ensure social distancing.

Constraints
2≤N≤105
1≤M≤105
0≤Li≤Ri≤1018
INPUT
The first line contains two integers N and M. The next M lines contain two integers Li,Ri denoting the start point and the end point of the island segment.

OUTPUT
Output a single integer indicating the largest possible value of the minimum distance between any two people.

Example
Input:
5 3
0 2
4 7
9 9
Output:
2

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MAX (ll) (1e5+7)
vector<ll> adj[MAX];
ll intime[MAX] , outtime[MAX];
ll subtree[MAX];
bool vis[MAX];
ll val = 0;

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vp;
    ll x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        vp.push_back({x,y});
    }
    sort(vp.begin(),vp.end());
    ll low = 1,hi = 1e18;
    ll min_dist = 0;
    vector<ll> an;
    while(low<=hi)
    {
        ll mid = low+(hi-low)/2;
        ll cnt_people = 0;
        ll prev = 0;
        for(auto it : vp)
        {
            ll lef = it.first;
            ll rig = it.second;
            lef = max(mid+prev,lef);
            ll num = (rig-lef)/mid;
            if(lef<=rig)
            {
                num++;
            }
            if(num>0)
            {
                cnt_people+=num;
                prev = lef+(num-1)*mid;
            }
        }
        if(cnt_people+1>=n)
        {
            an.push_back(mid);
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    cout<<an.back()<<"\n";
}
