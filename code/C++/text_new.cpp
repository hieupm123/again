#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int slove(vector<int> a, vector<int> b){
	
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> t;
	vector<int> result;
	for(int i = 0; i < a; ++i){
		int m;
		cin>>m;
		t.push_back(m);
	}
	for(int i = 0; i < b; ++i){
		int n;
		cin>>n;
		vector<int> u;
		u.push_back(n);
		result.push_back(slove(t,u));
	}
	for(auto i : result){
		cout<<i<<endl;
	}
}