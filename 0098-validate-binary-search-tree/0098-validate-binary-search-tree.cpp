
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

        return is_sorted(res.begin(), res.end()) &&
               adjacent_find(res.begin(), res.end()) == res.end();
    }
};
