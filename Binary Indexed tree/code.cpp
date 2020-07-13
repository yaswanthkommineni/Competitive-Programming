/*
 * Yaswanth Phani Kommineni
 */

/* 
 * USE ONE BASED INDEXING FOR BIT
 * For more refer the book(competitive programmers handbook) 
 * if you want to add elements:
 * 				first set all elements to zero and perform add(i) to add element
 * Note: if you want modify by x perform add(k,x)
 * if you want to change to x perform add(k,x-a[k]s);
 *
 */


// operations of binary indexed tree starts here//
ll sum(ll* tree,ll k){
	ll s=0;
	while(k>=1){
		s+=tree[k];
		k-=k&-k;
	}
	return s;
}

void add(ll* tree,ll n,ll k,ll s){
	while(k<=n){
		tree[k]+=s;
		k+=k&-k;
	}
}
// operations of binary indexed tree ends here//
