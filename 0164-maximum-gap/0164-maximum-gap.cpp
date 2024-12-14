class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max1=0;
        for(int i=1;i<nums.size();i++){
            max1=max(max1,nums[i]-nums[i-1]);
        }
        return max1;
        
    }
};