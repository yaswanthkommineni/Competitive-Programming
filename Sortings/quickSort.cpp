#include <bits/stdc++.h>
using namespace std;

int partition(int l,int r,vector <int> &v){
	int pivot = v[l];
	int i = l-1,j = r+1;
	while(true){
		do{
			i++;
		}while(v[i]<pivot);
		do{
			j--;
		}while(v[j]>pivot);
		if(i>=j) return j;
		v[i]^=v[j];
		v[j]^=v[i];
		v[i]^=v[j];
	}
}

void quickSort(int l,int r,vector <int> &v){
	if(l<r){
		int k = partition(l,r,v);
		quickSort(l,k,v);
		quickSort(k+1,r,v);
	}
}

int main(){
	int n;
	cin >> n;
	vector <int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	quickSort(0,n-1,v);
	for(int i=0;i<n;i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}
