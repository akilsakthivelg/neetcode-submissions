class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=0;
        n--;
        vector<int> xa(64), na(64);
        for (int i=0;i<32;i++) {
            xa[i]=(x>>i)&1;
            na[i]=(n>>i)&1;
        }
        int i=0,j=0;
        while (i<64) {
            while (i<64 && xa[i]!=0) i++;
            if (i<64) xa[i++]=na[j++];
        }
        for (int i=0;i<64;i++) {
            ans|=(((long long)(xa[i]))<<i);
        }
        return ans;
    }
};