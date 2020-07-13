/*
 *Yaswanth Phani Kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*NOTE: please remeber while operating that these functions are 1 indexed*/

// FOR FINDING SUM QUERY 
// SEGMENT TREE FUNCTIONS END HERE
// Builds tree recursively //
void build(ll *tree,ll m,ll v){
	if(v<m){
		build(tree,m,2*v);
		build(tree,m,2*v+1);
		tree[v]=tree[2*v]+tree[2*v+1];
	}
}

// Finds sum from l to r(1 indexed) //
ll sum(ll *tree,ll m,ll l,ll r){
	ll s=0;
	l+=m-1;r+=m-1;
	while(l<=r){
		if(l&1) s+=tree[l++];
		if(!(r&1)) s+=tree[r--];
		l/=2;
		r/=2;
	}
	return s;
}

void update(ll *tree,ll m,ll v,ll s){
	v+=m-1;
	while(v>=1){
		tree[v]+=s;
		v/=2;
	}
}

// TREE FUNCTIONS STARTS HERE //

int main(){
	freopen("input.txt","r",stdin);
	ll n;
	cin >> n;
	// IMPORTANT STEP //
	ll m=(ll)pow(2,(ll)ceil(log2(n)));
	ll tree[2*m+1];
	memset(tree,0,sizeof(tree));
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		tree[i+m]=l;
	}
	build(tree,m,(ll)1);
	for(ll i=1;i<2*m+1;i++){
		cout << tree[i] << " ";
	}
	cout << "" << endl;
}
