/*
 * yaswanth phani kommineni
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // added
#include <ext/pb_ds/tree_policy.hpp>	// added
#include <functional> 			// added
using namespace __gnu_pbds;		// added
using namespace std;
typedef long long int ll;
#define endl '\n';

/* this data structure is to find number of elements that are less than or equal to x in O(log(n))
and it is also used to find the element at position k in O(log(n))
*/

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
	ordered_set p;
	p.insert(1);
	p.insert(10);
	p.insert(11);
	p.insert(9);
	p.insert(7);
	p.insert(8);
	cout << *(p.find_by_order(3)) << endl; // gives the value at given index
	cout << p.order_of_key(9) << endl; // gives the index of given value
	cout << p.order_of_key(2) << endl; // if the given element is not there, then it will return the index if it's there
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	tc = 1;
	//cin >> tc;
	for(int i=1;i<=tc;i++){
		solve();
	}
	return 0;
}

