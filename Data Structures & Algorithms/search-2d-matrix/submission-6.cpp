class Solution {
public:

    bool find(vector<int>& arr,int target) {
        int i=0,j=arr.size()-1;
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (arr[mid]==target) return true;
            else if (arr[mid]<target) i=mid+1;
            else j=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix.size()-1;
        int n=matrix.size(),m=matrix[0].size();
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (matrix[mid][0]<=target && matrix[mid][m-1]>=target) return find(matrix[mid],target);
            else if (matrix[mid][0]>target) j=mid-1;
            else i=mid+1;
        }
        return false;
        
    }
};
