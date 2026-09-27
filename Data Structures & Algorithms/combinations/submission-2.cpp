class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> a(k,0);
        int i=0;

        while (i>=0) {
            a[i]++;
            if (a[i]>n) {
                i--;
                continue;
            }
            if (i==k-1) {
                ans.push_back(a);
            } else {
                i++;
                a[i]=a[i-1];
            }
        }
        return ans;
    }
};