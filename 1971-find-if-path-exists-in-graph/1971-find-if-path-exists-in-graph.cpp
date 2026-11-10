class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node,
             int destination, vector<bool>& vis) {

        if(node == destination)
            return true;

        vis[node] = true;

        for(int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            if(!vis[neigh]) {
                if(dfs(adj, neigh, destination, vis))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        
        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dest = edges[i][1];

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }


        vector<bool> vis(n, false);

        return dfs(adj, source, destination, vis);
    }
};