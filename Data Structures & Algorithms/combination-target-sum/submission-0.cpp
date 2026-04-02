class Solution {
public:

    void helper(vector<int>& a,int i,int sum,int t,vector<int>& temp,vector<vector<int>>& ans) {
        if (i==a.size()) {
            if (sum==t) ans.push_back(temp);
            return;
        }
        if (sum==t) {
            ans.push_back(temp);
            return;
        }
        if (sum>t) return;
        temp.push_back(a[i]);
        helper(a,i,sum+a[i],t,temp,ans);
        temp.pop_back();
        helper(a,i+1,sum,t,temp,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,0,0,target,temp,ans);
        return ans;
    }
};
