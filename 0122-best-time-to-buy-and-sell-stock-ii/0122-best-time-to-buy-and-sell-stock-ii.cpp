class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0)); // Initialize to 0 for base cases

    // Base cases
    dp[n][1] = 0; // No profit if no days left to buy
    dp[n][0] = 0; // No profit if no days left to sell

    // Fill the DP table in reverse
    for (int idx = n - 1; idx >= 0; idx--) {
        for (int jdx = 1; jdx >= 0; jdx--) {
            int profit = 0;
            if (jdx) {
                // Buying option
                int buy = -prices[idx] + dp[idx + 1][0];
                int skip_buying = dp[idx + 1][1];
                profit = max(buy, skip_buying);
            } else {
                // Selling option
                int sell = prices[idx] + dp[idx + 1][1];
                int skip_selling = dp[idx + 1][0];
                profit = max(sell, skip_selling);
            }
            dp[idx][jdx] = profit;
        }
    }

    return dp[0][1]; // Maximum profit when starting with the option to buy
}

};