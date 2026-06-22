class Solution {
public:
    
    int dijkstra(int src,int des,vector<vector<int>>& adj) {
        vector<int> dis(adj.size(),1e9);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d>dis[node]) continue;
            for (auto x:adj[node]) {
                if (d+1<dis[x]) {
                    pq.push({d+1,x});
                    dis[x]=d+1;
                }
            }
        }
        return dis[des];
    }

    int ladderLength(string begin, string end, vector<string>& words) {
        int n=words.size();
        int w=begin.size();
        vector<vector<int>> adj(n);
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                int d=0;
                for (int k=0;k<w;k++) {
                    if (words[i][k]!=words[j][k]) d++;
                }
                if (d==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> beginNext;
        for (int i=0;i<n;i++) {
            int d=0;
            for (int k=0;k<w;k++)
                if (words[i][k]!=begin[k]) d++;
            if (d==1)
                beginNext.push_back(i);
        }
        if (beginNext.size()==0) return 0;
        int endIndex=-1;
        for (int i=0;i<n;i++) {
            if (words[i]==end) {
                endIndex=i;
                break;
            }
        }
        if (endIndex==-1) return 0;
        int ans=1e9;
        for (auto x:beginNext) {
            if (x==endIndex) return 2;
            int d=dijkstra(x,endIndex,adj);
            if (d<1e9) ans=min(ans,d+2);
        }
        return ans==1e9?0:ans;
    }
};
