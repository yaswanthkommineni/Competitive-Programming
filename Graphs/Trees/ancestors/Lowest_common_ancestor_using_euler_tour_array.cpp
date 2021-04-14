/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n';

//*** TESTED ***

const ll M = 2e5+1,M_ = (ll)1<<(ll)ceil(log2(2*M));
vector <ll> eulerArray,depth(M);
vector < vector <ll> > g(M);
vector <bool> vis(M);
vector <pair<ll,ll>> st(2*M_);

void dfs(ll u){
	vis[u] = true;
	for(auto x : g[u]){
		if(vis[x]) continue;
		depth[x] = depth[u]+1;
		eulerArray.push_back(u);
		dfs(x);
	}
	eulerArray.push_back(u);
}

void build(ll u){
	if(u<M_){
		build(2*u);
		build(2*u+1);
		if(st[2*u].second<=st[2*u+1].second){
			st[u] = st[2*u];
		}
		else st[u] = st[2*u+1];
	}
}

ll query(ll l,ll r){
	l+=M_;
	r+=M_;
	pair<ll,ll> res = make_pair(0,1e18);
	while(l<=r){
		if(l&1){
			if(res.second>st[l].second){
				res = st[l];
			}
			l++;
		}
		if(!(r&1)){
			if(res.second>st[r].second){
				res = st[r];
			}
			r--;
		}
		l>>=1;
		r>>=1;
	}
	return res.first;
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
	depth[1] = 1;
	dfs(1);
	for(ll i=0;i<(ll)eulerArray.size();i++){
		st[M_+i] = make_pair(eulerArray[i],depth[eulerArray[i]]);
	}
	build(1);
	vector < vector <ll> > eulerIndices(n+1);
	for(ll i=0;i<(ll)eulerArray.size();i++){
		eulerIndices[eulerArray[i]].push_back(i);
	}
	ll q;
	cin >> q;
	while(q--){
		ll u,v;
		cin >> u >> v;
		u = eulerIndices[u].back();
		v = eulerIndices[v].front();
		if(u>v){
			u^=v;
			v^=u;
			u^=v;
		}
		cout << query(u,v) << endl;
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
