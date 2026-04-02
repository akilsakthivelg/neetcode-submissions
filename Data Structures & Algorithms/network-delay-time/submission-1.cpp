class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjL(n+1);
        for (auto x:times) {
            adjL[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<bool> visited(n+1);
        visited[0]=true;
        pq.push({0,k});
        // visited[k]=true;
        int ans=0;
        while (!pq.empty()) {
            int s=pq.size();
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (!visited[node]) ans=max(ans,t);
            visited[node]=true;
            for (auto x:adjL[node]) {
                if (!visited[x.first]) {
                    pq.push({t+x.second,x.first});
                    // visited[x.first]=true;
                }
            }
        }
        for (auto x:visited) if (!x) return -1;
        return ans;
    }
};
