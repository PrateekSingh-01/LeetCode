
class Solution {
public:
    TreeNode* t1 = NULL;
    TreeNode* t2 = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);

        if (prev != NULL && prev->val > root->val) {
            if (t1 == NULL) {
                t1 = prev;
            }
            t2 = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t1->val, t2->val);
    }
};
