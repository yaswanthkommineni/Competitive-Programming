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

// for maximum independent node set, find maximum graph matching and add one node from each edge in matching.
// this was using flows and cuts algorithm by adding sink and source at vertices n+1 and n+2
const ll M = 1003; // maximum number of vertices + 2
vector < vector <ll> > w(M, vector <ll> (M));// weights

void solve(){
	ll n,m,k;
	cin >> n >> m >> k; // number of vertices on the left and right and number of edges
	n += m;
	for(ll i=0;i<k;i++){
		ll u,v;
		cin >> u >> v;
		v += (n-m);
		w[u][v] += 1;
	}
	for(ll i=1;i<=n-m;i++){
		w[n+1][i] = 1;
	}
	for(ll i=1;i<=m;i++){
		w[n-m+i][n+2] = 1;
	}
	ll source,sink;
	source = n+1;
	sink = n+2;
	ll flow = 0;
	while(true){
		vector <ll> p(n+3,-1);
		queue <ll> q;
		q.push(source);
		while(!q.empty()){
			auto u = q.front();
			q.pop();
			if(u == sink){
				break;
			}
			for(ll i=1;i<=n+2;i++){
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
	for(ll i=1;i<=n-m;i++){
		for(ll j=1;j<=m;j++){
			if(w[j+n-m][i] && w[n+2][j+n-m] && w[i][n+1]){
				cout << i << " " << j << endl;
			}
		}
	}
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
