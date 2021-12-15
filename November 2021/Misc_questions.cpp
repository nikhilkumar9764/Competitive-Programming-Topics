/* Rain water trapping problem */
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)
#define MAX (ll) (1e3+3)

int main() 
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll lef = 0,rig = n-1;
    ll lef_max = 0,rig_max = 0;
    ll an = 0;
    while(lef<=rig)
    {
         if(ar[lef]<=ar[rig])
         {
             if(ar[lef]>=lef_max)
             {
                 lef_max = ar[lef];
             }
             else{
                 an+=abs(ar[lef]-lef_max);
             }
             lef++;
         }
         else{
             if(ar[rig]>=rig_max)
             {
                 rig_max = ar[rig];
             }
             else{
                  an+=abs(ar[rig]-rig_max);
             }
             rig--;
         }
    }
    cout<<an<<"\n";
}


/*Largest area under a histogram */


/*Three sum --> Given a number n and an array of integers A[] , find the triplets whose sum adds up to 0 */
 