class Solution {
public:
    void giveans(vector<vector<int>> &ans,vector<int> &temp,int idx,int sum,vector<int> nums){
        if(idx>=nums.size() || sum<0){
            return;
        }
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        if(nums[idx]<=sum){
            temp.push_back(nums[idx]);
            giveans(ans,temp,idx,sum-nums[idx],nums);
            temp.pop_back();
        }
        giveans(ans,temp,idx+1,sum,nums);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        giveans(ans,temp,0,target,candidates);
        return ans;
        
    }
};