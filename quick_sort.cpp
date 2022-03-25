#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int lo, int hi){
	int pivot = v[lo];
	int i = lo;
	int j = hi;

	while(i < j){
		while(v[i] <= pivot && i <= hi){
			i++;
		}
		while(v[j] > pivot && j >= lo){
			j--;
		}

		if(i < j){
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}

	int temp = v[j];
	v[j] = v[lo];
	v[lo] = temp;

	return j;
}

void quick_sort(vector<int> &v, int lo, int hi){
	if(lo < hi){
		int pivot = partition(v, lo, hi);
		quick_sort(v, lo, pivot-1);
		quick_sort(v, pivot+1, hi);
	}
}

int main(){
	int n;
	cin>>n;

	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin>>v[i];
	}

	quick_sort(v, 0, n-1);

	for(auto it: v){
		cout<<it<<" ";
	}
}