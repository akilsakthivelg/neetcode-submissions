class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> ans;
        for (int i=0;i<strs.size();i++) {
            string e=strs[i];
            sort(e.begin(),e.end());
            if (map.find(e)==map.end()) {
                map[e]={strs[i]};
            } else {
                map[e].push_back(strs[i]);
            }
        }
        for (auto k : map) {
            ans.push_back(k.second);
        }
        return ans;
    }
};
