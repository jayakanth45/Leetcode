class Solution {
public:
    int givesum(vector<int>& nums, int idx, int curr_max, int curr_min, int& global_max) {
    if (idx == nums.size()) {
        return global_max;
    }

    int num = nums[idx];

    // Calculate both pick cases: multiplying current max and min by the current element
    int pick_max = max({num,num * curr_max, num * curr_min});
    int pick_min = min({num,num * curr_max, num * curr_min});

    // Update the global max product
    global_max = max(global_max, pick_max);

    // Recursively proceed to the next element
    return givesum(nums, idx + 1, pick_max, pick_min, global_max);
}

int maxProduct(vector<int>& nums) {
    int global_max = nums[0];
    return givesum(nums, 1, nums[0], nums[0], global_max);
}
};