#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	int n;
	cin >> n;
	vector <ll> v(n+1);
	for(ll i=0;i<n;i++){
		cin >> v[i+1];
	}
	ll maximumPower = ceil(log2(n));
	// 2^(maximumPower)-1 is the maximum number of steps one can go ahead
	vector < vector <ll> > succ(n+1,vector <ll> (maximumPower+1,0));
	for(ll i=1;i<=n;i++){
		succ[i][0] = v[i];
	}
	for(ll j=1;j<=maximumPower;j++){
		for(ll i=1;i<=n;i++){
			succ[i][j] = succ[succ[i][j-1]][j-1];
		}
	}
	ll start,steps;
	cin >> start >> steps;
	// stepsth step from start = res
	ll res = start;
	for(ll i=0;i<=32;i++){
		if(((ll)1<<i)&steps){
			res = succ[res][i];
		}
	}
	cout << res << endl;
	return 0;
}
