#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll M =1e5+1;
vector <ll> lpf(M),primes;

void precalc(){
	for(ll i=2;i<M;i++) lpf[i] = i;
	for(ll i=2;i<M;i++){
		if(lpf[i] == i){
			for(ll j=i*i;j<M;j+=i) if(lpf[j] == j) lpf[j] = i;
		}
	}
	for(ll i=2;i<M;i++) if(lpf[i] == i) primes.push_back(i);
}

ll euler(ll n){
	vector <pair<ll,ll>> fact;
	for(ll x : primes){
		ll k = 0;
		while(n%x == 0){
			k++;
			n/=x;
		}
		if(k) fact.push_back(make_pair(x,k));
	}
	if(n>1) fact.push_back(make_pair(n,1));
	ll res = 1;
	for(auto x : fact) res*=(ll)pow(x.first,x.second-1)*(x.first-1);
	return res;
}

int main(){
	precalc();
	ll n;
	cin >> n;
	cout << euler(n) << endl;
	return 0;
}
