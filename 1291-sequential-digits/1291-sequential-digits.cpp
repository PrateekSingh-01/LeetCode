class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for (int len = lowLen; len <= highLen; len++) {

           
            int num = 0;
            for (int i = 1; i <= len; i++) {
                num = num * 10 + i;
            }

     
            int maxStart = 10 - len;

            for (int start = 1; start <= maxStart; start++) {

                if (num >= low && num <= high)
                    ans.push_back(num);

                int next = 0;
                for (int d = start + 1; d <= start + len; d++) {
                    next = next * 10 + d;
                }
                num = next;
            }
        }

        return ans;
    }
};