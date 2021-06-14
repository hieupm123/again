#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
int dp[1001][1001];
int32_t main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n,m; cin>>n>>m;
   vector<int> A(n);
   for(int i = 0; i < n; ++i){
      cin>>A[i];
   }
   // sort(A.begin(),A.end());
   // sort(B.begin(),B.end());
   // for(int i = 0; i < m; ++i){
   //    int a; cin>>a;
   //    vector<int>::iterator b = lower_bound(A.begin(),A.end(),a);
   //    if(b == A.end()){
   //       cout<<0<<"\n";
   //    }else{
   //       *b -= a;
   //       cout<<B[b - A.begin()].second<<"\n";
   //    }
   // }
   auto b = lower_bound(A.begin(),A.end(),7);
   cout<<*b<<"\n";
}