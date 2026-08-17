class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for (int i=0;i<k;i++) {
            if (m[nums[i]]) return true;
            m[nums[i]]++;
        }
        for (int i=0;i<n-k;i++) {
            if (m[nums[i+k]]) return true;
            m[nums[i+k]]++;
            m[nums[i]]--;
        }
        return false;
    }
};