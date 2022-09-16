#include<bits/stdc++.h>
using namespace std;

int LCS(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();
        
    int dp[n+1][m+1];
        
    memset(dp, 0, sizeof(dp));
        
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    
int longestPalindromeSubseq(string s) {
    string str1 = s;
    reverse(s.begin(), s.end());
    string str2 = s;
        
    return LCS(str1, str2);
}
