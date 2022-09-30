#include<bits/stdc++.h>
using namespace std;

int find_path(vector<vector<int>>& grid, int i, int j, vector<vector<int> > &dp){
    if(i == grid.size() || j == grid[0].size()){
        return 1000000;
    }

    if(i == grid.size()-1 && j == grid[0].size()-1){
        return grid[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int op1 = grid[i][j] + find_path(grid, i, j+1, dp);
    int op2 = grid[i][j] + find_path(grid, i+1, j, dp);
        
    return dp[i][j] = min(op1, op2);
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > dp(n+1, vector<int>(m+1, -1));

    int i = 0;
    int j = 0;

    return find_path(grid, i, j, dp);
}
