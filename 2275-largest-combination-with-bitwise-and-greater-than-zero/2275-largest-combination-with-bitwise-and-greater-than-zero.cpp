class Solution {
public:
  

int largestCombination(vector<int>& candidates) {
    int max_count = 0;

    // Iterate over each bit position (0 to 31 for 32-bit integers)
    for (int bit = 0; bit < 32; ++bit) {
        int count = 0;

        // Count how many numbers have the current bit set
        for (int num : candidates) {
            if (num & (1 << bit)) {
                count++;
            }
        }

        // Keep track of the maximum count for any single bit position
        max_count = max(max_count, count);
    }

    return max_count;
}
};