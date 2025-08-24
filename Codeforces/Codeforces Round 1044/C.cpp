#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
   ll n;
   cin>>n;
   priority_queue<pair<ll,ll>>pq;
   for(ll i=1;i<=n;i++){
      cout<<"? "<<i<<" "<<n<<" ";
      for(ll j=1;j<=n;j++){
         cout<<j;
         if(j<n){
            cout<<" ";
         }
      }
      cout<<endl;
      cout.flush();
      ll a;
      cin>>a;
      pq.push({a,i});
   }
   vector<ll>ans;
   ans.push_back(pq.top().second);
   ll size=pq.top().first;
   pq.pop();
   // ans.size()!=size
   while(!pq.empty()){
      ll start=pq.top().second;
      pq.pop();
      cout<<"? "<<ans.back()<<" 2 "<<ans.back()<<" "<<start;
      cout<<endl;
      cout.flush();
      ll val;
      cin>>val;
      if(val==2){
         ans.push_back(start);
      }
   }
   cout<<"! "<<ans.size()<<" ";
   for(ll i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
   }
   cout<<endl;
   cout.flush();
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