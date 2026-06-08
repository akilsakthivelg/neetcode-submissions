class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn=1,mx=1;
        int ans=nums[0];
        for (auto x:nums) {
            int new_mn = min({x,x*mn,x*mx});
            int new_mx = max({x,x*mn,x*mx});
            mx=new_mx,mn=new_mn;
            ans=max(ans,mx);
        }
        return ans;
    }
};