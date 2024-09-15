class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = nums[0];
        int maxLen = 1;
        int currentLen = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxLen = 1;
                currentLen = 1;
            } else if (nums[i] == maxVal) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }

        return maxLen;
    }
};