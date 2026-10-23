class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;

        for (int n : nums) {
            string ans = "";

            while (n > 0) {
                int k = min(25, 31 - __builtin_clz(n));

                ans += char('a' + k);
                n -= (1 << k);
            }

            res.push_back(ans);
        }

        return res;
    }
};