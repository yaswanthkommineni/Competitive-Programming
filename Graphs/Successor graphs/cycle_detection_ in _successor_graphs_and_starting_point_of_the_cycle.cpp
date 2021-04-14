/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	ll n;
	cin >> n;
	vector < ll > succ(n+1);
	for(ll i=1;i<=n;i++) cin >> succ[i];
	ll a = succ[1];
	ll b = succ[succ[1]];
	while(a!=b){
		a = succ[a];
		b = succ[succ[b]];
	}
	a = 1;
	while(a!=b){
		a = succ[a];
		b = succ[b];
	}
	cout << a << endl;
	// this is the starting point of the cycle in the successor graphs
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
		solve();
	}
	return 0;
}

