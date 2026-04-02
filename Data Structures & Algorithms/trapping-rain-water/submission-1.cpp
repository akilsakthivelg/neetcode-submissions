class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int i=0;
        int j=n-1;
        int lmax=height[i];
        int rmax=height[j];
        while (i<j) {
            if (lmax < rmax) {
                i++;
                lmax=max(lmax,height[i]);
                ans+=lmax-height[i];
            } else {
                j--;
                rmax=max(rmax,height[j]);
                ans+=rmax-height[j];
            }
        }
        return ans;
    }
};
