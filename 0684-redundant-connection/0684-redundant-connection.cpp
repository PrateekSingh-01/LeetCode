class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUparent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUparent(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (ds.findUparent(u) == ds.findUparent(v))
                return {u, v};

            ds.unionbyrank(u, v);
        }

        return {};
    }
};
