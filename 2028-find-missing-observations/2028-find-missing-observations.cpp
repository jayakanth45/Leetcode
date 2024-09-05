class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int currSum = 0;
        for(auto c : rolls) {
            currSum += c;
        }
        int total = m + n;
        int need = total * mean;
        int rem = need - currSum;

        if (rem < n || rem > 6 * n) {
            return {};
        }

        vector<int> ans(n, rem / n);
        int extra = rem % n;

        for (int i = 0; i < extra; i++) {
            ans[i]++;
        }

        return ans;
    }
};