#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
   ll n,k;
   cin>>n>>k;
   vector<ll>power(23);
   ll val=1;
   for(ll i=0;i<=22;i++){
        power[i]=val;
        val*=3;
   }
   ll ans=0;
   vector<ll>used(23,0);
   for(ll i=21;i>=0;i--){
      ll val=power[i];
      if((n/val)>0){
        ll time=n/val;
        used[i]=time;
         k-=time;
         n=(n%val);
         ll price=power[i+1]+ (i>0? i*power[i-1]:0);
         ans+=price*time;
      }
   }
   if(k<0){
    cout<<-1<<endl;
   }else{
    for(ll i=22;i>=1;i--){
        ll remove=min(used[i],k/2);
        // cout<<"for ind "<<i<<" k is "<<k<<endl;
        // cout<<"used[i] is "<<used[i]<<" and k is "<<k<<endl;
        // cout<<"remove for this is "<<remove<<endl;
        k-=(2*remove);
        used[i-1]+=3*remove;
        ll price_rm=remove*(power[i+1]+i*power[i-1]);
        ll price_add=3*remove*(power[i]+(i<2? 0:(i-1)*power[i-2]));
        ans+=price_add;
        ans-=price_rm;
    }
    cout<<ans<<endl;
   }

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