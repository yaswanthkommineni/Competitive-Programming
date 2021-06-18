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

// input a string and then number of strings and strings that
// are needed to be searched

ll comp(string s,string g){
	s += "$";
	g += "$";
	ll i = 0;
	while(s[i] == g[i]){
		i++;
		if(i == (ll)s.size() && i == (ll)g.size()){
			return 0;
		}
	}
	if(s[i]<g[i]){
		return -1;
	}
	return 1;
}

void solve(){
	string s;
	cin >> s;
	s += "$";
	ll n = (ll)s.size();
	ll N = max(n,(ll)260);
	vector <ll> sa(n),ra(n);
	for(ll i=0;i<n;i++){
		sa[i] = i;
		ra[i] = s[i];
	}
	for(ll k=0;k<n;k?k*=2:k++){
		vector <ll> nsa(sa), nra(n),cnt(N);
		for(ll i=0;i<n;i++){
			nsa[i] = (nsa[i]-k+n)%n;
			cnt[ra[i]]++;
		}
		for(ll i=1;i<N;i++){
			cnt[i]+=cnt[i-1];
		}
		for(ll i=n-1;i+1;i--){
			sa[--cnt[ra[nsa[i]]]] = nsa[i];
		}
		for(ll i=1,r=0;i<n;i++){
			nra[sa[i]] = r += ra[sa[i]]!= ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		}
		ra = nra;
	}
	vector <ll> v(n-1);
	for(ll i=0;i<n-1;i++){
		v[ra[i]-1] = i;
	}
	ll p;
	cin >> p;
	while(p--){
		string g;
		cin >> g;
		ll l = 0,r = n-2;
		while(l<=r){
			string temp;
			ll mid = (l+r)/2;
			for(ll i=0;i<min((ll)g.size(),n-v[mid]-1);i++){
				temp.pb(s[v[mid]+i]);
			}
			if(comp(temp,g)>=0) r = mid-1;
			else l = mid+1;
		}
		string temp;
		r++;
		if(r>=n-1){
			cout << "No" << endl;
			continue;
		}
		for(ll i=0;i<min((ll)g.size(),n-v[r]-1);i++){
			temp.pb(s[v[r]+i]);
		}
		if(!comp(temp,g)){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
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
