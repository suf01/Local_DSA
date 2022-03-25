#include<bits/stdc++.h>
using namespace std;

void shortdistbfs(int V, vector<int> adjL[], int scr){
	vector<int> dist(V, INT_MAX);

	queue<int> q;
	dist[scr] = 0;
	q.push(scr);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto ele : adjL[node]){
			if(dist[node]+1 < dist[ele]){
				dist[ele] = dist[node]+1;
				q.push(ele);
			}
		}
	}

	for(int i = 0; i < dist.size(); i++){
		cout<<"0--"<<i<<" = "<<dist[i]<<endl;
	}

}

int main(){
	int V, E;
	cin>>V>>E;
	vector<int> adjL[V];

	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	for(int i = 0; i < V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

	shortdistbfs(V, adjL, 0);
}