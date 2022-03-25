#include<bits/stdc++.h>
using namespace std;

bool isDAGcycle(int node, vector<int> &visited, vector<int> &dfsvisited, vector<int> adjL[]){
	visited[node] = 1;
	dfsvisited[node] = 1;

	for(auto ele : adjL[node]){
		if(!visited[ele]){
			if(isDAGcycle(ele, visited, dfsvisited, adjL)){
				return true;
			}
		}else{
			if(dfsvisited[ele]){
				return true;
			}
		}
	}
	dfsvisited[node] = 0;
	return false;
}

bool cyclicDAGdfs(int V, vector<int> adjL[]){
	vector<int> visited(V+1, 0);
	vector<int> dfsvisited(V+1, 0);

	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			if(isDAGcycle(i, visited, dfsvisited, adjL)){
				return true;
			}
		}
	}
	return false;
}

bool cyclicDAGbfs(int V, vector<int> adjL[]){
	vector<int> indegree(V+1, 0);

	for(int i = 1; i <= V; i++){
		for(auto ele : adjL[i]){
			indegree[ele]++;
		}
	}

	queue<int> q;

	for(int i = 1; i <= V; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int count = 0;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		count++;

		for(auto ele : adjL[node]){
			indegree[ele]--;

			if(indegree[ele] == 0){
				q.push(ele);
			}
		}
	}

	if(count == V){
		return false;
	}else{
		return true;
	}
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<int> adjL[V+1];

	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
	}

	for(int i = 1; i <= V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

	if(cyclicDAGdfs(V, adjL)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

	if(cyclicDAGbfs(V, adjL)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}

}