class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans = arr;

        for (int x : arr) {
            pq.push(x);
        }

        unordered_map<int, int> mp;
        int rank = 1;

        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            if (mp.find(curr) == mp.end()) {
                mp[curr] = rank;
                rank++;
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            ans[i] = mp[ans[i]];
        }

        return ans;
    }
};