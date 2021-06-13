/*
yaswanth phani kommineni
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mpa make_pair
#define endl '\n'

// for directed graph
const ll M = 501; // maximum number of vertices
vector < vector <ll> > w(M, vector <ll> (M));// weights

void solve(){
	ll n,m;
	cin >> n >> m; // number of vertices and edges
	for(ll i=0;i<m;i++){
		ll u,v,W;
		cin >> u >> v >> W;
		w[u][v] += W;
	}
	ll source,sink;
	cin >> source >> sink;// enter the values of source and sink
	ll flow = 0;
	while(true){
		vector <ll> p(n+1,-1);
		queue <ll> q;
		q.push(source);
		while(!q.empty()){
			auto u = q.front();
			q.pop();
			if(u == sink){
				break;
			}
			for(ll i=1;i<=n;i++){
				if(w[u][i] && p[i] == -1){
					p[i] = u;
					q.push(i);
				}
			}
		}
		if(p[sink] == -1) break;
		ll cur = sink,mn = (ll)1e18;
		while(cur!=source){
			mn = min(mn,w[p[cur]][cur]);
			cur = p[cur];
		}
		cur = sink;
		while(cur!=source){
			w[p[cur]][cur]-=mn;
			w[cur][p[cur]]+=mn;
			cur = p[cur];
		}
		flow += mn;
	}
	cout << flow << endl;
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("input.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	tc = 1;
	//cin >> tc;
	for(int i=1;i<=tc;i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
