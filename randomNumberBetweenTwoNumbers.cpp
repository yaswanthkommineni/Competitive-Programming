#include <bits/stdc++.h>
using namespace std;

int main(){
	int l,r;
	cin >> l >> r;
	default_random_engine gen;
	uniform_int_distribution <int> dis(l,r);
	int rand = dis(gen); // includes l and r
	cout << rand << endl;
	return 0;
}
