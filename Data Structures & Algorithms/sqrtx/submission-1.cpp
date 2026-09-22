class Solution {
public:
    int mySqrt(int x) {
        int i=1,j=x;
        int ans=0;
        while (i<=j) {
            int m=i+(j-i)/2;
            if (1ll*m*m<=x) {
                ans=m;
                i=m+1;
            }
            else j=m-1;
        }
        return ans;
    }
};