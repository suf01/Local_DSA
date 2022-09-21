#include<bits/stdc++.h>
using namespace std;

/*
  spannig tree -> if a graph can be converted into a tree with N nodes and N-1 edges.
  minimum sp -> spanning tree having minimum edge weights(sum of edge weights is minimum).
  * prims algo
  * kruskals algo
*/

#include<bits/stdc++.h>
using namespace std;

//brute force
int spanningTree(int V, vector<vector<int>> adj[]){
   
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
        
    vector<bool> mst(V, false);
	
    //use parent only if u want to get the actual graph    
    vector<int> parent(V, -1);
        
    for(int edges = 0; edges < V-1; edges++){
        int least_dist = INT_MAX;
            
        int node;
        for(int i = 0; i < V; i++){
            if(mst[i] == false && dist[i] < least_dist){
                least_dist = dist[i];
                node = i;
            }
        }
            
        mst[node] = true;
            
        for(auto it: adj[node]){
            int ele = it[0];
            int wgt = it[1];
                
            if(mst[ele] == false && wgt < dist[ele]){
                dist[ele] = wgt;
                parent[ele] = node;
            }
        }
    }
        
    int cost = 0;
    for(int i = 0; i < V; i++){
        cost += dist[i];
    }
    
    return cost;
}

//optimization
int spanningTree(int V, vector<vector<int>> adj[]){
    
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
        
    vector<bool> mst(V, false);
        
    vector<int> parent(V, -1);
        
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        
    //{dist, node} 
    q.push({0, 0});
    
    //must use q.empty() only dont run for loops for V-1 times
    while(!q.empty()){
            
        int node  = q.top().second;
        q.pop();
            
        mst[node] = true;
            
        for(auto it: adj[node]){
            int ele = it[0];
            int wgt = it[1];
                
            if(mst[ele] == false && wgt < dist[ele]){
                parent[ele] = node;
                dist[ele] = wgt;
                q.push({dist[ele], ele});
            }
        }
    }
        
    int cost = 0;
    for(int i = 0; i < V; i++){
        cost += dist[i];
    }
    return cost;
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<pair<int, int> > adjL[V];

	for(int i = 0; i < E; i++){
		int a, b, wt;
		cin>>a>>b>>wt;
		adjL[a].push_back({b, wt});
		adjL[b].push_back({a, wt});
	}

	for(int i = 0; i < V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<"("<<ele.first<<", "<<ele.second<<")";
		}
		cout<<endl;
	}

	primsop(V, adjL);
}
