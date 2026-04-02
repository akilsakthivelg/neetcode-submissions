class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int row[10]={0};
        int col[10]={0};
        int box[10]={0};

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (b[i][j]!='.') {
                    if ((row[i]>>b[i][j])&1) return false;
                    row[i]|=(1<<b[i][j]);
                }
            }
        }
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (b[j][i]!='.') {
                    if ((col[i]>>b[j][i])&1) return false;
                    col[i]|=(1<<b[j][i]);
                }
            }
        }
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (b[i][j]!='.') {
                    if ((box[(i/3)*3+(j/3)]>>b[i][j])&1) return false;
                    box[(i/3)*3+(j/3)]|=(1<<b[i][j]);
                }
            }
        }
        return true;
    }
};
