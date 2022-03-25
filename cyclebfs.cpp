#include<bits/stdc++.h>
using namespace std;

bool checkcylebfs(int node, vector<int> adjL[], vector<int> &visited){
	queue<pair<int, int> > q;
	
	visited[node] = 1;
	q.push({node, -1});

	while(!q.empty()){
		int temp = q.front().first;
		int prev = q.front().second;
		q.pop();

		for(auto ele : adjL[temp]){
			if(!visited[ele]){
				q.push({ele, temp});
				visited[ele] = 1;
			}
			else if(ele != prev){
				return true;
			}
		}

	}
	return false;
}

bool isCycleBFS(int V, vector<int> adjL[]){
	
	vector<int> visited(V+1, 0);

	for(int  i = 1; i <= V; i++){
		if(!visited[i]){
			if(checkcylebfs(i, adjL, visited)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<int> adjL[V+1];

	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);

	}

	for(int i = 1; i <= V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
	
	cout<<isCycleBFS(V, adjL);
}