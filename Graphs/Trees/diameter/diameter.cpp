/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll M = 1e5;
vector < vector <ll> > g(M);
vector <ll> d(M);
vector <bool> vis(M,false);

void dfs(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		d[x] = d[u]+1;
		dfs(x);
	}
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
	dfs(1);
	ll max_node = 0;
	for(ll i=1;i<=n;i++){
		if(d[i]>d[max_node]) max_node = i;
	}
	d.assign(M,0);
	vis.assign(M,false);
	dfs(max_node);
	ll max__node = 0;
	for(ll i=1;i<=n;i++){
		if(d[i]>d[max__node]) max__node = i;
	}
	cout << max_node << " " << max__node << endl;
	// these two are end points of the diameter
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

