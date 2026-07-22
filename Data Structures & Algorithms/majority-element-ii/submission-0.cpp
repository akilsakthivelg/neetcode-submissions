class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for (auto x:nums) m[x]++;
        vector<int> ans;
        int n=nums.size();
        for (auto x:m) {
            if (x.second>n/3) ans.push_back(x.first);
        }
        return ans;
    }
};