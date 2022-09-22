#include<bits/stdc++.h>
using namespace std;

//same as that of minmum no of deletion
int LCS(string &x, string &y){
    int n = x.size();
        
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
        
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
        
    return dp[n][n];
}

int minInsertions(string s){
    string x = s;
        
    reverse(s.begin(), s.end());
        
    string y = s;
        
    int lcs = LCS(x, y);
        
    return s.size()-lcs;
}
