/*
  for 4 direction
  
  int delr = {-1, 0, 1, 0};
  int delc = {0, 1, 0, -1};
  
  for(int i = 0; i < 4; i++){
     int newr = r+delr[i];
     int newc = c+delc[i];
  }
*/

/*
  for 8 direction
  
  for(int delr = -1; delr <= 1; delr++){
     for(int delc = -1; delc <= 1; delc++){
        int newr = r+delr;
        int newc = c+delc;
     }
  }
*/


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int startrow = 0;
    int startcol = 0;

    int n = grid.size();
    int m = grid[0].size();

    if(grid[startrow][startcol] == 1){
        return -1;
    }
    if(grid[n-1][m-1] == 1){
        return -1;
    }

    queue<pair<int, pair<int, int> > > q;
    q.push({0, {startrow, startcol}});
    grid[startrow][startcol] = 1;

    while(!q.empty()){
        int prev = q.front().first;

        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if(r == n-1 && c == m-1){
            return prev+1;
        }

        for(int delr = -1; delr <= 1; delr++){
            for(int delc = -1; delc <= 1; delc++){
                int newr = r+delr;
                int newc = c+delc;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0){
                    q.push({prev+1, {newr, newc}});
                    grid[newr][newc] = 1;
                }
            }
        }
    }
    return -1;
}
