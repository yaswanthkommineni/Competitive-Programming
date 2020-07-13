/*
 * yaswanth phani kommineni
 */
// any queries refer dynamic programming in bitmanipulation section in Competitive programmers hand book
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 1e5;

void solve(){
	int n,m;
	cin >> n >> m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	int dp[1<<n][m];
	for(int i=0;i<(1<<n);i++){
		dp[i][0]=MAXN;
	}
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		dp[1<<i][0]=a[i][0];
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<(1<<n);j++){
			dp[j][i]=dp[j][i-1];
			for(int k=0;k<n;k++){
				if(j&(1<<k)) dp[j][i]=min(dp[j][i],dp[j^(1<<k)][i-1]+a[k][i]);
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<m;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	//cin >> t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
