class Solution {
public:
    bool checkValidString(string s) {
        int lmin,lmax;
        lmin=lmax=0;
        for (auto c:s) {
            if (c=='(') {
                lmin++;
                lmax++;
            } else if (c==')') {
                lmin--;
                lmax--;
            } else {
                lmax++;
                lmin--;
            }
            if (lmax<0) return false;
            if (lmin<0) lmin=0;
        }
        return lmin==0;
    }
};
