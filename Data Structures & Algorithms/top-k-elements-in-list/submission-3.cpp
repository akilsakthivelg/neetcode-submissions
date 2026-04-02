class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (auto x:nums) {
            m[x]++;
        }
        map<int,vector<int>> freq;
        for (auto x:m) {
            freq[-x.second].push_back(x.first);
        }
        vector<int> ans;
        for (auto x:freq) {
            for (int i=0;i<x.second.size() && k--;i++) {
                ans.push_back(x.second[i]);
            }
            if (k<=0) break;
        }
        return ans;
    }
};
