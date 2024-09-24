class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int lo = 0, hi = 10, ans = 0;

        auto ok = [&](int k) {
            set<int> s;
            for(int x : arr1) {
                int sz = to_string(x).size();
                if (sz < k) continue;
                while(sz > k) {
                    x /= 10;
                    --sz;
                }
                s.insert(x);
            }
            for(int x : arr2) {
                int sz = to_string(x).size();
                if (sz < k) continue;
                while(sz > k) {
                    x /= 10;
                    --sz;
                }
                if (s.find(x) != s.end()) return true;
            }
            return false;
        };
        
        while(hi >= lo) {
            int mid = (hi + lo) / 2;
            if (ok(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};