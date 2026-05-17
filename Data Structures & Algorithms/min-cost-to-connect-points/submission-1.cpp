class Solution {
public:
    int distance(vector<int> &a,vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<int> visited(n);
        pq.push({0,0});
        while (!pq.empty()) {
            int dis=pq.top().first;
            int des=pq.top().second;
            pq.pop();
            if (visited[des]) continue;
            ans+=dis;
            visited[des]=true;
            for (int i=0;i<n;i++) {
                if (!visited[i]) {
                    pq.push({distance(points[des],points[i]),i});
                }
            }
        }
        return ans;

    }
};
