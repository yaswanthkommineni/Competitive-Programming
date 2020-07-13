#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MINN = -1e6;

/* NOTE: All are 1 base indexed in these functions so please remember this */
// SEGMENT TREE FUNCTIONS STARTS HERE//
void build(ll *tree,ll m,ll v){
	if(v<m){
		build(tree,m,2*v);
		build(tree,m,2*v+1);
		tree[v]=max(tree[2*v],tree[2*v+1]);
	}	
}

ll Max(ll *tree,ll m,ll l,ll r){
	ll res=MINN;
	l+=m-1;
	r+=m-1;
	while(l<=r){
		if(l&1) res=max(res,tree[l++]);
		if(!(r&1)) res=max(res,tree[r--]);
		l/=2;
		r/=2;
	}
	return res;	
}

void update(ll *tree,ll m,ll v,ll k){
	v+=m-1;
	tree[v]+=k;
	v/=2;
	while(v>=1){
		tree[v] = max(tree[2*v],tree[2*v+1]);
		v/=2;
	}
}
// SEGMENT TREE FUNCTIONS ENDS HERE//

int main(){
	freopen("input.txt","r",stdin);
	ll n;
	cin >> n;
	ll m=(ll)pow(2,ceil(log2(n)));
	ll tree[2*m+1];
	memset(tree,MINN,sizeof(tree));
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		tree[m+i]=l;
	}
	cout << m << endl;
	build(tree,m,1);
	cout << Max(tree,m,3,9) << endl;
	//update(tree,m,4,10);
	return 0;
}
