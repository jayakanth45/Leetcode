class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;

        vector<int> subarray;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum = (sum + nums[j]) % mod;
                subarray.push_back(sum);
            }
        }

        sort(begin(subarray), end(subarray));

        long long ans = 0;
        for(int i = left; i <= right; ++i) {
            ans = (ans + subarray[i - 1]) % mod;
        }

        return ans;
    }
};