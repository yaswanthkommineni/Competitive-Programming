#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &v,int l,int r){
	int mid = (l+r)/2;
	int i = l,j = mid+1;
	vector <int> m;
	while(i<=mid && j<=r){
		if(v[i]<v[j]) m.push_back(v[i++]);
		else m.push_back(v[j++]);
	}
	while(i<=mid) m.push_back(v[i++]);
	while(j<=r) m.push_back(v[j++]);
	for(i=l;i<=r;i++) v[i] = m[i-l];
}

void mergeSort(vector <int> &v,int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(v,l,mid);
		mergeSort(v,mid+1,r);
		merge(v,l,r);
	}
}

int main(){
	int n;
	cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	mergeSort(v,0,n-1);
	for(auto x : v ) cout << x << " ";
	cout << endl;
	return 0;
}
