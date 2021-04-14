#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod = 1e9+7,M = 1e5+1;
vector <ll> fact(M);

void calc_fact(){
	fact[0] = 1;
	for(ll i=1;i<M;i++) fact[i] = (i*fact[i-1])%mod;
}

ll modpow(ll x,ll n){
	if(n == 0) return 1%mod;
	ll u = modpow(x,n/2);
	u = (u*u)%mod;
	if(n&1) u=(u*x)%mod;
	return u;
}

ll inverse(ll x){
	return modpow(x,mod-2);
}

ll BC(ll n,ll k){
	return ((fact[n]*inverse(fact[n-k]))%mod*inverse(fact[k])%mod);
}

int main(){
	calc_fact();
	int n,k;
	cin >> n >> k;
	cout << BC(n,k) << endl;
	return 0;
}
