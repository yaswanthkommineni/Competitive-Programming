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

// if you want to find a pattern p in string s, run z algorithm on p#s and 
//when the z value for some index in s is the length p then you have your pattern

void solve(){
	string s;
	cin >> s;
	ll n = (ll)s.size();
	vector <ll> z(n,0);
	ll l = 0,r = 0;
	for(ll i=1;i<n;i++){
		if(i>r){
			l = i;r = i-1;
			while(r+1<n && s[r+1] == s[r-l+1]) r++;
			z[i] = r-l+1;
		}
		else{
			if(z[i-l]+i-1 >= r){
				l = i;
				while(r+1<n && s[r+1] == s[r-l+1]) r++;
				z[i] = r-l+1;
			}
			else z[i] = z[i-l];
		}
	}
	for(ll i=0;i<n;i++){
		cout << z[i] << " ";
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
