class Solution {
public:

    int helper(vector<int>& arr) {
        int a,b;
        a=b=0;
        for (auto x:arr) {
            int temp = max(x+a,b);
            a=b;
            b=temp;
        }
        return max(a,b);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        if (n==3) return max({nums[0],nums[1],nums[2]});
        vector<int> temp1;
        for (auto x:nums) temp1.push_back(x);
        temp1.pop_back();
        vector<int> temp2;
        for (int i=1;i<n;i++) temp2.push_back(nums[i]);
        return max(helper(temp1),helper(temp2));
    }
};
