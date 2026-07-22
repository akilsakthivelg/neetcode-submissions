class Solution {
public:
    string addBinary(string a, string b) {
        while (a.size()!=b.size()) {
            if (a.size()<b.size()) a='0'+a;
            else b='0'+b;
        }
        int i=a.size()-1;
        int c=0;
        string ans="";
        while (i>=0) {
            int v = a[i] - '0' + b[i] - '0' + c;
            ans=(v%2?'1':'0')+ans;
            c=v/2;
            i--;
        }
        if (c) ans='1'+ans;
        return ans;
    }
};