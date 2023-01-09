vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int> > mpp;

        int n = mat.size();
        int m = mat[0].size();

        if(n*m == 0){
            return {};
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        /*
        for(auto it: mpp){
            for(auto jt: it.second){
                cout<<jt<<" ";
            }
            cout<<endl;
        }
        */

        vector<int> ans;
        bool flag = true;
        for(auto it: mpp){
            vector<int> temp = it.second;
            if(flag == false){
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }else{
                for(int i = temp.size()-1; i >= 0; i--){
                    ans.push_back(temp[i]);
                }
            }
            flag = !flag;
        }
        return ans;
    }


//optimal
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int r = 0;
        int c = 0;

        int total = n*m;
        vector<int> ans;

        if(total == 0){
            return ans;
        }

        for(int i = 0; i < total; i++){
            ans.push_back(mat[r][c]);

            if((r+c)%2 == 0){
                if(c == m-1){
                    r++;
                }else if(r == 0){
                    c++;
                }else{
                    r--;
                    c++;
                }
            }else{
                if(r == n-1){
                    c++;
                }else if(c == 0){
                    r++;
                }else{
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
