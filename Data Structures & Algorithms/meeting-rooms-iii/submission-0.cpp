class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for (int i=0;i<n;i++) pq.push({0,i});
        vector<int> c(n);
        for (auto x:m) {
            int s=x[0],e=x[1];
            while (pq.top().first<s) {
                auto [old_e,room] = pq.top();
                pq.pop();
                pq.push({s,room});
            }
            auto [old_e,room] =pq.top();
            pq.pop();
            pq.push({old_e+(e-s),room});
            c[room]++;
        }
        int mx=*max_element(c.begin(),c.end());
        for (int i=0;i<n;i++) if (c[i]==mx) return i;
        return -1;
    }
};