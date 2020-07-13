/*
Subarray Sum__

Consider the problem where we are given an array of n positive integers and a target sum x, and we want to find a subarray whose sum is x or report that there is no such subarray.

for example, the array 1,3,2,5,1,1,2,3

contains a subarray whose sum is 8 2,5,1.

this problem can be solved in O(n) time by using the two pointers method.
The idea is to maintain pointers that point to the first and the last value of the subarray.
On each turn, the left pointer moves one step to the right , and the right pointer moves to the right as long as th resulting subarray sum becomes exactly x, a solution has been found.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector <ll> v;
	ll n,k;
	cin >> n >> k;
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		v.push_back(l);
	}
	ll fl=0,s=0,end=0;
	for(ll i=0;i<n;i++){
		while(end+1<n && s+v[end+1]<=k){
			s+=v[end+1];
			if(s==k) fl=1;
			end++;
		}
		s-=v[i];
	}
	if(fl) cout << "found" << endl;
	else cout << "not found" << endl;
	return 0;
}
