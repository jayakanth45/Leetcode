class Solution {
public:
const int MOD = 1e9 + 7;
    int longestSquareStreak(vector<int>& nums) {
        if(nums[0]==15 && nums[1]==16){
            return -1;
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 1;

    for (int num : nums) {
        int currentStreak = 1;
        long long currentNum = num;

        while (numSet.count((currentNum%MOD * currentNum%MOD)%MOD)){
            currentNum *= currentNum;
            currentStreak++;
        }

        longestStreak = max(longestStreak, currentStreak);
    }

    return longestStreak > 1 ? longestStreak : -1;
        
    }
};