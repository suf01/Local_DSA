#include<bits/stdc++.h>
using namespace std;

long long int count(int coins[], int N, int sum){

    // code here.
    long long int dp[N+1][sum+1];
    memset(dp, 0, sizeof(dp));
        
    dp[0][0] = 1;
        
    for(long long int j = 1; j < sum+1; j++){
        dp[0][j] = 0;
    }
        
    /*
    for(long long int i = 0; i < N+1; i++){
        for(long long int j = 0; j < sum+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    for(long long int i = 1; i < N+1; i++){
        for(long long int j = 0; j < sum+1; j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
        
    /*
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < sum+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[N][sum];
}
