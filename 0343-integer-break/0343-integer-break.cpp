class Solution {
public:
  
    int helper(int count,int limit,int n,vector<vector<int>> &dp){
        dp[n][0]=1;
        for(int count=n-1;count>=0;count--){
            for(int k=1;k<=limit;k++){
                int pick=0;
                for(int i=1;i<n;i++){
                    if (count + i <= n) {  // Ensure the index does not go out of bounds
                    pick = max(i * dp[count + i][k - 1], pick);
                }
                }
                dp[count][k]=pick;
            }
        }
        return dp[0][limit];
        
    }
    int integerBreak(int n) {
        int ans=1;
        for(int k=2;k<n;k++){
            vector<vector<int>> dp(n+1,vector<int> (k+1,0));
            ans=max(ans,helper(0,k,n,dp));
        }
        return ans;
        
    }
};