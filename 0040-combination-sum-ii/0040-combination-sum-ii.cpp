class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size() || target < 0)
            return;

        
        temp.push_back(candidates[idx]);
        solve(idx + 1, candidates, target - candidates[idx]);
        temp.pop_back();

        
        int next = idx + 1;
        while (next < candidates.size() &&
               candidates[next] == candidates[idx])
            next++;

        solve(next, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return ans;
    }
};