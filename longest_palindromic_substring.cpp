string longestPalindrome(string s) {
    int dp[s.size()][s.size()];
        
    memset(dp, 0, sizeof(dp));
    int maxi = INT_MIN;
        
    int start = 0;
    int end = 0;
        
    for(int diff = 0; diff < s.size(); diff++){
        for(int i = 0, j = diff; j < s.size(); i++, j++){
            if(diff == 0){
                dp[i][j] = 1;
                if(dp[i][j] > maxi){
                    maxi = dp[i][j];
                    start = i;
                    end = j;
                }
            }else if(diff == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 2;
                    if(dp[i][j] > maxi){
                        start = i;
                        end = j;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 2+dp[i+1][j-1];
                    if(dp[i][j] > maxi){
                        maxi = dp[i][j];
                        start = i;
                        end = j;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
    }
        
    string ans = "";
    for(int i = start; i <= end; i++){
        ans += s[i];
    }
    return ans;
}
