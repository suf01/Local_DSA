#include<bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        
    int cnt = 0;
    for(int diff = 0; diff < s.size(); diff++){
        for(int i = 0, j = diff; j < s.size(); i++, j++){
            if(diff == 0){
                dp[i][j] = true;
                cnt++;
            }else if(diff == 1){
                if(s[i] == s[j]){
                    dp[i][j] = true;
                    cnt++;
                }else{
                    dp[i][j] = false;
                }
            }else{
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    cnt++;
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return cnt;
}
