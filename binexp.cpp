#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int BinExpIT(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a) %M;
        }
        a = (a*a) %M;
        b = b>>1;
    }
    return ans;
}
int BinExpRec(int a, int b){
    if(b==0) return 1;

    if(b&1){
        return (a * (BinExpRec(a, b/2) * BinExpRec(a, b/2)) %M)%M;
    }
    else{
        return (BinExpRec(a, b/2) * BinExpRec(a, b/2))%M;
    }
}

int main(){
    int a = 2, b = 13;
    cout<<BinExpRec(a, b)<<endl;
}

