/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll M = 1e5+1;
vector < vector <ll> > g(M),anc;
ll k;
vector <bool> vis(M);

void dfs(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		anc[x][0] = u;
		for(ll i=1;i<=k;i++) anc[x][i] = anc[anc[x][i-1]][i-1];
		dfs(x);
	}
}

ll get_ancestor(ll u,ll t){
	for(ll i=0;i<=k;i++){
		if(((ll)1<<i)&t) u = anc[u][i];
	}
	return u;
}

void solve(){
	ll n;
	cin >> n;
	for(ll i=0;i<n-1;i++){
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	k = (ll)log2(n);
	anc.assign(M, vector <ll> (k+1,0));
	ll root;
	cin >> root;
	dfs(root);
	ll queries;
	cin >> queries;
	while(queries--){
		ll u,t;
		cin >> u >> t;
		cout << get_ancestor(u,t) << endl;
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	tc = 1;
	//cin >> tc;
	for(int i=1;i<=tc;i++){
		solve();
	}
	return 0;
}
