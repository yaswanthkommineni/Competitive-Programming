/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n';

const ll M = 1e5+1;
vector < vector <ll> > g(M);
vector <bool> vis(M);
vector <ll> paths(M);

void dfs(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]){
			paths[u]+=paths[x];
			continue;
		}
		dfs(x);
		paths[u]+=paths[x];
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	ll a,b;
	cin >> a >> b;
	paths[b] = 1;
	dfs(a);
	cout << paths[a] << endl;
}

int main(){
	freopen("input.txt","r",stdin);
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

