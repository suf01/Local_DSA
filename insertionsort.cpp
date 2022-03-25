#include<bits/stdc++.h>
using namespace std;

vector<int> insertionsort(vector<int> &a){
	int n = a.size();

	for(int i = 1; i < n; i++){
		int temp = a[i];

		int j = i-1;
		while(j>=0 && a[j]>temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
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

	vector<int> ans = insertionsort(v);

	for(auto it : ans){
		cout<<it<<" ";
	}
}