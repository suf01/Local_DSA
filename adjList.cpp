#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	vector<int> adjL[n+1];

	for(int i = 0; i < n; i++){
		int u, v;
		cin>>u>>v;

		//for bidirected
		adjL[u].push_back(v);
		adjL[v].push_back(u);


	}

	//for weighted
	vector<pair<int, int> > adjL[n+1];

	for(int i = 0; i < n; i++){
		int u, v, wt;
		cin>>u>>v>>wt;

		adjL[u].push_back({v, wt});
		adjL[v].push_back({u, wt});
	}


}