#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    bool dp[arr.size()+1][sum+1];
        
    for(int i = 0; i < arr.size()+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(i > 0 && j > 0){
                break;
            }
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }else if(i == 0){
                dp[i][j] = false;
            }else if(j == 0){
                dp[i][j] = true;
            }
        }
    }
        
    for(int i = 1; i < arr.size()+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
            }else if(arr[i-1] == j){
                dp[i][j] = true;
            }else if(j > arr[i-1] && dp[i-1][j-arr[i-1]]){
                dp[i][j] = true;
            }else{
                dp[i][j] = false;
            }
        }
    }
    
    /*
    for(int i = 0; i < arr.size()+1; i++){
        for(int j = 0; j < sum+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
        
    return dp[arr.size()][sum];
}

int main(){

}
