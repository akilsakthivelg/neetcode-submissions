class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> pq;
        int i=0;
        for (i=i;i<k;i++) pq.push(nums[i]);
        while (i<nums.size()) {
            pq.push(nums[i++]);
            pq.pop();
        }
        return pq.top();
    }
};
