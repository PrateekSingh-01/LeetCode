class Solution {
public:
    vector<int> keys;
    vector<int> gain;
    vector<int> dp;

    int solve(int idx) {
        if (idx >= keys.size()) return 0;

        if (dp[idx] != -1) return dp[idx];

    
        int skip = solve(idx + 1);

        
        int x = keys[idx];
        int take = gain[idx];

    
        int nextIdx = upper_bound(keys.begin(), keys.end(), x + 1) - keys.begin();

        take += solve(nextIdx);

        return dp[idx] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto& [x, f] : freq) {
            keys.push_back(x);
        }

        sort(keys.begin(), keys.end());

        for (int x : keys) {
            gain.push_back(x * freq[x]);
        }

        dp.assign(keys.size(), -1);

        return solve(0);
    }
};