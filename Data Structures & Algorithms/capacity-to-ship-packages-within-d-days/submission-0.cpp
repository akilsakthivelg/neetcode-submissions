class Solution {
public:

    bool canFit(vector<int>& weights,int days,int weight) {
        int w = 0, d=0;
        for (auto &x:weights) {
            if (w+x>weight) {
                w=x;
                d++;
            } else w+=x;
        }
        d++;
        return d<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int i=*max_element(weights.begin(),weights.end());
        int j=accumulate(weights.begin(),weights.end(),0);
        while (i<j) {
            int m=i+(j-i)/2;
            if (canFit(weights,days,m)) j=m;
            else i=m+1;
        }
        return i;

    }
};