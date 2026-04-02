class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int rmax=prices[n-1];
        for (int i=n-2;i>=0;i--) {
            rmax=max(prices[i],rmax);
            ans=max(ans,rmax-prices[i]);
        }
        return ans;
    }
};
