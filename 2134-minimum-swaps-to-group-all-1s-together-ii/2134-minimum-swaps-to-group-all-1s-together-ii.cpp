class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n=nums.size();
        int ones=0;
     
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ones++;
            }
        }
       
        if(ones==n || ones==0){
            return 0;
        }

       
        int minSwaps=0;
        int swaps=0;
        for(int i=0;i<ones;i++){
            if(nums[i]==0){
                minSwaps++;
                swaps++;
            }
        }

       
        int i=0,j=ones;
        while(i<n){
            
            if(nums[i]==0){
                swaps--;
            }
          
            if(nums[j]==0){
                swaps++;
            }

            minSwaps=min(minSwaps,swaps);

            i++;
            j=(j+1)%n;
        }

        return minSwaps;
        
    }
};