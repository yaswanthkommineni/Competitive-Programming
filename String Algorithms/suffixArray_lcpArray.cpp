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
Don't forget
1. If you are looking at editorial, remember that you are accepting defeat.
2. [If stuck] Don't stick to one approach and attack with different approaches.
Write everything down, analyze the G-spot and attack throught it.
3. Don't look at standings during the contest.
4. Don't try to code fast and code concetrately instead or bugs will eat you in the sleep.
5. When you are writing return, make sure that there are no input operations after that
*/

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

// requires suffix array to construct longest common prefix array
vector <ll> lcpArray(string s,vector <ll> sa){ //O(n)
	ll n = (ll)s.size();
	vector <ll> rank(n),lcp(n,0);
	for(ll i=0;i<n;i++){
		rank[sa[i]] = i;
	}
	ll k = 0;
	for(ll i=0;i<n;i++,k=((!k)?0:(k-1))){
		if(rank[i] == n-1){
			k = 0;
			continue;
		}
		ll j = sa[rank[i]+1];
		while(max(i+k,j+k)<n && s[i+k] == s[j+k]){
			k++;
		}
		lcp[rank[i]] = k;
	}
	return lcp;
}

void solve(){
	string s;
	cin >> s;
	vector <ll> sa = suffixArray(s);
	vector <ll> lcp = lcpArray(s,sa);
	for(auto x : lcp){
		cout << x << " ";
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

