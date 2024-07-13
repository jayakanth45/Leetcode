class Solution {
public:
   
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=0;
        for(int idx=nums.size()-2;idx>=0;idx--){
             int ans=nums.size()-1;
        for(int j=1;j<=nums[idx];j++){
            if(idx+j>nums.size()-1){
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