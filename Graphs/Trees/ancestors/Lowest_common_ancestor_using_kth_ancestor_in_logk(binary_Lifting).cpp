/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n';

//***TESTED***
// This method is also known as binary lifting

const ll M = 2e5+1;
vector < vector <ll> > g(M);
vector <bool> vis(M);
vector <ll> parent(M),depth(M);

void dfs(ll u){
	for(auto x : g[u]){
		if(x == parent[u]) continue;
		parent[x] = u;
		depth[x] = depth[u]+1;
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
	parent[1] = 0;
	dfs(1);
	// dp[i][j] = j^2th ancestor of i
	// here I chose 20 because 2^19>2e5, so chose wisely
	vector < vector <ll> > dp(n+1, vector <ll> (20,0));
	for(ll i=1;i<=n;i++){
		dp[i][0] = parent[i];
	}
	for(ll j=1;j<=19;j++){
		for(ll i=1;i<=n;i++){
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<20;j++){
			cout << dp[i][j] << " ";
		}
		cout<< endl;
	}
	ll m;
	cin >> m;
	while(m--){
		ll u,v;
		cin >> u >> v;
		if(depth[u]>depth[v]){
			u^=v;
			v^=u;
			u^=v;
		}
		ll k = depth[v]-depth[u];
		for(ll i=0;i<20;i++){
			if(k&((ll)1<<i)){
				v = dp[v][i];
			}
		}
		for(ll i=19;i>=0;i--){
			if(dp[u][i]!=dp[v][i]){
				u = dp[u][i];
				v = dp[v][i];
			}
		}
		if(v!=u) u = parent[u];
		cout << u << endl;
	}
}

int main(){
	freopen("input.txt","r",stdin);
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
