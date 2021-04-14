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

int main(){
	precalc();
	for(int i=0;i<(int)primes.size();i++) cout << primes[i] << endl;
	return 0;
}
