#include<bits/stdc++.h>
using namespace std;

//recursion
int solve(int x, int y, string s1, string s2){
    if(x == 0 || y == 0){
        return 0;
    }
        
    if(s1[x-1] == s2[y-1]){
        return 1+solve(x-1, y-1, s1, s2);
    }else{
        return max(solve(x-1, y, s1, s2), solve(x, y-1, s1, s2));
    }
}

//recursion + memoziation

int dp[1001][1001];
int flag = true;
    
int lcs(int x, int y, string s1, string s2){
    if(flag){
        memset(dp, -1, sizeof(dp));
        flag = false;
    }
        
    if(x == 0 || y == 0){
        return 0;
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    if(s1[x-1] == s2[y-1]){
        return dp[x][y] = 1+lcs(x-1, y-1, s1, s2);
    }else{
        return dp[x][y] = max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
    }
}

//recursion + memoziation, for leetcode pass strings by reference

int dpp[1001][1001];
bool flagg = true;
    
int solve(string &x, string &y, int n, int m){
    if(flagg){
        memset(dpp, -1, sizeof(dpp));
        flagg = false;
    }
        
    if(n == 0 || m == 0){
        return 0;
    }
        
    if(dpp[n][m] != -1){
        return dpp[n][m];
    }
        
    if(x[n-1] == y[m-1]){
        return dpp[n][m] = 1+solve(x, y, n-1, m-1);
    }else{
        return dpp[n][m] = max(solve(x, y, n-1, m), solve(x, y, n, m-1));
    }
}
    
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
        
    if(n < 1 || m < 1){
        return 0;
    }
    return solve(text1, text2, n, m);
}


//top-down using dp, 2d array
int longestcommonsubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
        
    int dp[n+1][m+1];
        
    dp[0][0] = 0;
        
    for(int i = 1; i < n+1; i++){
        dp[i][0] = 0;
    }
        
    for(int j = 1; j < m+1; j++){
        dp[0][j] = 0;
    }
        
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
        
    return dp[n][m];
}
