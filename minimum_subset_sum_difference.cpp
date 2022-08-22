#include<bits/stdc++.h>
using namespace std;

vector<int> find_range(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
        
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
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
        
    for(int i = 1; i < n+1; i++){
        //j can start from either 0 for 1, both cases work, but in count subset problem j must start from 0, only for test cases which contain 0 as a part of the arry
        for(int j = 1; j < sum+1; j++){
            if(dp[i-1][j]){
                dp[i][j] = true;
            }else if(arr[i-1] <= j && dp[i-1][j-arr[i-1]]){
                dp[i][j] = true;
            }else{
                dp[i][j] = false;
            }
        }
    }

    vector<int> range;
    for(int j = 0; j < sum+1; j++){
        if(dp[n][j]){
            range.push_back(j);
        }
    }
        
    return range;
}
    
int minDifference(int arr[], int n){
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
        
    vector<int> possible_subset_sum = find_range(arr, n, sum);
        
    //consider two subsets s1 and s2 in range from 0 to sum(sum of array elements, which is the maximum sum that is possible)
    //therefore the goal or aim is to minimize the difference of sum between these sub arrays abs(s1-s2)
    //to keep difference always positive limit s1, to always contain elements before or equal to its mid  
    //we only need to find the subset s1, because s2 = range-s1, where range is sum of all array elements and s1 is sum of subarray
    //and since s2 is always bigger, s2-s1 = range-s1-s1 = range-(2*s1)
    //therefore minimize  range-(2*s1);
        
    int mini = INT_MAX;
    int m = possible_subset_sum.size();
        
    int mid = m/2;
        
    for(int i = 0; i <= mid; i++){
        if((sum-(2*possible_subset_sum[i])) < mini){
            mini = abs(sum-(2*possible_subset_sum[i]));
        }
    }
        
    return mini;
} 

int main(){

}
