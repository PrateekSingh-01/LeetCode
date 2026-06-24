class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<vector<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                pq.push({-(i + j), i, nums[i][j]});
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top()[2]);
            pq.pop();
        }

        return ans;
    }
};