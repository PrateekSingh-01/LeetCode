class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();
        vector<long long> suffix(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        int count = 0;

        for(int i = 0; i < n - 1; i++) {
            if(1LL * nums[i] * (n - i - 1) > suffix[i + 1]) {
                count++;
            }
        }

        return count;
    }
};