class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int s=newInterval[0];
        int e=newInterval[1];
        bool done=false;
        for (auto x:intervals) {
            if (s>x[1]) {
                ans.push_back(x);
                continue;
            }
            if (e<x[0]) {
                if (!done) {
                    ans.push_back({s,e});
                    done=true;
                }
                ans.push_back(x);
                continue;
            }
            s=min(s,x[0]);
            if (e<=x[1]) {
                ans.push_back({s,x[1]});
                done = true;
            }
        }
        if (!done) ans.push_back({s,e});
        return ans;
    }
};
