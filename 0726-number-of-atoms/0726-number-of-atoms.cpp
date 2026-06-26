class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});

        int n = formula.size();

        for (int i = 0; i < n;) {

            if (formula[i] == '(') {
                st.push({});
                i++;
            }

            else if (formula[i] == ')') {
                i++;

                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;

                auto cur = st.top();
                st.pop();

                for (auto &it : cur) {
                    st.top()[it.first] += it.second * num;
                }
            }

            else {
                
                string atom;
                atom += formula[i++];
                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }

            
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;

                st.top()[atom] += num;
            }
        }

        string ans;

        for (auto &it : st.top()) {
            ans += it.first;
            if (it.second > 1)
                ans += to_string(it.second);
        }

        return ans;
    }
};