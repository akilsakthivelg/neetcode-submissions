class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1);
        for (int i=0;i<n;i++) {
            prefix[i+1]=prefix[i]+nums[i];
        }
        int ans=0;
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<=n;j++) {
                if (prefix[j]-prefix[i] == k) ans++;
            }
        }
        return ans;
    }
};