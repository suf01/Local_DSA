#include<bits/stdc++.h>
using namespace std;

vector<int> selectionsort(vector<int> &a){
	int n = a.size();

	for(int i = 0; i < n-1; i++){
		int minimum  = i;
		
		for(int j = i+1; j < n; j++){
			if(a[j] < a[minimum]){
				minimum = j;
			}
		}

		if(minimum != i){
			int temp = a[i];
			a[i] = a[minimum];
			a[minimum] = temp;
		}

	}
	return a;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin>>v[i];
	}

	vector<int> ans = selectionsort(v);

	for(auto it : ans){
		cout<<it<<" ";
	}
}