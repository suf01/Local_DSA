#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
        
    int dp[n+1][amount+1];
        
    /*
     intialize as follows
     amount    0  1  2  3  4
            --|--------------
            0 |*  *  *  *  *   --> we need INT_MAX-1 number of coins to make amount = j   
              |
            1 |0               --> in this problem we also need to initialize 1st row
              |                     (*) if the amount j is completely divisible by the
            2 |0                        coins[i-1] which is coins[0] then dp[1][j] = j/coins[0]
              |                         only if j%coins[0] == 0 else it is INT_MAX-1
            3 |0
               
               ^
               |  we need 0 coins to makes amount 0
               n    
    */


    for(int i = 1; i < n+1; i++){
        dp[i][0] = 0;
    }
        
        for(int j = 0; j < amount+1; j++){
            dp[0][j] = INT_MAX-1;
        }
        
        for(int j = 1; j < amount+1; j++){
            if((j % coins[0]) == 0){
                dp[1][j] = j/coins[0];
            }else{
                dp[1][j] = INT_MAX-1;
            }
        }
        
        for(int i = 2; i < n+1; i++){
            for(int j = 1; j < amount+1; j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount] == INT_MAX-1){
            return -1;
        }else{
            return dp[n][amount];
        }
}
