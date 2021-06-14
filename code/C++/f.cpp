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
int h = 0;
int checked(int a){
    // if(a == 1){
    //     return 1;
    // }
    int b = sqrt(a);
    if(b * b != a){
        return 1;
    }
    return 0;
}
void check(vector<int> A, int a, int b){
    if(b == A.size()){
        if(checked(a)){
            h = 1;
            return;
        }
    }else{
        for(int i = b; i < A.size(); ++i){
            check(A,a*A[i],b + 1);
            if(i == A.size() - 1){
                check(A,a*A[i],b + 1);
            }else{
                check(A,a,b + 1);
            }
        }
    }
}
void solve(){
    int n; cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i){
        cin>>A[i];
    }
    check(A, 1, 0);
    if(h){
        cout<<Y;
    }else{
        cout<<N;
    }
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