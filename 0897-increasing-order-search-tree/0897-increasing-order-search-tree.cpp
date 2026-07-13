class Solution {
public:
    vector<TreeNode*> inorder;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        inorder.push_back(root);
        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);

        for (int i = 0; i < inorder.size() - 1; i++) {
            inorder[i]->left = nullptr;
            inorder[i]->right = inorder[i + 1];
        }

        inorder.back()->left = nullptr;
        inorder.back()->right = nullptr;

        return inorder[0];
    }
};