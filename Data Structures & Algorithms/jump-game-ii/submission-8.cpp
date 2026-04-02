class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r;
        int n=nums.size();
        int c=0;
        while (l<n-1) {
            r=l+nums[l];
            int m=l+1;
            if (r>=n-1) m=r;
            else
                for (int i=m;i<=r;i++) {
                    if (nums[m]+m<=nums[i]+i) m=i;
                }
            c++;
            l=m;
        }
        return c;
    }
};
