class Solution {
public:

    bool search(vector<int> a,int t) {
        int i=0,j=a.size()-1;
        while (i<=j) {
            int mid=i+(j-i)/2;
            if (a[mid]==t) return true;
            else if (a[mid]<t) i=mid+1;
            else j=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto x:matrix) {
            if (target <= *(x.rbegin())) return search(x,target);
        }
        return false;
    }
};
