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

// returns sorted order of suffixes
vector <ll> suffixArray(string s){ //O(nlogn)
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
	n--;
	for(ll i=0;i<n;i++){
		ra[i]--;
		sa[ra[i]] = i;
	}
	sa.pop_back();
	return sa;
}

void solve(){
	string s;
	cin >> s;
	vector <ll> sa = suffixArray(s);
	for(auto x : sa){
		cout << x << " ";
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
