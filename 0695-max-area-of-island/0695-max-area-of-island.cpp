class Solution {
public:

    bool valid(int x, int y, int n, int m) {
        return (x >= 0 && x < n &&
                y >= 0 && y < m);
    }

    int bfs(vector<vector<int>>& grid, int x, int y,
            vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        queue<pair<int,int>> q;

        q.push({x, y});
        vis[x][y] = true;

        int count = 1;

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nx = row + dx[i];
                int ny = col + dy[i];

                if(valid(nx, ny, n, m) &&
                   grid[nx][ny] == 1 &&
                   !vis[nx][ny]) {

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    int count = bfs(grid, i, j, vis);

                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};