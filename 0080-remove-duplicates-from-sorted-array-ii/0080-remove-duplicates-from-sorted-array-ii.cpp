class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,count=1,count1=0;;
        nums[k++]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                if(count1<2){
                    count++;
                count1+=2;
                    nums[k++]=nums[i];
                }
            }
            else{
                count++;
                nums[k++]=nums[i];
                count1=0;
                
            }
        }
        return count;
        
    }
};