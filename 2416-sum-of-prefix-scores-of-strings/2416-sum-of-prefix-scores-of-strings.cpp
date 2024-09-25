class Solution {
public:
    vector<int> sumPrefixScores(const vector<string>& words) {
        int n = words.size();
        vector<string_view> sorted;
        sorted.reserve(n);
        for (string_view w : words) sorted.push_back(w);
        sort(sorted.begin(), sorted.end());
        vector<int> ans;
        ans.reserve(words.size());

        for (string w : words) {
            int wl = w.length();
            auto lb = sorted.begin(), ub = sorted.end();
            int total = 0;
            string_view wv = w;
            for (int i = 1; i <= wl; ++i) {
                auto& lc = w[i -1];
                string_view prefix = wv.substr(0, i);
                lb = lower_bound(lb, ub, prefix);
                ++lc;
                ub = lower_bound(lb, ub, prefix);
                --lc;
                total += ub - lb;
            }
            ans.push_back(total);
        }
        return ans;
    }
};