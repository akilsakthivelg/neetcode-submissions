class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for (int i=0;i<n-2;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int t=-nums[i];
            int l=i+1,r=n-1;
            while (l<r) {
                if (nums[l]+nums[r]==t) {
                    vector<int> a = {nums[i],nums[l],nums[r]};
                    ans.push_back(a);
                    l++;
                    r--;
                    while (l<r && nums[l-1]==nums[l]) l++;
                    while (l<r && nums[r]==nums[r+1]) r--;
                } else if (nums[l]+nums[r]>t) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
