class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n=nums.size();
        int ones=0;
        // Count the number of 1s in the array
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ones++;
            }
        }
        // Edge case: if there are no 1s or all are 1s, no swaps needed
        if(ones==n || ones==0){
            return 0;
        }

        // First window: count the number of 0s in the first window of size `ones`
        int minSwaps=0;
        int swaps=0;
        for(int i=0;i<ones;i++){
            if(nums[i]==0){
                minSwaps++;
                swaps++;
            }
        }

        // Sliding window
        int i=0,j=ones;
        while(i<n){
            // Remove the leftmost element
            if(nums[i]==0){
                swaps--;
            }
            // Add the next element in the array to the window
            if(nums[j]==0){
                swaps++;
            }

            minSwaps=min(minSwaps,swaps);

            i++;
            j=(j+1)%n;// Use modulo to wrap around the array
        }

        return minSwaps;
        
    }
};