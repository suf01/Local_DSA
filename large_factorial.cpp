#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
        
    vector<int> ans;
    ans.push_back(1);
        
    for(int x = 2; x <= N; x++){
        int carr = 0;
        for(int i = 0; i < ans.size(); i++){
            int val = ans[i]*x + carr;
            ans[i] = val%10;
            carr = val/10;
        }
        while(carr != 0){
            ans.push_back(carr%10);
            carr = carr/10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;    
}
