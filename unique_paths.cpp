#include<bits/stdc++.h>
using namespace std;

//recursion + memoziation
int find_paths(int m, int n, int i, int j, vector<vector<int> > &dp){
    if(i == m-1 && j == n-1){
        return 1;
    }
    if(i >= m || j >= n){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }   
    int op1 = find_paths(m, n, i+1, j, dp);
    int op2 = find_paths(m, n, i, j+1, dp);
    return dp[i][j] = op1+op2; 
}
    
int uniquePaths(int m, int n) {
    vector<vector<int> > dp(m, vector<int>(n, -1));
    return find_paths(m, n, 0, 0, dp);
}

//top-down
long long int numberOfPaths(int m, int n){
    int M = 1e9+7;
    vector<vector<long long> > dp(m, vector<long long>(n, 0));
        
    for(int i = 0; i < m; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j < n; j++){
        dp[0][j] = 1;
    }
        
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%M;
        }
    }
    return dp[m-1][n-1];
}
