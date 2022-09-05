#include<bits/stdc++.h>
using namespace std;

int maxsum(vector<int> v){
    int n = v.size();

    int cur = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        cur += v[i];

        if(cur > max){
            maxi = cur;
        }
        if(cur < 0){
            cur = 0;
        }
    }
    return max;
}

int smallestSumSubarray(vector<int>& a){
    int mini = INT_MAX;
    int curr = 0;
      
    for(int i = 0; i < a.size(); i++){
        
        if(curr > 0){
            curr = a[i];
        }else{
            curr += a[i];
        }
          
        if(curr < mini){
            mini = curr;
        }
    }
    
    return mini;
}


int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cout<<maxsum(v);
}
