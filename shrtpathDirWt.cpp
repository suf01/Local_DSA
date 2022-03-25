#include<bits/stdc++.h>
using namespace std;

void findtopo(int node, vector<int> &visited, vector<pair<int, int> > adjL[], stack<int> &st){
	visited[node] = 1;

	for(auto ele : adjL[node]){
		if(!visited[ele.first]){
			findtopo(ele.first, visited, adjL, st);
		}
	}
	st.push(node);
}

void shortpath(int V, int scr, vector<pair<int, int> > adjL[]){
	vector<int> visited(V, 0);

	stack<int> st;
	for(int i = 0; i < V; i++){
		if(!visited[i]){
			findtopo(i, visited, adjL, st);
		}
	}

	vector<int> dist(V, INT_MAX);
	dist[scr] = 0;

	while(!st.empty()){
		int node = st.top();
		st.pop();

		if(dist[node]!=INT_MAX){
		    for(auto ele : adjL[node]){
			    if(dist[node]+ele.second < dist[ele.first]){
			        dist[ele.first] = dist[node]+ele.second;
			    }
		    }
		}
	}

	for(int i = 0; i < V; i++){

		int distance = (dist[i] == INT_MAX) ? (-1) : dist[i];
		cout<<"0--"<<i<<" = "<<distance<<endl;
	}
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<pair<int, int> > adjL[V];

	for(int i = 0; i < E; i++){
		int u, v, wt;
		cin>>u>>v>>wt;

		adjL[u].push_back({v, wt});
	}

	for(int i = 0; i < V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<"("<<ele.first<<","<<ele.second<<")";
		}
		cout<<endl;
	}

	shortpath(V, 0, adjL);
}