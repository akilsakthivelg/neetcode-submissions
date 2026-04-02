class Solution {
public:

    void helper(int i,int j,vector<int>& temp,vector<vector<int>>& ans) {
        if (i==j) {
            ans.push_back(temp);
            return;
        }
        for (int k=i;k<=j;k++) {
            swap(temp[k],temp[i]);
            helper(i+1,j,temp,ans);
            swap(temp[k],temp[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;
        helper(0,nums.size()-1,temp,ans);
        return ans;
    }
};
