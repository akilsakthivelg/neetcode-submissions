class Solution {
public:

    vector<vector<int>> ans;

    void helper(int i,vector<int>& nums) {
        if (i==nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int j=i;j<nums.size();j++) {
            if (used.count(nums[j])) continue;
            used.insert(nums[j]);
            swap(nums[i],nums[j]);
            helper(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(0,nums);
        return ans;
    }
};