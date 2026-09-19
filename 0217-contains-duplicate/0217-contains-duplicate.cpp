class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1){
                return true;
            }
            
            
        }
        return false;
    }
};