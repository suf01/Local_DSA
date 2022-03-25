#include<bits/stdc++.h>
using namespace std;
//t.c O(V+E) or O(V)
//s.c O(V+E) or O(V)
vector<int> graph_bfs(int V, vector<int> adj[]){
	vector<int> ans;
	vector<int> visited(V+1, 0);

	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			queue<int> q;
			q.push(i);
			visited[i] = 1;

			while(!q.empty()){
				int node = q.front();
				q.pop();
				ans.push_back(node);

				for(auto ele : adj[node]){
					if(!visited[ele]){
						q.push(ele);
						visited[ele] = 1;
					}
				}
			}
		}
	}

	return ans;
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
		for(auto ele : adjL[V]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

	vector<int> bfslist = graph_bfs(V, adjL);

	for(auto ele : bfslist){
		cout<<ele<<" ";
	}
}