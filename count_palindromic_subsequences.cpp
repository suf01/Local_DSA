#include<bits/stdc++.h>
using namespace std;

int countPalindromes(string s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    int ans = 0;
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = 1;
            }else if(g == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 3;
                }else{
                    dp[i][j] = 2;
                }
            }else{
                if(s[i] == s[j]){
                    dp[i][j] = dp[i][j-1]+dp[i+1][j]+1;
                }else{
                    dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
