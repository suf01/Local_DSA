vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int> > ans;

    ans.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        int n = ans.size();
        int s1 = ans[n-1][0];
        int e1 = ans[n-1][1];

        int s2 = intervals[i][0];
        int e2 = intervals[i][1];

        if(s2 >= s1 && s2 <= e1){
            ans[n-1][0] = min(s1, s2);
            ans[n-1][1] = max(e1, e2);
        }else{
            ans.push_back({intervals[i][0], intervals[i][1]});
        }
    }
    return ans;
}
