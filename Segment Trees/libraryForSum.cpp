class sumSegmentTree{
	// author : yaswanth phani kommineni
	public :
		vector <ll> st;
		ll n;
		sumSegmentTree(vector <ll> v){
			n = ((ll)1<<((ll)ceil(log2(v.size()))));
			st.assign(2*n,0);
			for(ll i=0;i<(ll)v.size();i++){
				st[n+i] = v[i];
			}
			build(1);
		}
		// no need to instantiate (instantiated automatically)
		void build(ll u){
			if(u<n){
				build(2*u);
				build(2*u+1);
				st[u] = st[2*u]+st[2*u+1];
			}
		}
		// 0 indexed
		ll query(ll l,ll r){
			l+=n;
			r+=n;
			ll res = 0;
			while(l<=r){
				if(l&1) res += st[l++];
				if(!(r&1)) res += st[r--];
				l>>=1;
				r>>=1;
			}
			return res;
		}
		// changes value at l(0 indexed) to val
		void update(ll l,ll val){
			l+=n;
			ll k = val-st[l];
			while(l){
				st[l]+=k;
				l>>=1;
			}
		}
};
