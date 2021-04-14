class minSegmentTree{
	// author : yaswanth phani kommineni
	public :
		vector <ll> st;
		ll n;
		minSegmentTree(vector <ll> v){
			n = ((ll)1<<((ll)ceil(log2(v.size()))));
			st.assign(2*n,1e18+1);
			for(ll i=0;i<(ll)v.size();i++){
				st[n+i] = v[i];
			}
			build(1);
		}
		// not for use ( instantiated automatically)
		void build(ll u){
			if(u<n){
				build(2*u);
				build(2*u+1);
				st[u] = min(st[2*u],st[2*u+1]);
			}
		}
		// changes value at l(0 indexed) to val
		void update(ll l, ll val){
			l+=n;
			st[l] = val;
			l>>=1;
			while(l){
				st[l] = min(st[2*l],st[2*l+1]);
				l>>=1;
			}
		}
		// 0 indexed
		ll query(ll l,ll r){
			l+=n;
			r+=n;
			ll res = 1e18+1;
			while(l<=r){
				if(l&1) res = min(res,st[l++]);
				if(!(r&1)) res = min(res,st[r--]);
				l>>=1;
				r>>=1;
			}
			return res; 
		}
};
