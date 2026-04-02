class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix.size()*matrix[0].size()-1;
        int c=matrix[0].size();
        while (i<=j) {
            int mid=i+(j-i)/2;
            if (target == matrix[mid/c][(mid%c)]) return true;
            else if (target < matrix[mid/c][mid%c]) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};
