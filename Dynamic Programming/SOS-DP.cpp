/*
Yaswanth Phani Kommineni
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
        int n,m = 23;
        cin >> n;
        vector <int> v(n);
        vector < vector <int> > dp((1<<m), vector <int> (m+1));
        for(int i=0;i<n;i++){
                cin >> v[i];
                dp[v[i]][0] = 1;
        }
        for(int i=1;i<=m;i++){
                for(int j=0;j<(1<<m);j++){
                        dp[j][i] += dp[j&((1<<m)-1-(1<<(i-1)))][i-1];
                        if(j&(1<<(i-1))){
                                dp[j][i] += dp[j][i-1];
                        }
                }
        }
        for(int i=0;i<n;i++){
                cout << dp[v[i]][m] << " ";
        }
        cout << endl;
}

int main(){
#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif
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
