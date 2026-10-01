class Solution {
public:

    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> v,d;
        for (auto x:deadends) d.insert(x);
        
        if (d.count("0000")) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while (!q.empty()) {
            auto [s,c] = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                string t=s;
                if (t[i]=='0') t[i]='9';
                else t[i]--;
                if (!d.count(t) && !v.count(t)) {
                    if (t==target) return c+1;
                    q.push({t,c+1});
                    v.insert(t);
                }
                t=s;
                if (t[i]=='9') t[i]='0';
                else t[i]++;
                if (!d.count(t) && !v.count(t)) {
                    if (t==target) return c+1;
                    q.push({t,c+1});
                    v.insert(t);
                }
            }
        }
        return -1;
    }
};