class Solution {
public:
   int giveans(const std::vector<std::vector<int>>& grid, int idx, int jdx, int pr, std::vector<std::vector<int>>& memo) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Boundary and value check
    if (idx < 0 || jdx < 0 || idx >= m || jdx >= n || grid[idx][jdx] <= pr) {
        return 0;
    }
    
    // Check if result is already calculated
    if (memo[idx][jdx] != -1) {
        return memo[idx][jdx];
    }
    
    int first = 0, second = 0, third = 0;
    int currentValue = grid[idx][jdx];
    
    // Explore top-right, right, and bottom-right directions
    first = 1 + giveans(grid, idx - 1, jdx + 1, currentValue, memo);     // Move top-right
    second = 1 + giveans(grid, idx, jdx + 1, currentValue, memo);         // Move right
    third = 1 + giveans(grid, idx + 1, jdx + 1, currentValue, memo);      // Move bottom-right
    
    // Store the result in memo and return
       int k=max(first,max(second, third));
    memo[idx][jdx] =k;
    return memo[idx][jdx];
}

int maxMoves(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    // Initialize memoization table with -1 (indicating uncomputed)
    std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));

    // Try starting from each cell in the first column
    for (int i = 0; i < m; i++) {
        ans = std::max(ans, giveans(grid, i, 0, -1, memo)-1);  // Start with a value less than any in grid
    }

    return ans;
}
};