class Solution {
public:
    int reverse(int x) {
        if (x==INT_MIN) return 0;
        long long ans=0;
        int neg=1;
        if (x<0) neg=-1;
        x=abs(x);
        while (x>0) {
            ans=ans*10+(x%10);
            x/=10;
        }
        if (ans>INT_MAX || ans<INT_MIN) return 0;
        return ans*neg;
    }
};
