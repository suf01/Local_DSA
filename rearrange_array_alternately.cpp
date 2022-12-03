#include<bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n){ 
    
    long long s = 0;
    long long e = n-1;
        
    long long maxi = arr[n-1]+1;
    for(long long i = 0; i < n; i++){
        if(i%2 == 0){
            arr[i] = (arr[e]%maxi)*maxi+arr[i];
            e--;
        }else{
            arr[i] = (arr[s]%maxi)*maxi+arr[i];
            s++;
        }
    }
    for(long long i = 0; i < n; i++){
        arr[i] = arr[i]/maxi;
    }
}
