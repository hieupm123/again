#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
int n,q;
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>q;
   vector<int> A(n);
   for(int i = 1; i <= n; ++i){
      cin>>A[i];
   }
   for(int i = 0; i < q; ++i){
      int a; cin>>a;
      if(a == 1){
         int b,c,d; cin>>b>>c>>d;
         for(int i = b; i <= c; ++i){
            A[i] += d;
         }
      }else{   
         int b; cin>>b;
         cout<<A[b]<<"\n";
      }
   }
}