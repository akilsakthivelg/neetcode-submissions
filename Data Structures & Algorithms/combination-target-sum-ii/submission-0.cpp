class Solution {
public:

    vector<vector<int>> ans;

    void helper(vector<int>& a,int i,int sum,vector<int>& temp,int target) {
        if (sum==target) {
            ans.push_back(temp);
            return;
        }
        if (i>=a.size()) return;
        if (sum>target) return;
        for (int j=i;j<a.size();j++) {
            if (j!=i && a[j]==a[j-1]) continue;
            temp.push_back(a[j]);
            sum+=a[j];
            helper(a,j+1,sum,temp,target);
            sum-=a[j];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        helper(candidates,0,0,temp,target);
        return ans;
    }
};
