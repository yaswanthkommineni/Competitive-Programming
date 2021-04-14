/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

void solve(){
	ll a,n,b;
	cin >> a >> n >> b;
	// two matrices of dimensions aXn and nXb
	vector < vector <ll> > mat1(a, vector <ll> (n));
	vector < vector <ll> > mat2(n, vector <ll> (b));
	for(ll i=0;i<a;i++)
		for(ll j=0;j<n;j++)
			cin >> mat1[i][j];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<b;j++)
			cin >> mat2[i][j];
	vector < vector <ll> > v(a, vector <ll> (b,0));
	for(ll i=0;i<a;i++)
		for(ll j=0;j<b;j++)
			for(ll k=0;k<n;k++)
				v[i][j]+=mat1[i][k]*mat2[k][j];
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

