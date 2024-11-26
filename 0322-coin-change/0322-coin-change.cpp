class Solution {
public:
    /*int giveans(vector<int> coins,int idx,int sum,vector<vector<int>> &dp){
        if(idx<0 || sum<0){
            return INT_MAX;
        }
        if(sum==0){
            return 0;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
       
        int pick=INT_MAX,skip=INT_MAX;
        if(sum>=coins[idx]){
            if(giveans(coins,idx,sum-coins[idx],dp)!=INT_MAX)
            pick=1+giveans(coins,idx,sum-coins[idx],dp);
        }
        
        skip=giveans(coins,idx-1,sum,dp);
        return dp[idx][sum]=min(pick,skip);
    }*/
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
       // Base case: sum = 0, no coins are needed.
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }

    // Fill the DP table.
    for (int idx = 0; idx < n; idx++) {
        for (int sum = 1; sum <= amount; sum++) {
            int pick = INT_MAX, skip = INT_MAX;

            // If picking the current coin is possible.
            if (sum >= coins[idx] && dp[idx][sum - coins[idx]] != INT_MAX) {
                pick = 1 + dp[idx][sum - coins[idx]];
            }

            // Skip the current coin (use previous row if possible).
            if (idx > 0) {
                skip = dp[idx - 1][sum];
            }

            // Update the DP table.
            dp[idx][sum] = min(pick, skip);
        }
    }

    // The result is stored in `dp[n-1][amount]`.
    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
    }
};