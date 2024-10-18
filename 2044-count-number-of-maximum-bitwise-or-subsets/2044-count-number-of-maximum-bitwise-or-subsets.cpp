class Solution {
public:
    int giveans(int idx,vector<int> nums,int sum,int k){
       if (idx<0) return (sum==k)?1:0;
        int take=giveans(idx-1,nums,sum,k|nums[idx]);
        int not_take=giveans(idx-1,nums,sum,k);
        return take+not_take;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int r=0;
        for(auto x:nums){
            r|=x;
        }
        int k=0;
        return giveans(nums.size()-1,nums,r,k);
    }
};