class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        vector<int> ans;
        for (int i=0;i<k-1;i++) {
            m[nums[i]]+=1;
        }
        for (int i=k-1;i<n;i++) {
            m[nums[i]]++;
            ans.push_back(m.rbegin()->first);
            if (m[nums[i-k+1]]==1) m.erase(nums[i-k+1]);
            else m[nums[i-k+1]]--;
        }
        return ans;
    }
};
