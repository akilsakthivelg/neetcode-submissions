class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long p = 1;
        int z=0;
        for (auto x:nums) {
            if (x) p*=x;
            else z++;
        }
        vector<int> ans;
        for (auto x:nums) {
            if (z>1) {
                ans.push_back(0);
            } else if (x) {
                if (z) ans.push_back(0);
                else ans.push_back(p/x);
            } else ans.push_back(p);
        }
        return ans;
    }
};
