#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define double long double
#define int long long
int n,m;
vector<tuple<int,int,int>> A;
vector<int> E(100000 + 100),dp(100000 + 100, INT_MAX);
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        int a,b,c; cin>>a>>b>>c;
        A.push_back(make_tuple(a,b,c));
    }
    dp[1] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < A.size(); ++j){
            int a,b,c; tie(a,b,c) = A[j];
            dp[b] = min(dp[a] + c,dp[b]);
        }
    }
    for(int i = 1; i <= n; ++i){
        cout<<dp[i]<<" ";
    }
}