/*
 *Yaswanth Phani Kommineni
 */
/*
Edit Distance:

The edit distance needed to transform a string into another string. The allowed operations are as follows:

insert a character 
remove a character 
modify a character

for example, the edited distance between LOVE and movie is 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define INF 100005;
string s,g;

ll cost(ll a,ll b){
	if(s[a]==g[b]) return 0;
	else return 1;
}

ll dist(ll a,ll b){
	if(a==-1 && b==-1) return 0;
	else if(a<-1 || b<-1) return INF;	
	ll ans=min(dist(a-1,b-1)+cost(a,b),dist(a-1,b)+1);
	ans=min(dist(a,b-1)+1,ans);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> g;
	cout << dist((ll)(s.size()-1),(ll)(g.size()-1)) << endl;;
	return 0;
}
