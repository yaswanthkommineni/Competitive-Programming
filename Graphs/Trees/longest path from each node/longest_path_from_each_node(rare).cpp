/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll M = 1e5;
vector < vector <ll> > g(M);
vector < pair <ll,ll> > d(M);
// final answer is d[i].first
vector <bool> vis(M);

void dfs1(ll u){
	ll a = -1, b = -1;
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		dfs1(x);
		if(d[x].first>=a){
			b = a;
			a = d[x].first;
		}
	}
	d[u] = make_pair(a+1,b+1);
}

void dfs2(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		ll k = d[u].first;
		if(k == d[x].first + 1) k = d[u].second;
		if(k+1 >= d[x].first){
			d[x].second = d[x].first;
			d[x].first = k+1;
		}
		else if(k+1 >= d[x].second) d[x].second = k;
		dfs2(x);
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
	dfs1(1);
	vis.assign(M,false);
	dfs2(1);
	for(ll i=1;i<=n;i++) cout << d[i].first << " ";
	cout << endl;
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
