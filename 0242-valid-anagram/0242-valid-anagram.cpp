class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char,int>s1;
        for(char c : s){
            s1[c]++;
        }
        for(char c : t){
            s1[c]--;
        }
        for (auto &it : s1) {
            if (it.second != 0)
                return false;
        }

        return true;


    }
};