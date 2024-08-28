class Solution {
public:
    bool res;

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int r, int c) {
        if (x < 0 || x >= r || y < 0 || y >= c || grid2[x][y] == 0) return;
        if (grid1[x][y] == 0) res = false;
        grid2[x][y] = 0;

        for (int dx : {-1, 1}) dfs(grid1, grid2, x + dx, y, r, c);  // Move up/down
        for (int dy : {-1, 1}) dfs(grid1, grid2, x, y + dy, r, c);  // Move left/right
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid1[0].size(), subIslands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid2[i][j] == 1) {
                    res = true;
                    dfs(grid1, grid2, i, j, rows, cols);
                    subIslands += res;
                }
            }
        }
        return subIslands;
    }
};
