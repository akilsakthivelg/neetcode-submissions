class Solution {
public:

    unordered_map<int,int> cache;

    int helper(vector<int>& nums,int target) {
        if (target==0) return 1;
        if (cache.count(target)) return cache[target];
        int ans=0;
        for (auto x:nums) {
            if (x>target) continue;
            ans+=helper(nums,target-x);
        }
        cache[target]=ans;
        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return helper(nums,target);
    }
};