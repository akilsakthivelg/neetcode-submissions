class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for (int i=0;i<n;i++) {
            if (i!=0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int l=i+1,r=nums.size()-1;
            while (l<r) {
                if (l!=i+1 && nums[l]==nums[l-1]) {
                    l++;
                    continue;
                }
                int s=nums[l]+nums[r];
                if (s==target) ans.push_back({nums[i],nums[l++],nums[r--]});
                else if (s<target) l++;
                else r--;
            }
        }
        return ans;
    }
};
