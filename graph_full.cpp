#include<bits/stdc++.h>
using namespace std;

/*
edges connected by vertices or vertices connected by edges are called graphs

path is a sequence of nodes or vertices where non of the nodes repeates itself or appears more than once

for undirected graph totaldegree = 2*edges, totaldegree = sum of individual degrees of nodes or vertices

tree is a undirected acyclic graph

*/

int main(){
	//adjacent matrix
	//if n nodes create n+1 by n+1 matrix;
	//O(n^2)
	int n;
	cin>>n;

	vector<int> adjM[n+1][n+1];
	for(int i = 0; i < n; i++){
		cin>>u>>v;
		adjM[u][v] = 1;
		adjM[v][u] = 1;
	}

	//adjacency list
	//O(V+2E)

	//undirected
	int V, E;
	cin>>V>>E;

	//vector<vector<int> > adjL(v+1, vector<int>)
	vector<int> adjL[V+1]
	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	//directed
	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
	}


	//weighted graphs
	//vector<vector<pair<int, int> > adjL(V+1, vector<pair<int,int>>) 

	vector<pair<int, int> > adjL[v+1];
	for(int i = 0; i < E; i++){
		int u, v, wt;
		cin>>u>>v>>wt;

		adjL[u].push_back({v, wt});
		adjL[v].push_back({u, wt});
	}
}
