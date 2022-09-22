#include<bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
        
    //path compression without this t.c will be high
    return parent[node] = findParent(parent[node], parent);
}
    
void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
    int u_parent = findParent(u, parent);
    int v_parent = findParent(v, parent);
        
    if(u_parent == v_parent) return;
        
    if(rank[u_parent] > rank[v_parent]){
        parent[v_parent] = u_parent;
    }else if(rank[v_parent] > rank[u_parent]){
        parent[u_parent] = v_parent;
    }else{
        parent[u_parent] = v_parent;
        rank[v_parent]++;
    }
}
    
int spanningTree(int V, vector<vector<int>> adj[]){
    
    vector<int> parent(V);
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }
    
    vector<int> rank(V, 0);
        
    vector<vector<int> > nodeslist;
        
    for(int node = 0; node < V; node++){
        for(auto it: adj[node]){
            int u = node;
            int v = it[0];
            int wgt = it[1];
                
            vector<int> wgt_u_v;
            wgt_u_v.push_back(wgt);
            wgt_u_v.push_back(u);
            wgt_u_v.push_back(v);
                
            nodeslist.push_back(wgt_u_v);
        }
    }
        
    sort(nodeslist.begin(), nodeslist.end());
        
    int cost = 0;
    for(auto it: nodeslist){
        int u = it[1];
        int v = it[2];
        int wgt = it[0];
            
        if(findParent(u, parent) != findParent(v, parent)){
            cost += wgt;
            unionn(u, v, parent, rank);
        }
    }
    return cost;
}
