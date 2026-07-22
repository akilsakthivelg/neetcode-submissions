class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        for (int i=0;i<s.size();i++) {
            ans+=m[s[i]];
            if (i+1<s.size()) {
                if (s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')) ans-=2;
                if (s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')) ans-=20;
                if (s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')) ans-=200;
            }
        }
        return ans;
    }
};