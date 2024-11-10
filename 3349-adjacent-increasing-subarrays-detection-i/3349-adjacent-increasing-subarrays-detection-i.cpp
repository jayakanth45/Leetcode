class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),count=0,flag=0;
        if(k==1 && n>1){
            return true;
        }
       for(int i=0;i<n;i++){
           flag=0;
           count=0;
           for(int j=i+1;j<i+2*k && j<n;j++){
               if(nums[j]>nums[j-1]){
                   count++;
               }
               if(flag && count+1==k){
                   cout<<i<<endl;
                   return true;
               }
               if(count+1==k){
                   j+=1;
                   flag=1;
                   count=0;
               }
           }
         
       }
        return false;
    }
};