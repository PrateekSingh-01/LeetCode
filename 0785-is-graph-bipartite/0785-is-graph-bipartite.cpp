
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node,
             vector<int>& color) {

        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];

            if (color[neigh] == -1) {
                color[neigh] = 1 - color[node];

                if (!dfs(graph, neigh, color))
                    return false;
            }
            else if (color[neigh] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;

                if (!dfs(graph, i, color))
                    return false;
            }
        }

        return true;
    }
};
