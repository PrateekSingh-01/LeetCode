class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return {};

        unordered_map<int, int> freq;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            freq[node->val]++;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        int maxFreq = 0;

        for (auto &it : freq) {
            maxFreq = max(maxFreq, it.second);
        }

        vector<int> ans;

        for (auto &it : freq) {
            if (it.second == maxFreq)
                ans.push_back(it.first);
        }

        return ans;
    }
};