#include<iostream>
#include<math.h>
#include<vector>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<map>
#include<list>
#include<set>
#include<bitset>
using namespace std;
typedef long long ll;
set<vector<int>> m;
set<vector<int>> m_null;
// vector<int> x = {1,-1,0,0};
// vector<int> y = {0,0,-1,1};
// void creative(vector<int> a){
// 	for(int i = 0; i < x.size(); ++i){
// 		vector<int> b;
// 		b.push_back(a[0] + x[i]);
// 		b.push_back(a[1] + y[i]);
// 		m_null.insert(b);
// 	}
// }
int light_son(vector<vector<int>> a, vector<vector<int>> b){
	m.insert({1,1});
	// m_null.insert({1,1});
	int k = 1;
	// creative({1,1});
	for(int i = 0; i < a.size(); ++i){
		if(m.find(a[i]) != m.end()){
			if(m.find(a[i]) == m.end()){
				m.insert(a[i]);
				// m_null.insert(a[i]);
				++k;
				// creative(a[i]);
			}
			if(m.find(b[i]) == m.end()){
				++k;
				m.insert(b[i]);
				// m_null.insert(b[i]);
				// creative(b[i]);
			}
		}
	}
	return k;
}
int main(){
	int a,b,e;
	vector<vector<int>> c;
	vector<vector<int>> d;
	cin>>a>>b;
	for(int i = 0; i < b; ++i){
		vector<int> m;
		for(int j = 0; j < 2; ++j){
			cin>>e;
			m.push_back(e);
		}
		c.push_back(m);
		m.clear();
		for(int j = 0; j < 2; ++j){
			cin>>e;
			m.push_back(e);
		}
		d.push_back(m);
	}
	cout<<light_son(c,d);
	cout<<endl;
}	