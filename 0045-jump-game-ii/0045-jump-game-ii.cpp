class Solution {
public:
   
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[n-1]=0;
        for(int idx=n-2;idx>=0;idx--){
             int ans=n-1;
        for(int j=1;j<=nums[idx];j++){
            if(idx+j>n-1){
                ans=1;
            }
            else
            ans=min(ans,1+dp[idx+j]);
        }
        dp[idx]=ans;
            
            
        }
       return dp[0];
      
    }
};