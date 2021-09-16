class specialSegmentTree{
	// author : yaswanth phani kommineni
	public :
		class node{
			public:
				ll prefix,len,suffix,val,first,last;
				node(){
					prefix = 0;
					len = 0;
					suffix = 0;
					val = 0;
					first = 0;
					last = 0;
				}
		};
		vector <node> st;
		ll n;
		specialSegmentTree(vector <ll> v){
			n = ((ll)1<<((ll)ceil(log2(v.size()))));
			st.assign(2*n,node());
			for(ll i=0;i<(ll)v.size();i++){
				st[n+i].val = st[n+i].prefix = st[n+i].suffix = st[n+i].len = 1;
				st[n+i].first = v[i];
				st[n+i].last = v[i];
			}
			build(1);
		}
		node combine(node a,node b){
			if(a.len == 0) return b;
			if(b.len == 0) return a;
			node res;
			res.first = a.first;
			res.last = b.last;
			res.val = a.val+b.val;
			if(a.last <= b.first){
				res.val -= a.suffix*(a.suffix+1)/2;
				res.val -= b.prefix*(b.prefix+1)/2;
				res.val += (a.suffix+b.prefix)*(a.suffix+b.prefix+1)/2;
			}
			if(a.prefix == a.len && a.last <= b.first){
				res.prefix = a.prefix + b.prefix;
			}
			else{
				res.prefix = a.prefix;
			}
			if(b.suffix == b.len && a.last <= b.first){
				res.suffix = a.suffix + b.suffix;
			}
			else{
				res.suffix = b.suffix;
			}
			res.len = a.len+b.len;
			return res;
		}
		// no need to instantiate (instantiated automatically)
		void build(ll u){
			if(u<n){
				build(2*u);
				build(2*u+1);
				st[u] = combine(st[2*u],st[2*u+1]);
			}
		}
		// 0 indexed
		ll query(ll l,ll r){
			l+=n;
			r+=n;
			node pre,suf;
			while(l<=r){
				if(l&1){
					pre = combine(pre,st[l]);
					l++;
				}
				if(!(r&1)){ 
					suf = combine(st[r],suf);
					r--;
				}
				l>>=1;
				r>>=1;
			}
			node res = combine(pre,suf);
			return res.val;
		}
		// changes value at l(0 indexed) to val
		void update(ll l,ll val){
			l+=n;
			st[l].first = val;
			st[l].last = val;
			l/=2;
			while(l){
				st[l] = combine(st[2*l],st[2*l+1]);
				l/=2;
			}
		}
};
