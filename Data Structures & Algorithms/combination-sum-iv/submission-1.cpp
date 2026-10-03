class Solution {
public:

    unordered_map<int,int> cache;

    int helper(vector<int>& nums,int target) {
        if (cache.count(target)) {
            return cache[target];
        }
        int ans=0;
        for (auto x:nums) {
            if (x>target) continue;
            ans+=helper(nums,target-x);
        }
        cache[target]=ans;
        return ans;
    } 

    int combinationSum4(vector<int>& nums, int target) {
        cache[0]=1;
        // sort(nums.begin(),nums.end());
        return helper(nums,target);
    }
};