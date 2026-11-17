class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;

    int fun(TreeNode* root, int free) {
        if (root == NULL) return 0;

        if (dp.count(root) && dp[root][free] != -1)
            return dp[root][free];

        if (!dp.count(root))
            dp[root] = {-1, -1};

        if (free == 0) {
            return dp[root][free] =
                fun(root->left, 1) + fun(root->right, 1);
        }

        int c1 = root->val +
                 fun(root->left, 0) +
                 fun(root->right, 0);

        int c2 = fun(root->left, 1) +
                 fun(root->right, 1);

        return dp[root][free] = max(c1, c2);
    }

    int rob(TreeNode* root) {
        return fun(root, 1);
    }
};