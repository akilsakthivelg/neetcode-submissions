class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (auto x:nums) {
            freq[x]++;
            if (freq[x]==2) return true;
        }
        return false;
    }
};