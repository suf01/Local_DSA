#include<bits/stdc++.h>
using namespace std;

//for k = 2; or alternate kills only, express n as (2^x) + l; where x is the highest pow of 2<=n; and the ans is given by (2l+1)
//this works of bits e.g; n = 7 = 0 111 = (2^x, l) and 2*l = l<<1 and (2*l)+1 = (l<<1) + 1 = 110 + 1 = 111 = 7 

//using formula works only for alternates or k = 2;
int powof2(int n){
    int i = 1;

    while(i*2 <= n){
        i = i*2;
    }
    return i;
}

int laststanding(int n){
    int hp2 = powof2(n); // which give (2^x)
    int l = n-hp2;

    return (2*l)+1;
}

//josephus problem for any k
void solve(vector<int> &nums, int k, int index, int &ans){
    if(nums.size() == 1){
        ans = nums[0];
        return;
    }
    
    index = (index+k)%nums.size();
    nums.erase(nums.begin()+index);
        
    solve(nums, k, index, ans);
}
    
int findTheWinner(int n, int k) {
    k = k-1;
        
    if(n == 0) return 0;
        
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        nums[i] = i+1;
    }
        
    int ans = -1;
    solve(nums, k, 0, ans);
    return ans;
}

int main(){
    cout<<laststanding(7);
}
