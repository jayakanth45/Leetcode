class Solution {
public:
    void giveans(vector<vector<int>> &ans,vector<int> &temp,int sum,int idx,vector<int> nums){
        
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=idx;i<nums.size();i++){
            if(i!=idx && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>sum){
                break;
            }
            
            if(nums[i]<=sum){
                temp.push_back(nums[i]);
                giveans(ans,temp,sum-nums[i],i+1,nums);
                temp.pop_back();
            }
           
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        giveans(ans,temp,target,0,candidates);
        return ans;
        
    }
};