/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){ 
	string s;
	cin >> s;
	s += '$';
	int n = (int)s.size();
	vector < pair<char,int>> p(n);			
	for(int i=0;i<n;i++) p[i] = {s[i],i};
	sort(p.begin(),p.end());
	vector <int> a(n),c(n);
	for(int i=0;i<n;i++) a[i] = p[i].second;
	c[a[0]] = 0;	
	for(int i=1;i<n;i++){
		if(p[i].first == p[i-1].first) c[a[i]] = c[a[i-1]];
		else c[a[i]] = c[a[i-1]]+1;
	}
	int k = 0;
	while((1<<k)<n){
		vector <pair<pair<int,int>,int>> v(n);
		for(int i=0;i<n;i++) v[i] = {{c[i],c[(i+(1<<k))%n]},i};	
		// making use of classes obtained from previous transition 
		sort(v.begin(),v.end());
		for(int i=0;i<n;i++) a[i] = v[i].second ;
		c[a[0]] = 0;
		for(int i=1;i<n;i++){
			if(v[i].first == v[i-1].first) c[a[i]] = c[a[i-1]];
			else c[a[i]] = c[a[i-1]]+1;
		}
		k++;
	}
	for(int i=0;i<n;i++) cout << a[i] << " " ;
	cout << endl;
}

int main(){
	//freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll z;
	//cin >> z;
	z=1;
	while(z--){
		solve();
	}
	return 0;
}
