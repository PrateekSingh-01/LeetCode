class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string res = "";
        char curr = '#';

        while (!pq.empty()) {

            auto top1 = pq.top();
            pq.pop();

            if (top1.second != curr) {
                res += top1.second;
                curr = top1.second;

                top1.first--;

                if (top1.first > 0) {
                    pq.push(top1);
                }
            }

    
            else {
                if (pq.empty()) {
                    return "";
                }

                auto top2 = pq.top();
                pq.pop();

                res += top2.second;
                curr = top2.second;

                top2.first--;

                if (top2.first > 0) {
                    pq.push(top2);
                }

            
                pq.push(top1);
            }
        }

        return res;
    }
};