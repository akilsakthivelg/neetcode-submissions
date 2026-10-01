class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1=nums[0];
        int csum1=nums[0];
        int n=nums.size();
        for (int i=1;i<n;i++) {
            csum1=min(nums[i],csum1+nums[i]);
            sum1=min(csum1,sum1);
        }
        
        int sum2=nums[0];
        int csum2=nums[0];
        for (int i=1;i<n;i++) {
            csum2=max(nums[i],csum2+nums[i]);
            sum2=max(csum2,sum2);
        }
        int tot = accumulate(nums.begin(),nums.end(),0);
        bool pos = false;
        for (auto &x : nums) if (x>=0) pos = true;
        if (pos) return max(tot-sum1,sum2);
        return sum2;

    }
};