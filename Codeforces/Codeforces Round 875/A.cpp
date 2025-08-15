#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void dfs(ll parent ,ll node,vector<vector<ll>>&adj,map<pair<ll,ll>,ll>&indexes,vector<ll>&visited,vector<ll>&dp){
     visited[node]=1;
     for(auto ngh:adj[node]){
          if(visited[ngh]==0){
            ll minn=min(node,ngh);
            ll maxx=max(node,ngh);
            auto p2=make_pair(minn,maxx);
            auto p1=make_pair(min(node,parent),max(node,parent));
            if(indexes[p1]<=indexes[p2]){
                dp[ngh]=dp[node];
            }else{
                dp[ngh]=dp[node]+1;
            }
            dfs(node,ngh,adj,indexes,visited,dp);
          }
     }
}
void solve()
{
   ll n;
   cin>>n;
   vector<vector<ll>>adj(n+1);
   map<pair<ll,ll>,ll>indexes;
   for(ll i=0;i<n-1;i++){
     ll u,v;
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
     if(u>v) swap(u,v);
     indexes[{u,v}]=i;
   }

   vector<ll>dp(n+1,0);
   for(auto it:adj[1]){
    dp[it]=1;
   }
   vector<ll>visited(n+1,0);
   dp[1]=1;
   for(ll i=0;i<adj[1].size();i++){
       dfs(1,adj[1][i],adj,indexes,visited,dp);
   }
   ll ans=*max_element(dp.begin(),dp.end());
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