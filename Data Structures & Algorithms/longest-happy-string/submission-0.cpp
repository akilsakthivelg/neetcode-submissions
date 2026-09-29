class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a,'a'});
        if (b) pq.push({b,'b'});
        if (c) pq.push({c,'c'});
        while (pq.size()) {
            int n=ans.size();
            auto [c,ch] = pq.top();
            pq.pop();
            if (n>1 && ans[n-1]==ch &&ans[n-2]==ch) {
                if (pq.size()==0) break;
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