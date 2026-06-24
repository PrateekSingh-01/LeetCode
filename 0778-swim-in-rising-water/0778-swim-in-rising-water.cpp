class Solution {
public:
    int n;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    bool dfs(int r, int c, int t,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        if (r < 0 || c < 0 || r >= n || c >= n)
            return false;

        if (vis[r][c] || grid[r][c] > t)
            return false;

        if (r == n - 1 && c == n - 1)
            return true;

        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            if (dfs(r + dr[k], c + dc[k], t, grid, vis))
                return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int low = max(grid[0][0], grid[n - 1][n - 1]);
        int high = n * n - 1;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            vector<vector<int>> vis(n, vector<int>(n, 0));

            if (dfs(0, 0, mid, grid, vis)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};