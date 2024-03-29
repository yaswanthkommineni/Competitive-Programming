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

/*
Time complexity - O(n*sqrt(n))
Problem link : https://codeforces.com/contest/86/problem/D
This may not be the efficient solution. 
It ran in ~2000ms for n = 2e5.
*/

void solve(){
	ll n,t;
	cin >> n >> t;
	vector <ll> v(n),hsh(1e6+1),val(n+1);
	set <ll> s;
	for(ll i=0;i<n;i++){
		cin >> v[i];
		s.insert(v[i]);
	}
	ll cnt = 0;
	for(auto x : s){
		hsh[x] = cnt;
		val[cnt] = x;
		cnt++;
	}
	for(ll i=0;i<n;i++){
		v[i] = hsh[v[i]];
	}
	ll k = (ll)sqrt(n);
	ll m = (n+k-1)/k;
	vector <ll> ans(t);
	vector <pair<ll,ll>> q(t);
	vector < vector <pair<ll,ll>>> w(m);
	for(ll i=0;i<t;i++){
		cin >> q[i].first >> q[i].second;
		q[i].first--;
		q[i].second--;
		w[q[i].first/k].pb(mpa(q[i].second,i));
	}
	for(ll i=0;i<m;i++){
		sort(w[i].begin(),w[i].end());
		vector <ll> c(cnt,0);
		ll curl = k*i,curr = k*i-1,res = 0;
		for(auto x : w[i]){
			while(curr!=x.first){
				curr++;
				c[v[curr]]++;
				res += (2*c[v[curr]]-1)*val[v[curr]];
			}
			ll a = q[x.second].first;
			while(curl<a){
				res -= (2*c[v[curl]]-1)*val[v[curl]];
				c[v[curl]]--;
				curl++;
			}
			while(curl>a){
				curl--;
				c[v[curl]]++;
				res += (2*c[v[curl]]-1)*val[v[curl]];
			}
			ans[x.second] = res;
		}
	}
	for(ll i=0;i<t;i++){
		cout << ans[i] << endl;
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
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
