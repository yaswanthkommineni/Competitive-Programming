#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	vector <ll> v{1,3,5,5,5,6,7,67,124,124,124};
	ll l = 0;
	ll r = (ll)v.size()-1;
	ll key = 124;
	ll ans = -1;
	while(l<=r){
		ll mid = (l+r)/2;
		if(key<v[mid]){
			r = mid-1;
		}
		else{
			ans = mid;
			l = mid+1;
		}
	}
	cout << ans << endl;
	return 0;
}

