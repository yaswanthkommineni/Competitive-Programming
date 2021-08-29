// start
class lazySegTreeForMin{
	public :
		class node{
			public :
				ll mn,lazySet,lazyIncrement;
				bool setAll;
				node(){
					mn = 1e18+1;
					setAll = false;
					lazyIncrement = 0;
				}
				void reset(){
					setAll = false;
					lazyIncrement = 0;
				}
		};
		ll n;
		vector <node> tree;
		lazySegTreeForMin(vector <ll> v){
			n = (ll)1<<(ll)ceil(log2((ll)v.size()));
			tree.assign(2*n,node());
			for(ll i=0;i<(ll)v.size();i++){
				tree[i+n].mn = v[i];
			}
			build(1);
		}
		void build(ll u){
			if(u<n){
				build(2*u);
				build(2*u+1);
				tree[u].mn = min(tree[2*u].mn,tree[2*u+1].mn);
			}
		}
		void pushToChild(ll par,ll child){
			if(tree[par].setAll){
				tree[child].setAll = true;
				tree[child].lazySet = tree[par].lazySet;
				tree[child].lazyIncrement = tree[par].lazyIncrement;
			}
			else{
				tree[child].lazyIncrement += tree[par].lazyIncrement;
			} 
		}
		void push(ll index,ll x,ll y){
			if(tree[index].setAll){
				tree[index].mn = tree[index].lazySet;
			}
			tree[index].mn += tree[index].lazyIncrement;
			if(x!=y){
				pushToChild(index,2*index);
				pushToChild(index,2*index+1);
			}
			tree[index].reset();
		}
		void rangeSet(ll l,ll r,ll val){
			lazySet(l,r,1,0,n-1,val);
		}
		void rangeUpdate(ll l,ll r,ll val){
			lazyUpdate(l,r,1,0,n-1,val);
		}
		ll rangeMin(ll l,ll r){
			return lazyMin(l,r,1,0,n-1);
		}
		void lazySet(ll a,ll b,ll index,ll x,ll y,ll val){
			if(x>b || y<a) return;
			if(x>=a && y<=b){
				tree[index].setAll = true;
				tree[index].lazySet = val;
				tree[index].lazyIncrement = 0;
				return;
			}
			push(index,x,y);
			ll mid = (x+y)/2;
			lazySet(a,b,2*index,x,mid,val);
			lazySet(a,b,2*index+1,mid+1,y,val);
			push(2*index,x,mid);
			push(2*index+1,mid+1,y);
			tree[index].mn = min(tree[2*index].mn,tree[2*index+1].mn);
		}
		void lazyUpdate(ll a,ll b,ll index,ll x,ll y,ll val){
			if(x>b || y<a) return;
			if(x>=a && y<=b){
				tree[index].lazyIncrement += val;
				return;
			}
			push(index,x,y);
			ll mid = (x+y)/2;
			lazyUpdate(a,b,2*index,x,mid,val);
			lazyUpdate(a,b,2*index+1,mid+1,y,val);
			push(2*index,x,mid);
			push(2*index+1,mid+1,y);
			tree[index].mn = min(tree[2*index].mn,tree[2*index+1].mn);
		}
		ll lazyMin(ll a,ll b,ll index,ll x,ll y){
			if(x>b || y<a){
				return 1e18+1;
			}
			push(index,x,y);
			if(x>=a && y<=b){
				return tree[index].mn;
			}
			ll mid = (x+y)/2;
			return min(lazyMin(a,b,2*index,x,mid),lazyMin(a,b,2*index+1,mid+1,y));
		}
};
// end

/* NOTE
Use .rangeUpdate(), .rangeMin(), .rangeSet()
*/
