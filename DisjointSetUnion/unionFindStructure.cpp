/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 100001;
vector <int> link(M),siz(M);

int find(int u){
	if(u == link[u]) return u;
	return link[u] = find(link[u]);
}

void join(int a,int b){
	a = find(a);
	b = find(b);
	if(siz[a]>siz[b]){
		a^=b;
		b^=a;
		a^=b;
	}
	link[a] = b;
	siz[b]+=siz[a];
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		link[i] = i;
		siz[i] = 1;
	}
	for(int i=0;i<m;i++){
		string s;
		cin >> s;
		int u,v;
		cin >> u >> v;
		if(s == "union") join(u,v);
		else{
			find(u) == find(v) ? cout << "YES" : cout << "NO" ;
			cout << endl;
		}
	}
}
 
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int z;
	z = 1;
	//cin >> z;
	for(int z1=1;z1<=z;z1++){
		solve();
	}
	return 0;
}
