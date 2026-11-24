class Solution {
public:
    int solve(vector<int>& prices, int n, int i, int k, vector<vector<int>>& dp) {
        if (i == n || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k == 2) { 
            int c1 = solve(prices, n, i + 1, k - 1, dp) - prices[i];
            int c2 = solve(prices, n, i + 1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
        else { 
            int c1 = solve(prices, n, i + 1, 2, dp) + prices[i];
            int c2 = solve(prices, n, i + 1, k, dp);
            return dp[i][k] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));

        return solve(prices, n, 0, 2, dp);
    }
};