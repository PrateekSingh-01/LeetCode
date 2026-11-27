class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        if (i == n - 1)
            return matrix[i][j];

        if (dp[i][j] != INT_MIN)
            return dp[i][j];

        int c1 = solve(i + 1, j, matrix, dp);

        int c2 = INT_MAX;
        if (j > 0)
            c2 = solve(i + 1, j - 1, matrix, dp);

        int c3 = INT_MAX;
        if (j < n - 1)
            c3 = solve(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({c1, c2, c3});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, matrix, dp));
        }

        return ans;
    }
};