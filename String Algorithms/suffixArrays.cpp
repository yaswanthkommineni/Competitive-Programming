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

void solve(){
	string s;
	cin >> s;
	ll n = (ll)s.size();
	ll m = ((1<<((ll)ceil((ld)log2(n))))<<1);
	while((ll)s.size()!=m){
		s.pb('$');
	}
	ll cnt = 1;
	vector <pair<char,ll>> c(n);
	for(ll i=0;i<n;i++){
		c[i] = mpa(s[i],i);
	}
	sort(c.begin(),c.end());
	vector <ll> v(m);
	for(ll i=0;i<m;i++){
		if(i>=n){
			v[i] = 0;
		}
		else{
			if(i && c[i].first!=c[i-1].first){
				cnt++;
			}
			v[c[i].second] = cnt;
		}
	}
	vector < vector <pair<ll,ll>> > so1(n+1),so2(n+1);
	for(ll i=1;i<(ll)log2(m);i++){
		for(ll j=0;j<n;j++){
			so1[v[j+((ll)1<<(i-1))]].pb(mpa(v[j],j));
		}
		for(ll j=0;j<=n;j++){
			for(auto x : so1[j]){
				so2[x.first].pb(mpa(j,x.second));
			}
		}
		cnt = 0;
		for(ll j=0;j<=n;j++){
			for(ll k=0;k<(ll)so2[j].size();k++){
				if(!k || so2[j][k-1].first!=so2[j][k].first) cnt++;
				v[so2[j][k].second] = cnt;
			}
		}
		for(ll j=0;j<=n;j++){
			so1[j].clear();
			so2[j].clear();
		}
	}
	cout << "string having least number is the smallest : ";
	for(ll i=0;i<n;i++){
		cout << v[i] << " ";
	}
	cout << endl;
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
