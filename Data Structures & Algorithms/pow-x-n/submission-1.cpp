class Solution {
public:

    double pow(double x,int n) {
        if (n==0) return 1;
        if (n==1) return x;
        return pow(x,n/2)*pow(x,n/2+n%2);
    }

    double myPow(double x, int n) {
        if (x==1) return 0; 
        if (n==1) return x;
        double res=1;
        long power = abs(n);
        double ans = pow(x,power);
        if (n<0) return 1/ans;
        return ans;
    }
};