class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        std::vector<int> buckets(k, 0);
        return backtrack(nums, buckets, target, 0);
    }

private:
    bool backtrack(std::vector<int>& nums, std::vector<int>& buckets, int target, int index) {
        if (index == nums.size()) {
            for (int i = 0; i < buckets.size(); ++i) {
                if (buckets[i] != target) return false;
            }
            return true;
        }
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i] + nums[index] > target) continue;
            buckets[i] += nums[index];
            if (backtrack(nums, buckets, target, index + 1)) return true;
            buckets[i] -= nums[index];
            if (buckets[i] == 0) break;
        }
        return false;
    }
};
