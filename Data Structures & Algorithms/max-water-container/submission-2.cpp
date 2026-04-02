class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int mA=0;
        int i=0,j=n-1;
        while (i<j) {
            mA=max(mA,min(heights[i],heights[j])*(j-i));
            if (heights[i]<heights[j]) i++;
            else j--;
        }
        return mA;
    }
};
