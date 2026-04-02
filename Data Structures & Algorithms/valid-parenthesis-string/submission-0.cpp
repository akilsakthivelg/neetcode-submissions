class Solution {
public:
    bool checkValidString(string s) {
         int lmin,lmax;
         lmin=lmax=0;
         for (auto x:s)  {
            if (x=='(') {
                lmin++;
                lmax++;
            } else if (x==')') {
                lmax--;
                lmin--;
            } else {
                lmin--;
                lmax++;
            }
            if (lmin<0) lmin=0;
            if (lmax<0) return false;
         }
         return lmin==0;
    }
};
