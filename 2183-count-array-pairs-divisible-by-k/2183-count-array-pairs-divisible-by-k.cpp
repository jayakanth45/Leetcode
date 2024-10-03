class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
       unordered_map<int, int> remainder_count;
    int n = nums.size();
    long long count = 0;

    for (int num : nums) {
        long long gcd_num = gcd(num, k);
        for (auto& [gcd_other, freq] : remainder_count) {
            if ((gcd_num * gcd_other) % k == 0) {
                count += freq;
            }
        }
        remainder_count[gcd_num]++;
    }

    return count;
        
    }
};