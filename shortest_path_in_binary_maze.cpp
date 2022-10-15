#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
    
    int i = source.first;
    int j = source.second;
        
    int x = destination.first;
    int y = destination.second;
        
    if(grid[i][j] == 0){
        return -1;
    }
        
    int m = grid.size();
    int n = grid[0].size();
        
    queue<pair<pair<int, int>, int> > q;
    q.push({{i, j}, 0});
        
    int ans = INT_MAX;
    bool flag = false;
    while(!q.empty()){
        i = q.front().first.first;
        j = q.front().first.second;
            
        int val = q.front().second;
        q.pop();
            
        if(i == x && j == y){
            flag = true;
            ans = min(ans, val);
            continue;
        }
        
        if(i > 0 && grid[i-1][j] != 0){
            q.push({{i-1, j}, val+1});
            grid[i-1][j] = 0;
        }
        if(i < m-1 && grid[i+1][j] != 0){
            q.push({{i+1, j}, val+1});
            grid[i+1][j] = 0;
        }
        if(j > 0 && grid[i][j-1] != 0){
            q.push({{i, j-1}, val+1});
            grid[i][j-1] = 0;
        }
        if(j < n-1 && grid[i][j+1] != 0){
            q.push({{i, j+1}, val+1});
            grid[i][j+1] = 0;
        }
    }
    if(flag){
        return ans;
    }
    return -1;
}
