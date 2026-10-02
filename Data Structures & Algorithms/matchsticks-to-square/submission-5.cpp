class Solution {
public:

    bool helper(int i,vector<int>& m,vector<int>& sides,int l) {
        if (i==m.size()) return true;
        for (int j=0;j<4;j++) {
            if (sides[j]+m[i]<=l) {
                sides[j]+=m[i];
                if (helper(i+1,m,sides,l)) return true;
                sides[j]-=m[i];
            }
            if (sides[j]==0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& m) {
        int t = accumulate(m.begin(),m.end(),0);
        if (t%4) return false;
        sort(m.rbegin(),m.rend());
        vector<int> s(4);
        return helper(0,m,s,t/4);
    }
};