class Solution {
public:
    string simplifyPath(string path) {
        string s;
        s+=path[0];
        for (int i=1;i<path.size();i++) {
            if (path[i]=='/' && s[s.size()-1]=='/') continue;
            else s+=path[i];
        }
        while (s.size()!=0 && s[s.size()-1]=='/') s.pop_back();
        int i=0;
        vector<string> v;
        while (i<s.size()) { 
            string k;
            i++;
            while (i<s.size() && s[i]!='/') k+=s[i++];
            if (k==".") continue;
            if (k=="..") {
                if (v.size()) v.pop_back();
                continue;
            }
            v.push_back(k);
        }
        string ans;
        for (auto x:v) {
            ans+="/";
            ans+=x;
        }
        if (ans=="") ans="/";
        return ans;
    }
};