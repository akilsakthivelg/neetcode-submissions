class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        for (auto &x:trips) {
            diff[x[1]]+=x[0];
            diff[x[2]]-=x[0];
        }
        for (int i=1;i<1001;i++) diff[i]+=diff[i-1];
        for (auto x:diff) if (x>capacity) return false;
        return true;
    }
};