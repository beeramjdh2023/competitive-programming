#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
   ll n;
   cin>>n;
   bool flag=true;
   vector<ll>ans;
   for(ll i=10;i<=1e17;i*=10){
      ll div=i+1;
      if(n%div==0){
        flag=false;
         ll val=n/div;
         ans.push_back(val);
      }
   }
   if(flag){
    cout<<0<<endl;
   }else{
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
   }
   return;
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