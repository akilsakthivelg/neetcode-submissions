class Solution {
public:

    set<vector<int>> ans_set;
    void helper(int i,vector<int> temp,vector<int>& nums) {
        if (i==nums.size()) {
            ans_set.insert(temp);
            return;
        }
        helper(i+1,temp,nums);
        temp.push_back(nums[i]);
        helper(i+1,temp,nums);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans_set={};
        vector<int> temp={};
        helper(0,temp,nums);
        vector<vector<int>> ans;
        for (auto x:ans_set) ans.push_back(x);
        return ans;
    }
};
