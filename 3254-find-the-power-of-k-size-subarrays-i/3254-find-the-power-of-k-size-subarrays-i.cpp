class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int j=0,currsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(i-j+1>=k){
                int b=(k * (2 * nums[j] + (k - 1))) / 2;
                if(b==currsum && nums[i]==nums[j]+(k-1)){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
                currsum-=nums[j];
                j++;
            }
        }
        return ans;
        
    }
};