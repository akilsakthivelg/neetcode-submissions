class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> ans;
        for (int i=0;i<n;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int t=-nums[i];
            int l=0,r=n-1;
            if (l==i) l++;
            if (r==i) r--;
            while (l<r) {
                if (nums[l]+nums[r]==t) {
                    vector<int> a = {nums[l],nums[i],nums[r]};
                    sort(a.begin(),a.end());
                    ans.insert(a);
                    l++;
                    r--;
                } else if (nums[l]+nums[r]>t) {
                    r--;
                } else {
                    l++;
                }
                if (l==i) l++;
                if (r==i) r--;
            }

        }
        vector<vector<int>> vec_ans;
        for (auto x:ans) vec_ans.push_back(x);
        return vec_ans;
    }
};
