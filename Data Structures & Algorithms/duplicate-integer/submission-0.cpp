class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for (auto i:nums) {
            map[i]++;
            if (map[i]>1) return true;
        }
        for (auto i:nums) {
            if (map[i]>1) return true;
        }
        return false;
    }
};