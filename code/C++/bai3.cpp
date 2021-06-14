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
    int ans1 = 0, ans2 = 0;
    while(getline(cin, a)){
        for(int i = 0; i < a.size(); ++i){
            cout<<a[i];
            if(a[i] >= 'a' && a[i] <= 'z'){
                ans1++;
            }
            if(a[i] >= 'A' && a[i] <= 'Z'){
                ans2++;
            }
        }
    }
    cout<<"Chữ hoa là: "<<ans2<<"\n";
    cout<<"Chữ thường là: "<<ans1<<"\n";
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