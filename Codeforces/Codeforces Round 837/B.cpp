#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll pairgrp(ll n){
    return (n*(n+1))/2;
}
void solve()
{
   ll n,m;
   cin>>n>>m;
   unordered_map<ll,vector<ll>>mpp(n+1);
   for(ll i=0;i<m;i++){
       ll a,b;
       cin>>a>>b;
       if(b>a) swap(a,b);
       mpp[a].push_back(b);
   }
   ll l=1;
   ll ans=0;
   for(ll r=1;r<=n;r++){
      if(mpp.count(r)!=0){
        for(ll i=0;i<mpp[r].size();i++){
            ll other=mpp[r][i];
            while(l<=other){
                ans+=(r-1-l+1);
                l++;
            }
        }
      }
   }
   ans+=pairgrp(n-l+1);
   cout<<ans<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t>0)
    {
        t--;
        solve();
    }
    return 0;
}