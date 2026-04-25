class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int csum=nums[0];
        for (int i=1;i<nums.size();i++) {
            csum=max(csum+nums[i],nums[i]);
            sum=max(sum,csum);
        }
        return sum;
    }
};
