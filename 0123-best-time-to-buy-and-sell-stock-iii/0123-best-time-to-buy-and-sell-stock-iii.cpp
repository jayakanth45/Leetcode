class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int idx=prices.size()-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    int profit=0;
        if(buy){
           profit= max(-prices[idx]+dp[idx+1][0][count],dp[idx+1][1][count]);
        }
        else{
       profit= max(prices[idx]+dp[idx+1][1][count-1],dp[idx+1][0][count]);
                                      }
                                       dp[idx][buy][count]=profit;
                    
                }
            }
        }
        
    return dp[0][1][2];
        
    }
};