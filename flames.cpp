/*
Yaswanth Phani Kommineni
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
        string s,g;
        cin >> s >> g;
        vector <int> count(26,0);
        for(auto x : s){
                count[x-'a']++;
        }
        for(auto x : g){
                count[x-'a']--;
        }
        int val = 0;
        for(int i=0;i<26;i++){
                val += abs(count[i]);
        }
        string flames = "flames";
        vector <int> vis(6,0);
        int cancelled = 0,i = 5;
        while(cancelled < 5){
                for(int j=0;j<val;j++){
                        while(vis[(i+1)%6]){
                                i++;
                                i%=6;
                        }
                        i++;
                        i%=6;
                }
                vis[i] = 1;
                cancelled++;
        } 
        for(int i=0;i<6;i++){
                if(!vis[i]){
                        cout << flames[i] << endl;
                }
        }
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
