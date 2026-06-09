class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        unordered_map<int,int> m;
        
        for (int i=0;i<queries.size();i++) {
            m[queries[i]]=i;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int i=0;
        vector<int> ans=queries;
        sort(queries.begin(),queries.end());
        for (auto q:queries) {
            while (i<intervals.size() && intervals[i][0]<=q) {
                pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second<q) pq.pop();
            if (pq.empty()) m[q]=-1;
            else m[q]=pq.top().first;
        }
        for (auto &x:ans) {
            x=m[x];
        }
        return ans;
    }
};
