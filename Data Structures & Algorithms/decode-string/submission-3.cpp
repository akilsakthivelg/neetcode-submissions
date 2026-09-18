class Solution {
public:
    string decodeString(string s) {
        string ans;
        stack<string> stk;
        int i=0;
        int n=s.size();
        while (i<n) {
            string k;
            while (i<n && s[i]>='a' && s[i]<='z') {
                k+=s[i++];
            }
            if (k.size()!=0) {
                if (!stk.empty() && stk.top()[0]>='a' && stk.top()[0]<='z') {
                    k=stk.top()+k;
                    stk.pop();
                } stk.push(k);
            }
            if (i<n && s[i]=='[') i++;
            string num;
            while (i<n && s[i]>='0' && s[i]<='9') num+=s[i++];
            if (num.size()) {
                stk.push(num);
            }
            if (i<n && s[i]==']') {
                i++;
                string str=stk.top(); stk.pop();
                int t = stoi(stk.top()); stk.pop();
                string p;
                while (t--) p+=str;
                if (!stk.empty() && stk.top()[0]>='a' && stk.top()[0]<='z') {
                    p=stk.top()+p;
                    stk.pop();
                }
                stk.push(p);
            }
        }
        while (!stk.empty()) {
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};