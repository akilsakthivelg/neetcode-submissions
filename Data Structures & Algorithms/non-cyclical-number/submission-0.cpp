class Solution {
public:
    int sumOfSquares(int n) {
        int s=0;
        while (n>0) {
            s+=(n%10)*(n%10);
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_map<int,int> a;
        while (a[n]==0) {
            a[n]++;
            n=sumOfSquares(n);
            if (n==1) return true;
        }
        return false;
    }
};
