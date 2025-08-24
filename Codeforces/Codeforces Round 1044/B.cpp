#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
  ll n;
  cin>>n;
  priority_queue<ll>pq;
  for(ll i=0;i<n;i++){
    ll a;
    cin>>a;
    pq.push(a);
  }
  ll ans=0;
  while(!pq.empty()){
    ll a=pq.top();
    pq.pop();
    ans+=a;
    if(pq.empty()) break;
    pq.pop();
  }
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