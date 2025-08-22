#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
   ll n;
   cin>>n;
   vector<ll>power(23);
   ll val=1;
   for(ll i=0;i<=22;i++){
        power[i]=val;
        val*=3;
   }
   ll ans=0;
   for(ll i=21;i>=0;i--){
      ll val=power[i];
      if((n/val)>0){
        ll time=n/val;
         n=(n%val);
         ll price=power[i+1];
         if(i>0){
            price+=i*power[i-1];
         }
         ans+=price*time;
      }
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