class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currsum=0;
        int j=0;
        long long max1=0;
        int num1=-1;
        unordered_map<long long,long long> um;
        bool flag=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(um.find(nums[i])!=um.end()){
                if(um[nums[i]]==1)
                count++;
                num1=nums[i];
                flag=1;
            }
            um[nums[i]]++;
          
            if(i-j+1==k){
                if(flag!=1 && count==0){
                    max1=max(max1,currsum);
                }
                flag=0;
                if(um[nums[j]]-1==0){
                    um.erase(nums[j]);
                }
                else{
                um[nums[j]]--;
                    if(um[nums[j]]==1){
                        count--;
                    }
                }
                    
                
                currsum-=nums[j++];
                
                
            }
        }
        return max1;
        
    }
};