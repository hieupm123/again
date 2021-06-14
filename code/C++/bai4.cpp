#include<bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
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
    string a;
    while(getline(cin, a)){
        vector<int> A(5);
        // cout<<a.size();
        if(a.size() >= 6 && a.size() <= 12){
            A[4] = 1;
        }
        for(int i = 0; i < a.size(); ++i){
            // cout<<a[i]<<" ";
            if(a[i] >= 'A' && a[i] <= 'Z'){
                A[0] = 1;
            }
            if(a[i] >= 'a' && a[i] <= 'z'){
                A[1] = 1;
            }
            if(a[i] >= '0' && a[i] <= '9'){
                A[2] = 1;
            }
            if(a[i] == '$' || a[i] == '#' || a[i] == '@'){
                A[3] = 1;
            }
        }
        int h = 1;
        for(int i = 0; i <= 4; ++i){
            // cout<<A[i]<<" ";
            if(A[i] == 0){
                h = 0;
            }
        }
        if(h){
            cout<<a<<" ";
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    // cin >> t;
    // int i = 1;
    while(t--) {
        // cout<<"Case #"<<i<<": ";
        solve();
        // cout<<"\n";
        // cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
        // ++i;
    }
}