#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll x1,y1;
	ll d = gcd(b,a%b,x1,y1);
	x = y1;
	y = x1-(a/b)*y1;
	return d;
}

int main(){
	ll a,b,x,y,c;
	cin >> a >> b >> c ;
	ll g = gcd(a,b,x,y);
	if(c%g) cout << "no root" << endl;
	else{
		x*=(c/g);
		y*=(c/g);
		cout << x << " " << y << endl;
	}
	return 0;
}
