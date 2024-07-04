class Solution {
public:
    int path(vector<vector<int>> &grid,int idx,int jdx,vector<vector<int>> &dp){
        if(idx==0 && jdx==0){
            return grid[idx][jdx];
        }
        if(idx<0 || jdx<0){
            return 1e9;
        }
        if(dp[idx][jdx]!=-1){
            return dp[idx][jdx];
        }
        long long down=grid[idx][jdx]+path(grid,idx-1,jdx,dp);
        long long  right=grid[idx][jdx]+path(grid,idx,jdx-1,dp);
        return dp[idx][jdx]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int> (grid[0].size(),-1));
        return path(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};