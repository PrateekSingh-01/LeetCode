class Solution {
public:
    void dfs(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        for (Node* child : root->children) {
            dfs(child, ans);
        }

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};