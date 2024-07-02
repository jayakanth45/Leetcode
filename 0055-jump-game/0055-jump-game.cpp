class Solution {
public:
   
    bool canJump(vector<int>& nums) {
       int last_reachable_index = nums.size()-1;
        for(int i =  nums.size()-2;i>=0;i--){
            if(nums[i]+i>=last_reachable_index){
                last_reachable_index = i;
            }
        }
        return last_reachable_index == 0;
    }
};