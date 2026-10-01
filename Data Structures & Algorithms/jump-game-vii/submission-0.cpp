class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int i=0;
        int n=s.size();
        if (s[n-1]!='0') return false;
        vector<bool> canJump(n);
        canJump[0]=true;
        for (int j=0;j<n;j++) {
            if (!canJump[j]) continue;
            i = max(j+minJump,i);
            while (i<n && i<=j+maxJump) {
                if (s[i]=='0') canJump[i]=true;
                i++;
            }
        }
        return canJump[n-1];
    }
};