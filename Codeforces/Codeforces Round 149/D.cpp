#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
   ll n;
   cin>>n;
   string s;
   cin>>s;
   vector<ll>ans(n,1);
   stack<ll>q;
   ll total=0;
   for(ll i=0;i<n;i++){
         if(s[i]=='(') total+=1;
         else total-=1;
   }
   if(total!=0){
    cout<<-1<<endl;
    return;
   }
   for(ll i=0;i<n;i++){
      if(s[i]=='('){
        //    cout<<"yes1"<<endl;
         q.push(i);
      }else if(q.empty()){
        //    cout<<"yes2"<<endl;
         q.push(i);
      }else{
         ll last=q.top();
            // cout<<"yes3"<<endl;
            // cout<<s[last]<<endl;
         if(s[last]=='('){
            ans[last]=2;
            ans[i]=2;
            // cout<<"ans is 2 at "<<last<<" and i "<<i<<endl;
            q.pop();
         }
      }
   }

   if(q.empty()){
     cout<<1<<endl;
     for(ll i=0;i<n;i++){
        cout<<1<<" ";
     }
     cout<<endl;
     return;
   }
    stack<ll>empty;
    swap(q,empty);
    reverse(s.begin(),s.end());
    for(ll i=0;i<n;i++){
      if(s[i]=='('){
         q.push(i);
      }else if(q.empty()){
         q.push(i);
      }else{
         ll last=q.top();
         if(s[last]=='('){
            q.pop();
         }
      }
   }
   if(q.empty()){
    cout<<1<<endl;
    for(ll i=0;i<n;i++){
        cout<<1<<" ";
    }
    cout<<endl;
    return;
   }
   
   cout<<2<<endl;
   for(ll i=0;i<n;i++){
    cout<<ans[i]<<" ";
   }
   cout<<endl;
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