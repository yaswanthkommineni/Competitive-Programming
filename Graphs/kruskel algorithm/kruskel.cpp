/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

vector <ll> link(1e5+1),siz(1e5+1,1);
vector < vector <pair<ll,ll>> > g(1e5);

ll find(ll x){
	if(x == link[x]) return x;
	else return (link[x] = find(link[x]));
}

void unite(ll a,ll b){
	a = find(a);
	b = find(b);
	if(siz[a]>siz[b]){
		a^=b;
		b^=a;
		a^=b;
	}
	link[a] = b;
	siz[b]+=siz[a];
}

void solve(){
	ll n,m;
	cin >> n >> m;
	vector < pair<ll, pair<ll,ll> > > v;
	for(ll i=0;i<m;i++){
		ll u,t,w;
		cin >> u >> t >> w;
		v.push_back(make_pair(w,make_pair(u,t)));
	}
	ll ans = 0;
	sort(v.begin(),v.end());
	for(ll i=1;i<1e5+1;i++) link[i] = i;
	for(auto x : v){
		if(find(x.second.first) != find(x.second.second)){
			unite(x.second.first,x.second.second);
			ans+=x.first;
			g[x.second.first].push_back(make_pair(x.second.second,x.first));
			g[x.second.second].push_back(make_pair(x.second.first,x.first));
		}
	}
	cout << ans << endl;
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
