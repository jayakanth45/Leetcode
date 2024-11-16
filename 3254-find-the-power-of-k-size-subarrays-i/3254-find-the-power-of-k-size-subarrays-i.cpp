class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int j=0,currsum=0;
        int n=nums.size();
        bool flag=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if((i!=n-1 && i-j+1!=k && nums[i]>nums[i+1])|| (i!=n-1 && i-j+1!=k && nums[i+1]-nums[i]!=1)){
                flag=1;
            }
            if(i-j+1>=k){
                int b=(k * (2 * nums[j] + (k - 1))) / 2;
                if(!flag && b==currsum && nums[i]==nums[j]+(k-1)){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
                flag=0;
                currsum-=nums[j];
                j++;
            }
        }
        return ans;
        
    }
};