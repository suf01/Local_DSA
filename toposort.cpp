#include<bits/stdc++.h>
using namespace std;

void findtopodfs(int node, vector<int> adjL[], vector<int> &visited, stack<int> &st){
	visited[node] = 1;

	for(auto ele : adjL[node]){
		if(!visited[ele]){
			findtopodfs(ele, adjL, visited, st);
		}
	}
	st.push(node);
}

void toposortdfs(int V, vector<int> adjL[]){
	vector<int> visited(V, 0);
	stack<int> st;

	for(int i = 0; i < V; i++){
		if(!visited[i]){
			findtopodfs(i, adjL, visited, st);
		}
	}

	vector<int> ans;
	
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}

	for(auto it : ans){
		cout<<it<<" ";
	}	
}

vector<int> kahnstopobfs(int V, vector<int> adjL[]){
	vector<int> indegree(V, 0);

	for(int i = 0; i < V; i++){
		for(auto ele : adjL[i]){
			indegree[ele]++;
		}
	}

	queue<int> q;

	for(int i = 0; i < V; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	vector<int> ans;

	//int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		ans.push_back(node);
		q.pop();

		for(auto ele : adjL[node]){
			indegree[ele]--;

			if(indegree[ele] == 0){
				q.push(ele);
			}
		}
	}
	/*
	if(cnt == V){
		return true;
	}else{
		return false;
	}
	*/

	return cnt;
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<int> adjL[V];

	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
	}

	for(int i = 0; i < V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

	toposortdfs(V, adjL);
	cout<<endl;

	vector<int> ktopo = kahnstopobfs(V, adjL);

	for(auto ele : ktopo){
		cout<<ele<<" ";
	}
	cout<<endl;
}