#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN = 1e6;

/* NOTE: All are 1 base indexed in these functions so please remember this */
// SEGMENT TREE FUNCTIONS STARTS HERE//
void build(ll *tree,ll m,ll v){
	if(v<m){
		build(tree,m,2*v);
		build(tree,m,2*v+1);
		tree[v] = min(tree[2*v],tree[2*v+1]);
	}
}

ll Min(ll *tree,ll v,ll cl,ll cr,ll l,ll r){
	if(cl>r || cr<l) return MAXN;
	else if(cl==l && cr==r) return tree[v];
	ll mid = (cl+cr-1)/2;
	return min(Min(tree,2*v,cl,mid,l,min(r,mid)),Min(tree,2*v+1,mid+1,cr,max(mid+1,l),r));
}

void update(ll *tree,ll m,ll v,ll k){
	v+=m-1;
	tree[v]+=k;
	v/=2;
	while(v>=1){
		tree[v]=min(tree[2*v],tree[2*v+1]);
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
	memset(tree,MAXN,sizeof(tree));
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		tree[m+i]=l;
	}
	build(tree,m,1);
	cout << Min(tree,1,1,m,3,10) << endl;
	update(tree,m,10,8);
	cout << Min(tree,1,1,m,3,10) << endl;
	cout << tree[1] << endl;
}
