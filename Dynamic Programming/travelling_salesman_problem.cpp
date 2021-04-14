/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n';

int n;
const int Max = 1e9+5,M = 16;
vector < vector <int> > cities(M,vector <int> (M)),dp(M,vector <int> ((1<<M),Max));;

int tsp(int pos,int j){
	if(j == (1<<n)-1) return (dp[pos][(1<<n)-1] = cities[pos][0]);
	if(dp[pos][j]!=Max) return dp[pos][j];
	int best = Max;
	for(int i=0;i<n;i++){
		if(!((1<<i)&j)){
			best = min(best,cities[pos][i] + tsp(i,j|(1<<i)));
		}
	}
	dp[pos][j] = best;
	return dp[pos][j];
}

void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> cities[i][j];
		}
	}
	cout << tsp(0,1) << endl;
}

int main(){
	freopen("input.txt","r",stdin);
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

