int perfectSum(int arr[], int n, int sum){
    if(n == 0){
        return 0;
    }
    
    int M = 1e9+7;
        
    int dp[n+1][sum+1];
        
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }else if(i == 0){
                dp[i][j] = 0;
            }else if(j == 0){
                dp[i][j] = 1;
            }
                
            if(i > 0 && j > 0){
                break;
            }
        }
    }
    
    //start from j = 0; only for test case with arr which contains '0' because adding it to the subset will also count as subset
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-arr[i-1]])%M;
            }else{
                dp[i][j] = (dp[i-1][j])%M;
            }
        }
    }
    
    return dp[n][sum];
}
