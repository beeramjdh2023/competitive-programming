#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
    ll n;
    cin>>n;
    map<ll,ll>mpp;
    bool flag=false;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        mpp[a]++;
        if(mpp[a]==2){
            flag=true;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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