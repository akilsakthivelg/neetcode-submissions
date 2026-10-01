class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=0;
        n--;
        vector<int> xa(64) , na(64);
        for (int i=0;i<32;i++) {
            xa[i]=(x>>i)&1;
            na[i]=(n>>i)&1;
        }
        int ix=0,in=0;

        while (ix<63) {
            while (ix<63 && xa[ix]!=0) ix++;
            xa[ix]=na[in];
            ix++,in++;
        }

        for (int i=0;i<64;i++) {
            if (xa[i]==1) {
                ans|=(1ll<<i);
            }
        }
        return ans;
    }
};