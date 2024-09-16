class Solution {
private:
    int timeDifferenceCal(string& s1, string& s2) {
        int h1 = (s1[0] - '0') * 10 + (s1[1] - '0'),
            m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
        int h2 = (s2[0] - '0') * 10 + (s2[1] - '0'),
            m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
        int diff = (h1 - h2) * 60 + (m1 - m2);
        return min(diff, 1440 - diff);
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int mn = INT_MAX;
        for (int i = 1; i < n; i++) {
            mn = min(mn, timeDifferenceCal(timePoints[i], timePoints[i - 1]));
        }
        mn=min(mn, timeDifferenceCal(timePoints[n-1], timePoints[0]));
        return mn;
    }
};