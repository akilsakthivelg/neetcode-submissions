class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int i=0,j=1;
        while (i<prices.size() && j<prices.size()) {
            if (prices[i]<prices[j]) {
                maxProfit=max(maxProfit,prices[j]-prices[i]);
            } else {
                i=j;
            }
            j++;
        }
        return maxProfit;
    }
};
