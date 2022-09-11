#include<bits/stdc++.h>
using namespace std;

string longestcommonsubsequence(string text1, string text2) {
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
        
    string ans = "";
    int i = n;
    int j = m;

    while(j > 0 && i > 0){
        if(text1[i-1] == text2[j-1]){
            ans += text1[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
