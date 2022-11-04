#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	
	int lim = sqrt(N);
	//O(sqrt(N))
	for(int i = 1; i <= lim; i++){
		if(N%i == 0){
			cout<<i<<" ";
			if(N/i != i){
				cout<<N/i<<" ";
			}
		}
	}
  
	cout<<endl<<endl;
	
  //to count factors of each number from 1 to N
	vector<int> fact_cnt(N+1, 0);
	//O(NlogN)
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j = j+i){
			fact_cnt[j]++;
		}
	}
	
  for(int i = 1; i <= N; i++){
		cout<<fact_cnt[i]<<" ";
	}
}
