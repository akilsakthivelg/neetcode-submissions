class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        sum.resize(n+1,vector<int>(m+1));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return sum[r2+1][c2+1]-sum[r2+1][c1]-sum[r1][c2+1]+sum[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */