class Solution {
public:
   int giveans(vector<int> prices,int idx,int buy,vector<vector<int>> &dp){
        if(idx>=prices.size()){
            return 0;
        }
      int profit=0;
       if(dp[idx][buy]!=-1){
           return dp[idx][buy];
       }
        if(buy){
            profit=max(-prices[idx]+giveans(prices,idx+1,0,dp),giveans(prices,idx+1,1,dp));
        }
       else
        profit=max(prices[idx]+giveans(prices,idx+2,1,dp),giveans(prices,idx+1,0,dp));
       return dp[idx][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
    return giveans(prices,0,1,dp);
        
    }
};