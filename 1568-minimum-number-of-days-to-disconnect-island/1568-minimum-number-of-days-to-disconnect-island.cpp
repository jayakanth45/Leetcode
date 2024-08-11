class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid, int n, int m){
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0 || vis[r][c])
            return;
        vis[r][c] = true;
        vector<pair<int,int>> adjCells = {{r, c+1}, {r+1, c}, {r-1, c}, {r, c-1}};
        for(auto it : adjCells){
            int nr = it.first;
            int nc = it.second;
            dfs(nr, nc, vis, grid, n, m);
        }
    }

    int countIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt += 1;
                    dfs(i, j, vis, grid, n, m);
                }
            }
        }

        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int numIslands = countIslands(grid);
        if(numIslands != 1) return 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int curIslands = countIslands(grid);
                    if(curIslands != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};