class Solution {
public:
    int maxD = 0;

    void dfs(Node* root, int depth) {
        if (!root) return;

        maxD = max(maxD, depth);

        for (Node* child : root->children) {
            dfs(child, depth + 1);
        }
    }

    int maxDepth(Node* root) {
        if (!root) return 0;

        dfs(root, 1);
        return maxD;
    }
};