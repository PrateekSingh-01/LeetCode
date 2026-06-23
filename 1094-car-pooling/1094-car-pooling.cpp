class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1]; 
             });

        
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        int leftCap = capacity;

        for (auto &trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

        
            while (!pq.empty() && pq.top().first <= start) {
                leftCap += pq.top().second;
                pq.pop();
            }

            if (leftCap < passengers)
                return false;

            leftCap -= passengers;
            pq.push({end, passengers});
        }

        return true;
    }
};