class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;

        int mx = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                prefixGcd.push_back(nums[i]);
            } else {
                prefixGcd.push_back(gcd(mx, nums[i]));
            }
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int low = 0;
        int high = prefixGcd.size() - 1;

        long long ans = 0;

        while (low < high) {
            ans += gcd(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }

        return ans;
    }
};