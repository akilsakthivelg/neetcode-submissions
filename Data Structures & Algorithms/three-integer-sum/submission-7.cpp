class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++) {
            if (i!=0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int j=i+1;
            int k=n-1;
            while (j<k) {
                if (j!=i+1 && nums[j]==nums[j-1]) {
                    j++;
                    continue;
                }
                if (k!=n-1 && nums[k]==nums[k+1]) {
                    k--;
                    continue;
                }
                int val = nums[j]+nums[k];
                if (val==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if (val>target) k--;
                else j++;
            }
        }
        return ans;
    }
};
