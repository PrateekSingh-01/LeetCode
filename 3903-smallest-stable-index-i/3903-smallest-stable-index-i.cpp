class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int mx = INT_MIN;


            for (int j = 0; j <= i; j++) {
                mx = max(mx, nums[j]);
            }

            int mn = INT_MAX;

        
            for (int j = i; j < n; j++) {
                mn = min(mn, nums[j]);
            }

            int diff = mx - mn;

            if (diff <= k)
                return i;
        }

        return -1;
    }
};