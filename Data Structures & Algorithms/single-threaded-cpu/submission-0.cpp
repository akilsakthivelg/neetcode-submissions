class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for (int i=0;i<n;i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int> ans;
        int i=0;
        int t=tasks[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        while (!pq.empty() || i<n) {
            while (i<n && t>=tasks[i][0]) {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if (pq.empty()) t=tasks[i][0];
            else {
                t+=pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};