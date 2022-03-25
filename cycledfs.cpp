#include<bits/stdc++.h>
using namespace std;

bool checkcylcedfs(int node, int parent, vector<int> &visited, vector<int> adjL[]){
	visited[node] = 1;

	for(auto ele : adjL[node]){
		if(!visited[ele]){
			if(checkcylcedfs(ele, node, visited, adjL)) return true;
		}else{
			if(ele != parent) return true;
		}
	}
	return false;
}

bool isCycleDFS(int V, vector<int> adjL[]){
	vector<int> visited(V+1, 0);

	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			if(checkcylcedfs(i, -1, visited, adjL)){
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
	
	cout<<isCycleDFS(V, adjL);
}