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
Problem link - https://www.spoj.com/problems/FREQ2/
Be careful with cnt2[0] it must be initialized to n (not 0)
This may not be the efficient implementation
Runs in O(n*sqrt(n))
*/

void solve(){
	ll n,nq;
	cin >> n >> nq;
	vector <ll> v(n),hsh(1e5+1),val(n);
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
	vector <pair<ll,ll>> q(nq);
	vector < vector <pair<ll,ll>>> w(m);
	for(ll i=0;i<nq;i++){
		cin >> q[i].first >> q[i].second;
		w[q[i].first/k].pb(mpa(q[i].second,i));
	}
	vector <ll> ans(nq);
	for(ll i=0;i<m;i++){
		sort(w[i].begin(),w[i].end());
		ll curl = 2*i,curr = 2*i-1,res = 0;
		vector <ll> cnt1(cnt,0),cnt2(n+1,0);
		cnt2[0] = n;
		for(auto x : w[i]){
			while(curr!=x.first){
				curr++;
				cnt2[cnt1[v[curr]]]--;
				cnt1[v[curr]]++;
				cnt2[cnt1[v[curr]]]++;
				res = max(cnt1[v[curr]],res);
			}
			ll a = q[x.second].first;
			while(curl<a){
				cnt2[cnt1[v[curl]]]--;
				cnt1[v[curl]]--;
				cnt2[cnt1[v[curl]]]++;
				curl++;
				if(!cnt2[res]){
					res--;
				}
			}
			while(curl>a){
				curl--;
				cnt2[cnt1[v[curl]]]--;
				cnt1[v[curl]]++;
				cnt2[cnt1[v[curl]]]++;
				res = max(cnt1[v[curl]],res);
			}
			ans[x.second] = res;
		}
	}
	for(ll i=0;i<nq;i++){
		cout << ans[i] << endl;
	}
	cout << endl;
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
