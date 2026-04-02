class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        int lmax=height[i],rmax=height[j];
        while (i<j) {
            if (lmax<rmax) {
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
