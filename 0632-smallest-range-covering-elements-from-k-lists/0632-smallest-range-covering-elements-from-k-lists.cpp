class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int maxi = INT_MIN;

    
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (true) {
            auto cur = pq.top();
            pq.pop();

            int mini = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            if (col + 1 == nums[row].size())
                break;

            int nextVal = nums[row][col + 1];
            pq.push({nextVal, row, col + 1});
            maxi = max(maxi, nextVal);
        }

        return {start, end};
    }
};