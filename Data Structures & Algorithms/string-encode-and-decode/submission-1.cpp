class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for (auto x:strs) {
            ans+=to_string(x.size()) + '#' + x;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while (i<s.size()) {
            string l="";
            while (s[i]!='#') l+=s[i++];
            i++;
            int n=stoi(l);
            string t="";
            while (n--) {
                t+=s[i++];
            }
            ans.push_back(t);
        }
        return ans;
    }
};
