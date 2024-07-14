class Solution {
public:
   int giveans(vector<vector<int>>& t, int idx, int jdx, vector<vector<int>>& memo) {
    if (idx == t.size()) {
        return 0;
    }
    if (jdx >= t[idx].size()) {
        return INT_MAX;
    }
    
    if (memo[idx][jdx] != -1) {
        return memo[idx][jdx];
    }

 
    int count = t[idx][jdx] + min(giveans(t, idx + 1, jdx, memo), giveans(t, idx+1, jdx + 1, memo));

    memo[idx][jdx] = count;
    return count;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return giveans(triangle, 0, 0, memo);
}
};