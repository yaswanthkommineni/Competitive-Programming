/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 100001;
vector <ll> st(2*pow(2,ceil(log2(M)))+1);
int m;

void build(int v){
	if(v<m){
		build(2*v);
		build(2*v+1);
		st[v] = min(st[2*v],st[2*v+1]);
	}
}

ll query(int l,int r){
	ll res = 1e9+1;
	l+=m;
	r+=m;
	while(l<=r){
		if(l&1) res = min(res,st[l++]);
		if(!(r&1)) res = min(st[r--],res);
		l/=2;
		r/=2;
	}
	return res;
}

void update(int u,int s){
	u+=m;
	st[u] = s;
	u/=2;
	while(u){
		st[u] = min(st[2*u],st[2*u+1]);
		u/=2;
	} 
}

void solve(){
	int n,q;
	cin >> n >> q;
	m = pow(2,ceil(log2(n)));
	for(int i=0;i<n;i++) cin >> st[m+i];
	build(1);
	while(q--){
		int o,u,v;
		cin >> o >> u >> v;
		if(o == 1) update(u,v);
		else cout << query(u,v-1) << endl;
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int z;
	z = 1;
	//cin >> z;
	for(int z1=1;z1<=z;z1++){
		solve();
	}
	return 0;
}
