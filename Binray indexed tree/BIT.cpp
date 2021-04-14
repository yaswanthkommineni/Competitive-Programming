/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

// use this part
struct FenwickTree {
	vector<ll> bit;  // binary indexed tree
	ll n;
	FenwickTree(ll s) {
		n = s;
		bit.assign(n, 0);
	}
	FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
		for (ll i = 0; i < (ll)a.size(); i++)
		add(i, a[i]);
	}
	int sum(ll r) {
		ll ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
		ret += bit[r];
		return ret;
	}
	int sum(ll l, ll r) {
		return sum(r)-sum(l-1);
	}
	void add(ll idx, ll delta) {
		for (; idx < n; idx = idx | (idx + 1))
		bit[idx] += delta;
	}
};
// usable part ended
// --------------------------------------------------------------------------

void solve(){
	ll n;
	cin >> n;
	vector <ll> v(n);
	for(ll i = 0;i<n;i++) cin >> v[i];
	struct FenwickTree bit(v);
	for(ll i=0;i<n;i++){
		cout << bit.sum(i) << endl;
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

