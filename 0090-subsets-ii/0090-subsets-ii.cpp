class Solution {
public:
    void solve(int ind, vector<vector<int>>&ans, vector<int>&ds, vector<int>& arr, int n){
        ans.push_back(ds);

        for(int i=ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            solve(i+1, ans, ds, arr, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        solve(0,ans,ds,nums, nums.size());
        return ans;
    }
};