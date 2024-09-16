class Solution {
public:
     long long helper(vector<int>&a,vector<int>&b,int k,int i,vector<vector<long long>>&dp){
        if(k==4) return 0;
        if(i>b.size()-1) return -1e18;
        if(dp[k][i] != -1) return dp[k][i];
         long long take = -1e18;
         take = (long long)a[k]*b[i] + helper(a,b,k+1,i+1,dp);
        long long notTake = helper(a,b,k,i+1,dp);
        
        
        return dp[k][i] = max(take,notTake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>>dp(4,vector<long long>(n,-1));
        return helper(a,b,0,0,dp);
    }
};