class Solution {
public:
    int givecount(int idx,int jdx,vector<vector<int>> &dp){
        if(idx==0 && jdx==0){
            return 1;
        }
        if(idx<0 || jdx<0){
            return 0;
        }
        if(dp[idx][jdx]!=-1){
            return dp[idx][jdx];
        }
        int up=givecount(idx-1,jdx,dp);
        int left=givecount(idx,jdx-1,dp);
        return dp[idx][jdx]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return givecount(m-1,n-1,dp);
    }
};