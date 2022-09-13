#include<bits/stdc++.h>
using namespace std;

//when no cycle -> bipartite
//when cycle of odd length -> not bipartite
//when cycle of even length -> bipartite

bool check_dfs(int node, vector<int> &color, vector<vector<int> > &graph){
    for(auto it: graph[node]){
        if(color[it] == -1){
            color[it] = 1-color[node];
            if(!check_dfs(it, color, graph)){
                return false;
            }
        }else if(color[it] == color[node]){
            return false;
        }
    }
    return true;
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
        
    vector<int> color(V, -1);
        
    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!check_dfs(i, color, graph)){
                return false;
            }
        }
    }
    return true;
}
