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
		st[v] = st[2*v]+st[2*v+1];
	}
}

ll query(int l,int r){
	ll res = 0;
	l+=m;
	r+=m;
	while(l<=r){
		if(l&1) res+=st[l++];
		if(!(r&1)) res+=st[r--];
		l/=2;
		r/=2;
	}
	return res;
}

void update(int u,int s){
	u+=m;
	ll dif = s-st[u];
	while(u){
		st[u]+=dif;
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

