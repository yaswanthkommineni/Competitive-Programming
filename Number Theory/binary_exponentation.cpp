#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod = 1e9+7;

ll modpow(ll x,ll n){
	if(n == 0) return 1%mod;
	ll u = modpow(x,n/2);
	u = (u*u)%mod;
	if(n&1) u = (u*x)%mod;
	return u;
}

int main(){
	ll n;
	cin >> n;
	cout << modpow(n,3) << endl;
	return 0;
}
