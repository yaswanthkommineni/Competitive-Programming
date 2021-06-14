/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n';

// for 2-SAT answer, visit nodes in reverse topological order of strongly connected components (https://codeforces.com/gym/101987/submission/119426930)

const ll M = 2e5+1;
vector < vector <ll> > g(M),reverseG(M),scc;
vector <bool> vis(M);
vector <ll> order,curScc;

void dfs1(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		dfs1(x);
	}
	order.push_back(u);
}

void dfs2(ll u){
	vis[u] = true;
	curScc.push_back(u);
	for(auto x : reverseG[u]){
		if(vis[x]) continue;
		dfs2(x);
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v);
		reverseG[v].push_back(u);
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	for(ll i=1;i<=n;i++){
		vis[i] = false;
	}
	while(!order.empty()){
		ll u = order.back();
		order.pop_back();
		if(!vis[u]){
			dfs2(u);
			scc.push_back(curScc);
			curScc.clear();
		}
	}
	for(auto x : scc){
		for(auto y : x){
			cout << y << " ";
		}
		cout << endl;
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
