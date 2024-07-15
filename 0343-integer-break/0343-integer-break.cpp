class Solution {
public:
  
    int helper(int count,int limit,int n,vector<vector<int>> &dp){
        if(limit==0){
            return count==n?1:0;
        }
        if(count>n){
            return 0;
        }
        if(dp[count][limit]!=-1){
            return dp[count][limit];
        }
        int pick=1;
        for(int i=1;i<n;i++){
            pick=max(pick,i*helper(count+i,limit-1,n,dp));
        }
        return dp[count][limit]=pick;
    }
    int integerBreak(int n) {
        int ans=1;
        for(int k=2;k<n;k++){
            vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
            ans=max(ans,helper(0,k,n,dp));
        }
        return ans;
        
    }
};