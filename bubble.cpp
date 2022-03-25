#include<bits/stdc++.h>
using namespace std;

vector<int> bubblesort(vector<int> &a){
	int n = a.size();
	bool swapped;

	for(int i = 0; i < n-1; i++){
		swapped = false;
		for(int j = 0; j < n-i-1; j++){
			
			if(a[j+1] < a[j]){
				int temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				swapped = true;
			}
		}
		if(swapped == false) break;
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

	vector<int> ans = bubblesort(v);

	for(auto it : ans){
		cout<<it<<" ";
	}
}