class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1){
            
        }
            
            else
            {
                int k=0;
        while(nums[k]==0 && k<nums.size()){
            if(k==nums.size()-1)
                break;
            k++;
            
        }
        int i=k;
        int j=k+1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=0 && nums[j]==0){
                swap(nums[i],nums[j]);
            }
           else if(nums[i]==0){
                i++;
            }
            else if(nums[j]!=0){
                j++;
            }
            
        }
        k=0;
        while(nums[k]==0 && k<nums.size()){
            if(k==nums.size()-1)
                break;
            k++;
            
        }
                while(nums[k]==1 && k<nums.size()){
            if(k==nums.size()-1)
                break;
            k++;
            
        }
        i=k;
        j=k+1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=1 && nums[j]==1){
                swap(nums[i],nums[j]);
            }
           else if(nums[i]==1){
                i++;
            }
            else if(nums[j]!=1){
                j++;
            }
            
        }
            }
        
        
    }
};