#include<bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K) {
      
    vector<vector<int> > adj(K);
        
    for(int i = 0; i < N-1; i++){
        string a = dict[i];
        string b = dict[i+1];
            
        int m = min(int(a.size()), int(b.size()));
            
        for(int j = 0; j < m; j++){
            if(a[j] != b[j]){
                adj[a[j]-'a'].push_back(b[j]-'a');
                break;
            }
        }
    }
        
    vector<int> indegree(K, 0);
    for(int i = 0; i < K; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i = 0; i < K; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
            
        ans+=char(node+97);
            
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return ans;
}
