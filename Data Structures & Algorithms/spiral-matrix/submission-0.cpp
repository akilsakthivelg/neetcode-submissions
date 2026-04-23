class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int rs,re,cs,ce;
        rs=0;
        re=n-1;
        cs=0;
        ce=m-1;
        vector<int> ans;
        while (rs<=re && cs<=ce) {
            if (rs==re) {
                for (int i=cs;i<=ce;i++) {
                    ans.push_back(matrix[rs][i]);
                }
            }
            else if (cs==ce) {
                for (int i=rs;i<=re;i++) {
                    ans.push_back(matrix[i][cs]);
                }
            }
            else {
                for (int i=cs;i<=ce;i++) {
                    ans.push_back(matrix[rs][i]);
                }
                for (int i=rs+1;i<re;i++) {
                    ans.push_back(matrix[i][ce]);
                }
                for (int i=ce;i>=cs;i--) {
                    ans.push_back(matrix[re][i]);
                }
                for (int i=re-1;i>rs;i--) {
                    ans.push_back(matrix[i][cs]);
                }
            }
            rs++;
            cs++;
            re--;
            ce--;
        }
        return ans;
    }
};
