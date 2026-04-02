class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minimum = prices[0];
        for (auto x:prices) {
            minimum=min(minimum,x);
            ans=max(ans,x-minimum);
        }
        return ans;
    }
};
