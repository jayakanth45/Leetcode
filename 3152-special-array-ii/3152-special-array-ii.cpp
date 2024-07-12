class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       vector<int> sum(nums.size(),0);
    int sum1 = 0;

   
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] % 2 == nums[i + 1] % 2) {
            nums[i] = 1; 
        } else {
            nums[i] = 0; 
        }
        sum1 += nums[i];
        sum[i] = sum1;
    }


    sum[nums.size() - 1] = sum1;

    
    vector<bool> ans;
    for(int i = 0; i < queries.size(); i++) {
        int a = queries[i][0], b = queries[i][1];
        if(a==b){
            ans.push_back(true);
        }
        else if(a > 0 && b>0) {
            if(sum[b-1] - sum[a - 1] == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        } else {
            if(sum[b-1] == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
    }

    return ans;
        
    }
};