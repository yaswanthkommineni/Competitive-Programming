/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 100001;
vector <pair<int,int>> st(2*pow(2,ceil(log2(M)))+1);
int m;

pair <int,int> combine(pair<int,int> a,pair <int,int> b){
	if(a.first < b.first) return a;
	else if(a.first > b.first) return b;
	else return make_pair(a.first,a.second+b.second);
}

void build(int v){
	if(v<m){
		build(2*v);
		build(2*v+1);
		st[v] = combine(st[2*v],st[2*v+1]);
	}
}

pair <int,int> query(int l,int r){
	pair <int,int> res = {1e9+1,1};
	l+=m;
	r+=m;
	while(l<=r){
		if(l&1) res = combine(res,st[l++]);
		if(!(r&1)) res = combine(st[r--],res);
		l/=2;
		r/=2;
	}
	return res;
}

void update(int u,int s){
	u+=m;
	st[u].first = s;
	u/=2;
	while(u){
		st[u] = combine(st[2*u],st[2*u+1]);
		u/=2;
	} 
}

void solve(){
	int n,q;
	cin >> n >> q;
	m = pow(2,ceil(log2(n)));
	for(int i=0;i<n;i++){
		int a ;
		cin >> a;
		st[m+i] = make_pair(a,1);
	}
	build(1);
	while(q--){
		int o,u,v;
		cin >> o >> u >> v;
		if(o == 1) update(u,v);
		else{
			pair <int,int> res;
			res = query(u,v-1);
			cout << res.first << " " << res.second << endl;
		}
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
