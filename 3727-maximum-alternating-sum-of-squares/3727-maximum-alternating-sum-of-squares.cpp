class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long> pq;

        for (int x : nums) {
            long long val = abs((long long)x);
            pq.push(val * val);
        }

        int n = nums.size();
        int positive = (n + 1) / 2;
        long long ans = 0;

        while (!pq.empty()) {
            long long x = pq.top();
            pq.pop();

            if (positive > 0) {
                ans += x;
                positive--;
            } else {
                ans -= x;
            }
        }

        return ans;
    }
};