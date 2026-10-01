class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if (s[n-1]=='1') return false;
        vector<int> canJump(n);
        canJump[0]=true;
        int i=0;
        for (int j=0;j<n;j++) {
            if (!canJump[j]) continue;
            i=max(i,j+minJump);
            while (i<n && i<=j+maxJump) {
                if (s[i]=='0') canJump[i]=true;
                i++;
            }
        }
        return canJump[n-1];
    }
};