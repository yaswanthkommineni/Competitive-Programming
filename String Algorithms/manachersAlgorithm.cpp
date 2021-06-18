#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// _______O(N) solution______ 

int main(){
	freopen("input.txt","r",stdin);
	string s;
	cin >> s;
	/*
	 * creating a duplicate of the original string to run the process
	 * (Filling the gaps with #)
	 *  adding different characters at back and front so we not get overflows
	 */ 
	string g="";
	g.push_back('$');
	for(ll i=0;i<(ll)s.size();i++){
		g.push_back('#');
		g.push_back(s[i]);
	}
	g.push_back('#');
	g.push_back('@');
	cout << g << endl;
	ll p[(ll)g.size()]={0}; 		// to store the length of the current palindromic position
	ll c=1,r=1;	// c = position of the current center r = right bound 
	for(ll i=1;i<(ll)g.size()-1;i++){		// iterating over the all possible positions
		ll i_mirror = c-(i-c);		// mirror image of i corresponding to current center
		if(r>i){
			// *******___KEY STEP___*******
			p[i] = min(r-i,p[i_mirror]);
			// why do we need to caliculate if it is all ready caliculated by its mirror image and all we need to do is expand 
		}
		else{
			p[i]=0;
		}
		while(g[i+1+p[i]]==g[i-1-p[i]]) p[i]++; 	// Expanding
		if(i+p[i]>r){			// Expanding booundary if needed
			c=i;
			r=c+p[i];
		}
	}
	ll maxlen=0,centerindex=0;
	for(ll i=0;i<(ll)g.size();i++){
		if(p[i]>maxlen){
			maxlen = p[i];
			centerindex=i;
		}
	}
	string ans="";
	for(ll i=centerindex-maxlen;i<=centerindex+maxlen;i++){
		if(g[i]>=97) ans.push_back(g[i]);
	}
	cout << ans << endl;
	return 0;
}
