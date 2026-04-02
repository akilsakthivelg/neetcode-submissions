class Solution {
public:

    void helper(vector<int>& a,int i,vector<int>& temp,vector<vector<int>>& ans) {
        if (i==a.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(a[i]);
        helper(a,i+1,temp,ans);
        temp.pop_back();
        helper(a,i+1,temp,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,0,temp,ans);
        return ans;
    }
};
