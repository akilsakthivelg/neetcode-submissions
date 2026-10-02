class Solution {
public:

    bool helper(int i,vector<int>& m,vector<int>& sides,int t) {
        if (i==m.size()) return true;

        for (int j=0;j<4;j++) {
            if (sides[j]+m[i]<=t) {
                sides[j]+=m[i];
                if (helper(i+1,m,sides,t)) return true;
                sides[j]-=m[i];
            }
            if (sides[j]==0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& m) {
        int sum=accumulate(m.begin(),m.end(),0);
        if (sum%4) return false;
        sort(m.rbegin(),m.rend());
        vector<int> sides(4);
        return helper(0,m,sides,sum/4);
    }
};