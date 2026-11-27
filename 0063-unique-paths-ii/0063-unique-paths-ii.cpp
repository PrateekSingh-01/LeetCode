class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();

        if (i >= m || j >= n)
            return 0;

        if (grid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int c1 = solve(i, j + 1, grid, dp);
        int c2 = solve(i + 1, j, grid, dp);

        return dp[i][j] = c1 + c2;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};