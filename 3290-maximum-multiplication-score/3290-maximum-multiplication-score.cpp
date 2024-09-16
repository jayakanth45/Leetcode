class Solution {
public:
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][m]=-1e18;
        }
        
        for(int k=n-1;k>=0;k--){
            for(int i=m-1;i>=0;i--){
                long long take = -1e18;
         take = (long long)a[k]*b[i] + dp[k+1][i+1];
        long long notTake = dp[k][i+1];
        
        
        dp[k][i] = max(take,notTake);
                
                
            }
        }
        return dp[0][0];
    }
};