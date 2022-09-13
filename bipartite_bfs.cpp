bool check_bfs(int node, vector<int> &color, vector<vector<int> > &graph){
    queue<int> q;
    q.push(node);
    color[node] = 0;
        
    while(!q.empty()){
        int temp = q.front();
        q.pop();
            
        for(auto it: graph[temp]){
            if(color[it] == -1){
                color[it] = 1-color[temp];
                q.push(it);
            }else if(color[it] == color[temp]){
                return false;
            }
        }
    }
    return true;
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
        
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++){
        if(color[i] == -1){
            if(!check_bfs(i, color, graph)){
                return false;
            }
        }
    }
    return true;
}
