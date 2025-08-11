#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void buildsegtree(ll ind,ll l,ll r,vector<ll>&segtree,vector<ll>&arr){
     if(l==r){
      segtree[ind]=arr[l];
      return;
     }          
     ll mid=l+(r-l)/2;
     buildsegtree(2*ind+1,l,mid,segtree,arr);
     buildsegtree(2*ind+2,mid+1,r,segtree,arr);
     segtree[ind]=(segtree[2*ind+1])&(segtree[2*ind+2]);
     return;
}

ll getquery(ll start,ll end,ll ind,ll l,ll r,vector<ll>&segtree){
      if((start>r)||(end<l)) return -1;
      if((start<=l)&&(r<=end)){
         // cout<<"for ind "<<ind<<" completely lie"<<endl;
         return segtree[ind];
      }
      ll mid=l+(r-l)/2;
      ll left=getquery(start,end,2*ind+1,l,mid,segtree);
      ll right=getquery(start,end,2*ind+2,mid+1,r,segtree);
      
      if(left==-1){
         // cout<<"for ind "<<ind<<" only right"<<endl;
         return right;
      } 
      if(right==-1){
         // cout<<"for ind "<<ind<<" only left"<<endl;
         return left;
      } 
      ll temp= left&right;
      // cout<<"for ind "<<" both returned"<<endl;
      return temp;
}

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    vector<ll>segtree(4*n);
    buildsegtree(0,0,n-1,segtree,arr);
   //  for(ll i=0;i<4*n;i++){
   //    cout<<segtree[i]<<" ";
   //  }
    ll q;
    cin>>q;
    while(q--){
       ll left,k;
       cin>>left>>k;
       left--;
       ll low=left,high=n-1;
       ll ans=-2;
      //  cout<<"query left and k is "<<low<<" "<<k<<endl;
       while(low<=high){
           ll mid=low+(high-low)/2;
           ll val=getquery(left,mid,0,0,n-1,segtree);
         //cout<<"for mid "<<mid<<" we get "<<val<<endl;
           if(val>=k){
              low=mid+1;
              ans=mid;
           }else{
              high=mid-1;
           }
       }
       cout<<ans+1<<" ";
    }
    cout<<endl;
    
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