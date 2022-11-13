#include<bits/stdc++.h>
using namespace std;
/*
  --> T.C O(v^2)
  --> works for both directed and undirected graphs.
  --> may or maynot work for negative weights(use bellman ford). 
*/

//gfg
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){

    vector<int> dis(V, INT_MAX);
    
    dis[S] = 0;
        
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int>> > q;
    q.push({dis[S], S});
        
    while(!q.empty()){
        int node = q.top().second;
        int prev_dis = q.top().first;
        q.pop();
            
        for(auto it: adj[node]){
            int ele = it[0];
            int wght = it[1];
                
            if(prev_dis + wght < dis[ele]){
                dis[ele] = prev_dis + wght;
                q.push({dis[ele], ele});
            }
        }
    }
    return dis;
}

void dijkstras(int V, int scr, vector<pair<int, int> > adjL[]){
	vector<int> dist(V+1, INT_MAX);

	/*for negetive heap priority queue use
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >
  	*/
	priority_queue<pair<int, int> > q;

	dist[scr] = 0;
	q.push({dist[scr], scr});

	while(!q.empty()){
		pair<int, int> node = q.top();
		q.pop();

		for(auto ele : adjL[node.second]){
			// dist[node.second] = node.first
			if(abs(dist[node.second]) != INT_MAX){
				
				if(abs(dist[node.second])+(ele.second) < dist[ele.first]){
					dist[ele.first] = abs(dist[node.second])+(ele.second);
					q.push({-dist[ele.first], ele.first});
				}
			}
		}
	}

	for(int i = 1; i <= V; i++){
		cout<<1<<"--"<<i<<" = "<<dist[i]<<endl;
	}
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<pair<int, int> > adjL[V+1];

	for(int i = 0; i < E; i++){
		int u, v, wt;
		cin>>u>>v>>wt;

		adjL[u].push_back({v, wt});
		adjL[v].push_back({u, wt});
	}

	for(int i = 1; i <= V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<"("<<ele.first<<","<<ele.second<<")";
		}
		cout<<endl;
	}

	dijkstras(V, 1, adjL);
}
