class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& vis) {
        vis[node] = true;

        for(int i = 0; i < isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && !vis[i]) {
                dfs(isConnected, i, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> vis(n, false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(isConnected, i, vis);
                count++;
            }
        }

        return count;
    }
};