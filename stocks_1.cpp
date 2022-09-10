#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

//brute force
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i; j < prices.size(); j++){
            profit = max(profit, prices[j]-prices[i]);
        }
    }
    return profit;
}

//extra space O(n)
int maxProfit(vector<int>& prices) {
    int profit = 0;
    int n = prices.size();
        
    vector<int> temp(n+1);
        
    for(int i = n-1; i >= 0; i--){
        temp[i] = max(temp[i+1], prices[i]);
    }
        
    for(int i = 0; i < n; i++){
        profit = max(profit, temp[i]-prices[i]);
    }
        
    return profit;
}

//optimized
int maxProfit(vector<int>& prices) {
    int mini = INT_MAX;
    int profit = 0;
        
    for(int i = 0; i < prices.size(); i++){
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i]-mini);
    }
    return profit;
}
