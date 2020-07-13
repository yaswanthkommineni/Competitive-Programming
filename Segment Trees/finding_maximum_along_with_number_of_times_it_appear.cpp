/*
 *Yaswanth Phani Kommineni
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MINN = -1e6;

void build(pair<ll,ll> *tree,ll m,ll v){
	if(v<m){
		build(tree,m,2*v);
		build(tree,m,2*v+1);
		if(tree[2*v].first>tree[2*v+1].first) tree[v]=tree[2*v];
		else if(tree[2*v].first<tree[2*v+1].first) tree[v]=tree[2*v+1];
		else{
			tree[v].first=tree[2*v].first;
			tree[v].second=tree[2*v].second+tree[2*v+1].second;
		}
	}
}

pair<ll,ll> GET_MAX(pair<ll,ll> *tree,ll v,ll cl,ll cr,ll l,ll r){
	if(cr<l || cl>r) return {MINN,0};
	else if(cl==l && cr==r) return tree[v] ;
	ll mid=(cr+cl-1)/2;
	pair<ll,ll> t1;
	pair<ll,ll> t2;
	t1 = GET_MAX(tree,2*v,cl,mid,l,min(r,mid));
	t2 = GET_MAX(tree,2*v+1,mid+1,cr,max(mid+1,l),r);
	if(t1.first>t2.first) return t1;
	else if(t1.first<t2.first) return t2;
	else return {t1.first,t1.second+t2.second};
}

void update(pair<ll,ll> *tree,ll m,ll v,ll s){
	v+=m-1;
	tree[v].first+=s;
	v/=2;
	while(v>=1){
		if(tree[2*v].first>tree[2*v+1].first) tree[v]=tree[2*v];
		else if(tree[2*v].first<tree[2*v+1].first) tree[v]=tree[2*v+1];
		else{
			tree[v].first=tree[2*v].first;
			tree[v].second=tree[2*v].second+tree[2*v+1].second;
		}
		v/=2;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	ll n;
	cin >> n;
	ll m;
	m=(ll)pow(2,ceil(log2(n)));
	pair<ll,ll> tree[2*m+1];
	for(ll i=0;i<2*m+1;i++){
		tree[i]={MINN,0};
	}
	for(ll i=0;i<n;i++){
		ll l;
		cin >> l;
		tree[m+i]={l,1};
	}
	build(tree,m,1);
	update(tree,m,4,6);
	update(tree,m,10,4);
	auto ans = GET_MAX(tree,1,1,m,4,10);
	cout << ans.first << " " << ans.second << endl;
	return 0;	
}
