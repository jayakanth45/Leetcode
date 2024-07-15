class Solution {
public:
    long long solve(int n, vector<long long> &dp)
    {
       
        if(n ==2)
        {
            return 1;
        }
        

        if(dp[n]!=-1)
        {
            return dp[n];
        }
        long long maxi =1;
        long long p=1;
        for(int i=1;i<n;i++)
        {
                p =i*max(solve(n-i,dp),(long long)n-i);
                maxi = max(maxi,p);
        }
        dp[n] =maxi;
        return dp[n];
    }
    long long integerBreak(int n) {

        vector<long long > dp(n+1,-1);
         long long ans= solve(n,dp);
         return ans;
        
    }
};
