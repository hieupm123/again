#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define double long double
#define int long long
#define minn(a,b,c) min(a, min(b,c))
#define maxx(a,b,c) max(a, max(b,c))
#define mxvt(a) max_element(a.begin(),a.end())
#define mnvt(a) min_element(a.begin(),a.end())
string Y = "YES";
string N = "NO";
int M = 1e9 + 7;
void solve(){
    int n; cin>>n;
    vector<pair<int,int>> A(n + 100);
    for(int i = 1; i <= n; ++i){
        cin>>A[i].first>>A[i].second;
    }
    vector<pair<int,int>> B(n + 100);
    for(int i = 0; i < n - 1; ++i){
        cin>>B[i].first>>B[i].second;
    }
    vector<vector<int>> dp(n + 100, vector<int>(100));
    for(int i = 1; i <= n; ++i){
        dp[i][0] = A[i].first;
        dp[i][1] = A[i].second;
        cout<<A[i].first<<" "<<A[i].second<<" ";
    }
    for(int i = 0; i < n - 1; ++i){
        int a = B[i].first, b = B[i].second;
        dp[b][0] = max(abs(dp[a][0] - A[b].first),abs(dp[a][1] - A[b].first));
        dp[b][1] = max(abs(dp[a][0] - A[b].second),abs(dp[a][1] - A[b].second));
        // dp[a][0] = max(abs(dp[b][0] - A[a].first),abs(dp[b][1] - A[a].first));
        // dp[a][1] = max(abs(dp[b][0] - A[a].second),abs(dp[b][1] - A[a].second));
    }
    int a = B[n - 2].first, b = B[n - 2].second;
    cout<<max(dp[b][0],dp[b][1]);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    cin >> t;
    // int i = 1;
    while(t--) {
        // cout<<"Case #"<<i<<": ";
        solve();
        cout<<"\n";
        // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
        // ++i;
    }
}