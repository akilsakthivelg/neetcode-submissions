class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r;
        int n=nums.size();
        int c=0;
        while (l<n-1) {
            r=l+nums[l];
            int k=0;
            int m=l+1;
            if  (r>=n-1) m=r;
            else
                for (int i=m;i<=r && i<n;i++) {
                    if (nums[m]<=nums[i]+k) m=i;
                    k++;
                }
            c++;
            l=m;
        }
        return c;
    }
};
