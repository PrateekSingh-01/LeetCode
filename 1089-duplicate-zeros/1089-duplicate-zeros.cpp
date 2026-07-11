class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;

        for (int i = 0; i < n && res.size() < n; i++) {
            if (arr[i] == 0) {
                res.push_back(0);
                if (res.size() < n)
                    res.push_back(0);
            } else {
                res.push_back(arr[i]);
            }
        }

        arr = res;
    }
};