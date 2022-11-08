#include<bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N){
        
    long long int var = 0;
    for(int i = 0; i < N; i++){
        var = var^Arr[i];
    }
    long long int rsbm = (var&(-var));
        
    long long int a = 0;
    long long int b = 0;
    
    for(int i = 0; i < N; i++){
        if((Arr[i]&rsbm)){
            a = a^Arr[i];
        }else{
            b = b^Arr[i];
        }
    }
    vector<long long int> ans;
    if(a > b){
        ans.push_back(a);
        ans.push_back(b);
    }else{
        ans.push_back(b);
        ans.push_back(a);
    }
    return ans;    
}
