class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum=prices[0],minimum=prices[0];
        int profit=0;
        for (int i=1;i<prices.size();i++) {
            profit = max(prices[i]-minimum , profit);
            minimum=min(prices[i],minimum); 
        }
        return profit;
    }
};
