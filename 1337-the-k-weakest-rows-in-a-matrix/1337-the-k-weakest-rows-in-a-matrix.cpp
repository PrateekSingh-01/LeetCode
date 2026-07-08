class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int m = mat.size();
        int n = mat[0].size();

    
        for (int i = 0; i < m; i++) {
            int freq = 0;

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    freq++;
            }

            pq.push({freq, i});
        }

        vector<int> ans;

    
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};