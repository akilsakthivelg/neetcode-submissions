class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> a(n+1,vector<int>(2));
        for (auto x:trust) {
            a[x[0]][0]++;
            a[x[1]][1]++;
        }
        for (int i=1;i<n+1;i++) {
            if (a[i][0]==0 && a[i][1]==n-1) return i;
        }
        return -1;
    }
};