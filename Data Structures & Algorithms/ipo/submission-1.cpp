class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> min;
        priority_queue<int> max;
        for (int i=0;i<n;i++) min.push({capital[i],profits[i]});
        while (k--) {
            while (min.size() && min.top().first<=w) {
                max.push(min.top().second);
                min.pop();
            }
            if (max.size()) {
                w+=max.top();
                max.pop();
            }
        }
        return w;
    }
};