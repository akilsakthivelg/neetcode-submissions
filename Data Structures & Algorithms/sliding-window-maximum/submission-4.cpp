class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        int i;
        for (i=0;i<k;i++) {
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for (i=i;i<nums.size();i++) {
            while (!pq.empty() && pq.top().second <= i-k) pq.pop();
            pq.push({nums[i],i});
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
