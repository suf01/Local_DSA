#include<bits/stdc++.h>
using namespace std;

bool isvalid(int i, int j, int rows, int cols){
    if(i < 0 || i >= rows || j < 0 || j >= cols){
        return false;
    }
    return true;
}
    
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int total = (rows*cols);
    vector<vector<int> > ans;
    ans.push_back({rStart, cStart});

    int dis = 1;
    while(ans.size() < total){
        for(int i = 1; i <= dis; i++){
            if(isvalid(rStart, cStart+i, rows, cols)){
                ans.push_back({rStart, cStart+i});
            }
        }
        
        cStart += dis;
        
        for(int i = 1; i <= dis; i++){
            if(isvalid(rStart+i, cStart, rows, cols)){
                ans.push_back({rStart+i, cStart});
            }
        }
        
        rStart += dis;
        dis++;
        
        for(int i = 1; i <= dis; i++){
            if(isvalid(rStart, cStart-i, rows, cols)){
                ans.push_back({rStart, cStart-i});
            }
        }
        
        cStart -= dis;
        
        for(int i = 1; i <= dis; i++){
            if(isvalid(rStart-i, cStart, rows, cols)){
                ans.push_back({rStart-i, cStart});
            }
        }
        
        rStart -= dis;
        dis++;
    }
    return ans;
}
