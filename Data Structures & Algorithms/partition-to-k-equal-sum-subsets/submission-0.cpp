class Solution {
public:

    bool helper(int i,vector<int>& nums,vector<int>& groups,int t,int k) {
        if (i==nums.size()) return true;
        for (int j=0;j<k;j++) {
            if (groups[j]+nums[i]<=t) {
                groups[j]+=nums[i];
                if (helper(i+1,nums,groups,t,k)) return true;
                groups[j]-=nums[i];
            }
            if (groups[j]==0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%k!=0) return false;
        vector<int> groups(k);
        sort(nums.rbegin(),nums.rend());
        return helper(0,nums,groups,sum/k,k);
    }
};