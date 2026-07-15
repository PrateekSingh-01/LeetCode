class Solution {
public:
    int ans = 0;
    int maxDepth = -1;

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr)
            return;

        if (depth > maxDepth) {
            maxDepth = depth;
            ans = root->val;
        }

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};