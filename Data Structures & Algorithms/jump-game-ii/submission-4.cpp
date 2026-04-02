class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int c=0;
        while (l<n-1) {
            r=l+nums[l];
            int k=0;
            int m=l+1;
            for (int i=m;i<=r && i<n;i++) {
                if (nums[m]<=nums[i]+k) m=i;
                if (i==n-1) m=i;
                k++;
            }
            c++;
            l=m;
        }
        return c;
    }
};
