#include<bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
vector<int> A;
struct node{
	int vl,ct,cg;
};
vector<node> tree;
void down(int cnt){
	if(tree[cnt].ct != 0){
		tree[2 * cnt].vl += tree[cnt].ct;
		tree[2 * cnt + 1].vl += tree[cnt].ct;
		tree[2 * cnt].ct += tree[cnt].ct;
		tree[2 * cnt + 1].ct += tree[cnt].ct;	
		tree[cnt].ct = 0;
	}
}
void down1(int cnt, int l, int r){
	if(tree[cnt].cg != 0){
		tree[2 * cnt].vl = tree[cnt].cg * (r - l + 1);
		tree[2 * cnt + 1].vl = tree[cnt].cg * (r - l + 1);
		tree[2 * cnt].cg = tree[cnt].cg;
		tree[2 * cnt + 1].cg = tree[cnt].cg;
		tree[cnt].cg = 0; 
	}
}
void build(int l, int r, int cnt){
	if(l == r){
		tree[cnt].vl = A[l];
		tree[cnt].ct = tree[cnt].cg = 0;
		return;
	}else{
		int mid = (l + r) / 2;
		build(l,mid,2 * cnt);
		build(mid + 1,r,2 * cnt + 1);
		tree[cnt].vl = tree[2 * cnt + 1].vl + tree[2 * cnt].vl;
	}
}
void up1(int l, int r, int cnt, int a, int b, int c){
	if(b < l || a > r){
		return;
	} 
	if(b >= r && a <= l){
		tree[cnt].vl += c * (b - a + 1);
		tree[cnt].ct += c;
		return;
	}
	down(cnt);
	int mid = (l + r) / 2;
	down1(cnt,l,mid);
	down1(cnt,mid + 1,r);
	up1(l,mid,cnt * 2,a,b,c);
	up1(mid + 1,r,2 * cnt + 1,a,b,c);
	tree[cnt].vl = tree[2 * cnt].vl + tree[2 * cnt + 1].vl; 
}
void up2(int l, int r, int cnt, int a, int b, int c){
	if(b > l || a > r){
		return;
	}
	if(b >= r && a <= l){
		tree[cnt].vl = c * (b - a  + 1);
		tree[cnt].cg = c;
		return;
	}
	int mid = (l + r) / 2;
	down1(cnt,l,mid);
	down1(cnt,mid + 1,r);
	up2(l,mid,2 * cnt,a,b,c);
	up2(mid + 1,r,2 * cnt + 1,a,b,c);
	tree[cnt].vl = tree[2 * cnt].vl + tree[2 * cnt + 1].vl;
}
int query(int l, int r, int cnt, int a, int b){
	if(b < l || a > r){
		return 0;
	}
	if(a <= l && b >= r){
		return tree[cnt].vl;
	}
	down(cnt);
	int mid = (l + r) / 2;
	down1(cnt,l,mid);
	down1(cnt,mid + 1,r);
	return query(l,mid,2 * cnt,a,b) + query(mid + 1,r,2 * cnt + 1,a,b);
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,q; cin>>n>>q;
	A.resize(n + 100); tree.resize(n * 4 + 100);
	for(int i = 1; i <= n; ++i){
		cin>>A[i];
	}
	build(1,n,1);
	for(int i = 0; i < q; ++i){
		int a; cin>>a;
		if(a == 1){
			int b,c,d; cin>>b>>c>>d;
			up1(1,n,1,b,c,d);
		}else if(a == 2){
			int b,c,d; cin>>b>>c>>d;
			up2(1,n,1,b,c,d);
		}else{
			int b,c; cin>>b>>c;
			cout<<query(1,n,1,b,c)<<"\n";
		}
	}
}
