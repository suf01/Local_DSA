#include<bits/stdc++.h>
using namespace std;

bool find_target(int N, int arr[], int target){
    bool dp[N+1][target+1];
        
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < target+1; j++){
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }else if(i == 0){
                dp[i][j] = false;
            }else if(j == 0){
                dp[i][j] = true;
            }
                
            if(i > 0 && j > 0){
                break;
            }
        }
    }
        
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < target+1; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
            }else if(arr[i-1] == j){
                dp[i][j] = true;
            }else if(arr[i-1] < j && dp[i-1][j-arr[i-1]]){
                dp[i][j] = true;
            }else{
                dp[i][j] = false;
            }
        }
    }
        
    return dp[N][target];
}

int equalPartition(int N, int arr[]){
    if(N == 0){
        return 1;
    }
    if(N == 1){
        return 0;
    }
        
    int sum = 0;
        
    for(int i = 0; i < N; i++){
        sum += arr[i];
    }
        
    if(sum%2 != 0){
        return 0;
    }
        
    if(find_target(N, arr, sum/2)){
        return 1;
    }else{
        return 0;
    }
}

int main(){

}
