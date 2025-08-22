#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
    ll n;
    cin>>n;
    string a;
    cin>>a;
    ll m;
    cin>>m;
    string b;
    string c;
    cin>>b;
    cin>>c;
    for(ll i=0;i<c.size();i++){
        if(c[i]=='D'){
            a.push_back(b[i]);
        }else{
            a=b[i]+a;
        }
    }
    cout<<a<<endl;
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