#include<bits/stdc++.h>
using namespace std;

int count_subset_sum(int arr[], int n, int target){
    int dp[n+1][target+1];

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < target+1; j++){
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

    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < target+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int count_subset_sum_with_given_difference(int arr[], int n, int diff){
    //let s1 and s2 be the two subsets sums
    //we need to find abs(s1-s2) = diff
    //wkt s1+s2 = sum of array = total sum;
    //adding the above two equations we get 2*s1 = totalsum + diff
    //therefore s1 = (totalsum + diff)/2
    //this problem is now reduced to count no of subsets with given sum

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    int s1 = (sum+diff)/2;

    return count_subset_sum(arr, n, s1);
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int diff;
    cin>>diff;

    cout<<count_subset_sum_with_given_difference(arr, n, diff);
}
