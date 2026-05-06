class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0)) return -1;
        
        int t=0;
        int n=gas.size();
        int s=0;
        for (int i=0;i<n;i++) {
            t+=(gas[i]-cost[i]);
            if (t<0) {
                s=i+1;
                t=0;
            }
        }
        return s;
    }
};
