#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
#define maxx(a,b,c) max(a,max(b,c))
struct node{
	int s = 0,pr = 0,u = 0, d = 0;
};
vector<int> A;
vector<node> tree;
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt].s = A[l];
		tree[cnt].pr = A[l];
	}else{
		int mid = (l + r) / 2;
		build(l,mid,2 * cnt);
		build(mid + 1,r,2 * cnt + 1);
		int a = 2 * cnt, b = 2 * cnt + 1;
		tree[cnt].s = tree[a].s + tree[b].s;
		tree[cnt].pr = maxx(tree[a].pr,tree[b].pr,tree[a].pr + tree[a].d + tree[b].pr + tree[b].u);
		tree[cnt].u = max(tree[a].u,tree[a].s + tree[b].u);
		tree[cnt].d = max(tree[b].d,tree[a].d + tree[b].s);
	}
}
void up(int l, int r, int cnt, int a, int b){
	if(a > r || a < l){
		return;
	}
	if(l == r){
		tree[cnt].s = A[l];
		tree[cnt].pr = A[l];
		return;
	}
	int x = 2 * cnt, y = 2 * cnt + 1;
	int mid = (l + r) / 2;
	up(l,mid,x,a,b);
	up(mid + 1,r,y,a,b);
	tree[cnt].s = tree[x].s + tree[y].s;
	tree[cnt].pr = maxx(tree[x].pr,tree[y].pr,tree[x].pr + tree[x].d + tree[y].pr + tree[y].u);
	tree[cnt].u = max(tree[x].u,tree[x].s + tree[y].u);
	tree[cnt].d = max(tree[y].d,tree[x].d + tree[y].s);
}
node query(int l, int r , int cnt, int a, int b){
	if(a > r || b < l){
		node E;
		return E;
	}
	if(a <= l && b >= r){
		return tree[cnt];
	}
	int mid = (l + r) / 2;
	node X = query(l,mid,2 * cnt,a,b);
	node Y = query(mid + 1,r,2 * cnt + 1,a,b);
	node T;
	T.s = X.s + Y.s;
	T.pr = maxx(X.pr,Y.pr,X.pr + X.d + Y.pr + Y.u);
	T.u = max(X.u,X.s + Y.u);
	T.d = max(Y.d,Y.s + X.d);
	return T;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin>>n>>m;
	int sum = 0;
	A.resize(n + 100); tree.resize(n * 4 + 100);
	for(int i = 0; i < n; ++i){
		cin>>A[i];
	}
	build(1,n,1);
	for(int i = 0; i < m; ++i){
		int a,b; cin>>a>>b;
	}
	cout<<query(1,n,1,1,n).s<<"\n";
	// cout<<tree[1].s<<"\n";s
}
