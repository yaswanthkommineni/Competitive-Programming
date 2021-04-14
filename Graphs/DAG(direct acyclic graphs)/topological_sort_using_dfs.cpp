/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

const ll M = 2e5+1;
vector < vector <ll> > g(M);
vector <ll> ans,col(M);
bool cycle = false;

void dfs(ll u){
	col[u] = 1;
	for(auto x : g[u]){
		if(col[x]){
			if(col[x] == 1) cycle = true;
			continue;
		}
		dfs(x);
	}
	col[u] = 2;
	ans.push_back(u);
}

void solve(){
	ll n,m;
	cin >> n >> m;
	for(ll i=0;i<m;i++){
		ll u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(ll i=1;i<=n;i++){
		if(!col[i]) dfs(i);
	}
	reverse(ans.begin(),ans.end());
	for(auto x : ans) cout << x << " ";
	cout << endl;
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

