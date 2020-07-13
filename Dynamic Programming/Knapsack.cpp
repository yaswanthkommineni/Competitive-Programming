/*
 * Yaswanth Phani Kommineni
 */

/*
___Knapsack Problems___

knapsack refers to problems where a set of objects is given, and subsets with properties have to be found.
for example:Given a list of weights,determine all sums that can be constructed using the weights.
note:- (each weight can be used only once)

code for the following problem
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll poss[100005];

int main(){
	ll n,k,w=0;
	vector <ll > v;
	cin >> n >> k;
	for(ll i=0;i<k;i++){
		ll l;
		cin >> l;
		v.push_back(l);
		w+=l;
	}
	poss[0]=1;
	for(ll i=0;i<k;i++){
		for(ll j=w;j<=0;j--){
			if(poss[j]) poss[j+v[i]]=1;
		}
	}		
	return 0;
}
