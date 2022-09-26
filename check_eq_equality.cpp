#include<bits/stdc++.h>
using namespace std;

int findPar(int x, vector<int> &parent){
    if(parent[x] == x){
        return x;
    }
        
    return parent[x] = findPar(parent[x], parent);
}
    
void unionn(int u, int v, vector<int> &rank, vector<int> &parent){
    int parent_u = findPar(u, parent);
    int parent_v = findPar(v, parent);
        
    if(parent_u == parent_v) return;
        
    if(rank[parent_u] > rank[parent_v]){
        parent[parent_v] = parent_u;
    }else if(rank[parent_v] > rank[parent_u]){
        parent[parent_u] = parent_v;
    }else{
        parent[parent_u] = parent_v;
        rank[parent_v]++;
    }
}
    
bool equationsPossible(vector<string>& equations) {    
    vector<int> rank(26, 0);
    vector<int> parent(26);
        
    for(int i = 0; i < 26; i++){
        parent[i] = i;
    }
        
    for(auto it: equations){
        int a = it[0]-'a';
        int b = it[3]-'a';
            
        if(it[1] == '='){
            unionn(a, b, rank, parent);
        }
    }
        
    for(auto it: equations){
        int a = it[0]-'a';
        int b = it[3]-'a';
            
        if(it[1] == '!'){
            int x = findPar(a, parent);
            int y = findPar(b, parent);
                
            if(x == y){
                return false;
            }
        }
    }
        
    return true;
}
