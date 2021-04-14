/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

vector < vector <ll> > identity(ll n){
	vector < vector <ll> > v(n, vector <ll> (n,0));
	for(ll i=0;i<n;i++) v[i][i] = 1;
	return v;
}

vector < vector <ll> > mult(vector < vector <ll> > mat1, vector < vector <ll> > mat2){
	ll a = (ll)mat1.size();
	ll b = (ll)mat2.size();
	ll n = (ll)mat1[0].size();
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
	return v;
}

vector < vector <ll> > matpow(vector < vector <ll> > a,ll k){
	if(k == 0) return identity((ll)a.size());
	auto u = matpow(a,k/2);
	u = mult(u,u);
	if(k&1) u = mult(u,a);
	return u;
}

void solve(){
	ll n;
	cin >> n;
	vector < vector <ll> > v(n, vector <ll> (n));
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin >> v[i][j];
	ll k;
	cin >> k;
	auto res = matpow(v,k);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
		
}

int main(){
	freopen("input.txt","r",stdin);
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


