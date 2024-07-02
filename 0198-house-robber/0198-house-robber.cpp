class Solution {
public:
    int robbbers(vector<int> nums,int idx,vector<int> &dp){
        if(idx==0){
            return nums[idx];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
       
         int pick=nums[idx]+robbbers(nums,idx-2,dp);
        
        
        int notpick=robbbers(nums,idx-1,dp);
            
        return dp[idx]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
       vector<int> dp(nums.size(),-1);
       return robbbers(nums,nums.size()-1,dp);
        
    }
};