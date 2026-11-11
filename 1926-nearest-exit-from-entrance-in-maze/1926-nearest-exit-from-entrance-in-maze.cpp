
class Solution {
public:
    bool valid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int sr = entrance[0];
        int sc = entrance[1];

        q.push({sr, sc});
        vis[sr][sc] = true;

        int dist = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                
                if ((x == 0 || y == 0 || x == n-1 || y == m-1)
                    && !(x == sr && y == sc)) {
                    return dist;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (valid(nx, ny, n, m) &&
                        maze[nx][ny] == '.' &&
                        !vis[nx][ny]) {

                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            dist++;
        }

        return -1;
    }
};
