class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string str;
        int sum = 0;

        for (char c : s) {
            if (c != '0') {
                str.push_back(c);
                sum += c - '0';
            }
        }

        if (str.empty())
            return 0;

        long long num = stoll(str);
        return num * sum;
    }
};