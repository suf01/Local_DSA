#include<bits/stdc++.h>
using namespace std;

vector <int> nearlySorted(int arr[], int num, int K){
  
    priority_queue<int, vector<int>, greater<int> > q;
    
    int i = 0;
    int j = 0;
    int n = num;
        
    vector<int> ans(n);
        
    while(i < n && j < n){
        if(q.size() > K){
            ans[i] = q.top();
            i++;
            q.pop();
        }else{
            q.push(arr[j]);
            j++;
        }
    }
    
    while(!q.empty()){
        ans[i] = q.top();
        i++;
        q.pop();
    }
    return ans;
}
