#include<bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int prev = 0;

    int cnt = 0;
    for(int curr = 1; curr < intervals.size(); curr++){
        if(intervals[curr][0] < intervals[prev][1]){
            cnt++;
                // [1, 5] [2, 6]
                //         del
                // [1, 6] [2, 3]
                //  del
            if(intervals[curr][1] > intervals[prev][1]){
                prev = prev;
            }else if(intervals[curr][1] <= intervals[prev][1]){
                prev = curr;
            }
        }else{
            prev = curr;
        }
    }
    return cnt;
}
