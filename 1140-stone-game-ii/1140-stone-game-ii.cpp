class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int> (n+1,0));
         vector<int> suffixsum(n,0);
         suffixsum[n-1]=piles[n-1];
         for(int i=n-2;i>=0;i--){
            suffixsum[i]=suffixsum[i+1]+piles[i];
         }
         for(int i=n-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                if(i+2*j>=n){
                    dp[i][j]=suffixsum[i];
                }
                else{
                    for(int x=1;x<=2*j;x++){
                        dp[i][j]=max(dp[i][j],suffixsum[i]-dp[i+x][max(j,x)]);
                    }
                }
            }
         }

         return dp[0][1];

    }
};