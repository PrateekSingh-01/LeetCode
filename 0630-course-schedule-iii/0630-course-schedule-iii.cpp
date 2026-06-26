class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq; 
        int currDay = 0;

        for (auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            currDay += duration;
            pq.push(duration);

        
            if (currDay > lastDay) {
                currDay -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};