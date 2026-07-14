class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> available;

    
        for (char ch : magazine) {
            available[ch]++;
        }

    
        for (char ch : ransomNote) {
            if (available[ch] == 0) {
                return false;
            }
            available[ch]--;
        }

        return true;
    }
};