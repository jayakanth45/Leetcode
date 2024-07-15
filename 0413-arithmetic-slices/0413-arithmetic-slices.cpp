class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c=0;
        int ans =0;
        if(nums.size()<=2){
            return 0;
        }
        for(int i=0;i<nums.size()-2;i++)
        {
            
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1])
            {
                c++;
            }
            else
            {
                c=0;
            }
            
        ans +=c;
        }
        
        return ans;
        
    }
};