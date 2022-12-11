// gfg and array elements are only positive numbers

bool canPair(vector<int> nums, int k) {

    unordered_map<int, int> mpp;     
    int n = nums.size();
        
    for(int i = 0; i < n; i++){
        int temp = nums[i]%k;
        mpp[temp]++;
    }
        
    if(mpp[0]%2){
        return false;
    }
    if(k%2 == 0){
        if(mpp[k/2]%2){
            return false;
        }
    }
    
    for(int i = 1; i < k; i++){
        if(mpp[i] != mpp[k-i]){
            return false;
        }
    }
    return true;
}

// leetcode and negative numbers
bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> mpp;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        // for negative intergers
        int rem = (arr[i]%k+k)%k;
        mpp[rem]++;
    }
    
    if(mpp[0]%2){
        return false;
    }
    if(k%2==0){
        if(mpp[k/2]%2){
            return false;
        }
    }
        
    for(int i = 1; i < k; i++){
        if(mpp[i] != mpp[k-i]){
            return false;
        }
    }
    return true;
}
