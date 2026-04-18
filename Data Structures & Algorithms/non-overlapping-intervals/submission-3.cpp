class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b) {
            return a[1]<b[1];
        });
        int ans=0;
        int prev_end=INT_MIN;
        for (auto x:intervals) {
            if (x[0]<prev_end) ans++;
            else {
                prev_end=x[1];
            }
        }
        return ans;
    }
};
