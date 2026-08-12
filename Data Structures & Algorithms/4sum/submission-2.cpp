class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i,j,k,l;
        i=j=k=l=0;
        vector<vector<int>> ans;
        int n=nums.size();
        long long t=target;
        sort(nums.begin(),nums.end());
        while (i<n-3) {
            j=i+1;
            while (j<n-2) {
                k=j+1;
                while (k<n-1) {
                    l=k+1;
                    while (l<n) {
                        if (0ll+nums[i]+nums[j]+nums[k]+nums[l]==target) ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l++;
                        while (l<n && nums[l]==nums[l-1]) l++;
                    }
                    k++;
                    while (k<n && nums[k]==nums[k-1]) k++;
                }
                j++;
                while (j<n && nums[j]==nums[j-1]) j++;
            }
            i++;
            while (i<n && nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};