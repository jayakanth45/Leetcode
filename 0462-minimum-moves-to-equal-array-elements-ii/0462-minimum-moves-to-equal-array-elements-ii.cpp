class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=nums.size();
       int pos=nums[k/2];
        int ans=0;
        for(int i=0;i<k;i++){
            ans+=abs(pos-nums[i]);
        }
        return ans;
        
    }
};