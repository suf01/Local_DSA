#include<bits/stdc++.h>
using namespace std;

//gray code --> only one bit changes when we move to next number

void generate_gray(int n, vector<int> &temp){
    
    if(n == 1){
        temp.push_back(0);
        temp.push_back(1);
        return;
    }
        
    generate_gray(n-1, temp);
        
    for(int i = temp.size()-1; i >= 0; i--){
        int x = (1<<(n-1)) | temp[i];
        temp.push_back(x);
    }
}

vector<int> grayCode(int n) {
    vector<int> ans;
        
    if(n <= 0){
        return ans;
    }
        
    vector<int> temp;
    generate_gray(n, temp);
        
    return temp;
}
