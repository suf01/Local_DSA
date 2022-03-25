#include<bits/stdc++.h>
using namespace std;

int n, m;

void spiral_trav(vector<vector<int> > v, int top = 0, int down = n-1, int left = 0, int right = m-1){
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"*********"<<endl;

	int dir = 0;
	while(top <= down && left <= right){
		if(dir == 0){
			for(int i = left; i <= right; i++){
				cout<<v[top][i]<<" ";
			}
			top++;
		}else if(dir == 1){
			for(int i = top; i <= down; i++){
				cout<<v[i][right]<<" ";
			}
			right--;
		}else if(dir == 2){
			for(int i = right; i >= left; i--){
				cout<<v[down][i]<<" ";
			}
			down--;
		}else if(dir == 3){
			for(int i = down; i >= top; i--){
				cout<<v[i][left]<<" ";
			}
			left++;
		}

		dir = (dir+1)%4;
	}
}


int main(){
	
	cin>>n>>m;

	vector<vector<int> > v(n, vector<int> (m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
		}
	}

	spiral_trav(v);
}