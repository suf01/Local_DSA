bool ispossible(vector<vector<char> > &board, int x, int y, char k){
        
        for(int i = 0; i < board.size(); i++){
            if(board[i][y] == k){
                return false;
            }
        }
        
        for(int j = 0; j < board[0].size(); j++){
            if(board[x][j] == k){
                return false;
            }
        }
        
        int sub_i = 3*(x/3);
        int sub_j = 3*(y/3);
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[sub_i + i][sub_j + j] == k){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char> > &board, int i, int j){
        if(i == board.size()){
            return true;
        }
        
        int nexti = 0;
        int nextj = 0;
        
        if(j == board[0].size()-1){
            nexti = i+1;
            nextj = 0;
        }else{
            nexti = i;
            nextj = j+1;
        }
        
        if(board[i][j] != '.'){
            return solve(board, nexti, nextj);
        }else{
            for(char k = '1'; k <= '9'; k++){
                if(ispossible(board, i, j, k)){
                    board[i][j] = k;
                    if(solve(board, nexti, nextj)){
                        return true;
                    }
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        int i = 0;
        int j = 0;
        int n = board.size();
        int m = board[0].size();
        
        solve(board, i, j);
    }
