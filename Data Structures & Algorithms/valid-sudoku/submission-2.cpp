class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int row[10]={0};
        int col[10]={0};
        int box[10]={0};

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if ((b[i][j])=='.') continue;
                int n= b[i][j]-'1';
                int bit= 1<<n;
                int bi= (i/3)*3+(j/3);
                if (row[i]&bit) return false;
                if (col[j]&bit) return false;
                if (box[bi]&bit) return false;
                row[i]|=bit;
                col[j]|=bit;
                box[bi]|=bit;
            }
        }
        return true;
    }
};
