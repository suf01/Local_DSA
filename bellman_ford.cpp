#include<bits/stdc++.h>
using namespace std;

// it is used to detect negative cycle and find shortest path in case of negative or positive weights
// T.C O(V * E)
// it is not possible to get more optimial distance for a node after relaxing V-1 times, if we get then it has negative cycle

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dis(V, 1e8);
    dis[S] = 0;
        
    for(int i = 0; i < V-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wgt = it[2];
                
            if(dis[u] != 1e8 && dis[u]+wgt < dis[v]){
                dis[v] = dis[u]+wgt;
            }
        }
    }
    
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wgt = it[2];
            
        if(dis[u] != 1e8 && dis[u]+wgt < dis[v]){
            return {-1};
        }
    }
    return dis;
}
