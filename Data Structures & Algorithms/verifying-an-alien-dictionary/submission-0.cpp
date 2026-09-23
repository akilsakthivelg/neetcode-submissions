class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for (int i=0;i<26;i++) m[order[i]]=i;
        for (int i=1;i<words.size();i++) {
            int a=0;
            while (a<words[i-1].size() && a<words[i].size()) {
                if (m[words[i-1][a]]>m[words[i][a]]) return false;
                if (m[words[i-1][a]]<m[words[i][a]]) break;
                a++;
            }
            if (a==words[i].size() && words[i-1].size()>words[i].size()) return false;
        }
        return true;
    }
};