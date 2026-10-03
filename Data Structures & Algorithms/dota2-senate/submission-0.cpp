class Solution {
public:
    string predictPartyVictory(string senate) {
        int c=0,i=0;
        while (i<senate.size()) {
            if (senate[i]=='R') {
                if (c<0) senate.push_back('D');
                c++;
            } else {
                if (c>0) senate.push_back('R');
                c--;
            }
            i++;
        }
        return c>0?"Radiant":"Dire";
    }
};