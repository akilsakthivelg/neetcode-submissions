class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        for (auto x:nums) freq[x]++;
        map<int,vector<int>> m;
        for (auto x:freq) {
            m[-x.second].push_back(x.first);
        }
        vector<int> ans;
        for (auto x:m) {
            auto t = x.second;
            sort(t.rbegin(),t.rend());
            for (int i=0;i<t.size() && k--;i++) {
                ans.push_back(t[i]);
            }
            if (k<=0) break;
        }
        return ans;
    }
};
