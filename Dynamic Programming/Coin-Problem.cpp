/*
 * Yaswanth Phani Kommineni
 */
 
/*
COINS PROLEM(pg-68)

Given a set of coin values coins = { c 1 , c 2 , . . . , c k } and a target sum of money n , our task is to form the sum n using as few coins as possible.
*/

#include <bits/stdc++.h>
using namespace std;
typedef      long long int 	ll;

#define INF pow(10,6);
vector <ll > v;
int vis[100001],val[100001];

int main(){
	ll c,n;
	cin >> c;				// c=required sum
	cin >> n;				// number of coins n
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		v.push_back(l);
	}
	for(ll i=1;i<=c;i++){
		val[i]=(int)INF;		// calculating minimum for each sum <=c
		for(auto x: v){
			if(i-x>=0) val[i]=min(val[i-x]+1,val[i]);
		}
	}
	cout << val[c] << endl;
	return 0;
}

// if you want what are that coins visit page no.69 in the book(Competitive Programmers Handbook) 
