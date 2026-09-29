class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a,'a'});
        if (b) pq.push({b,'b'});
        if (c) pq.push({c,'c'});
        string ans;
        while (pq.size()) {
            auto [c,ch] = pq.top();
            pq.pop();
            int n=ans.size();
            if (n>=2 && ans[n-1]==ch && ans[n-2]==ch) {
                if (pq.size()==0) return ans;
                auto [nc,nch] = pq.top();
                pq.pop();
                ans.push_back(nch);
                nc--;
                if (nc) pq.push({nc,nch});
            } else {
                ans.push_back(ch);
                c--;
            }
            if (c) pq.push({c,ch});
        }
        return ans;
    }
};