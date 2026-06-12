class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a,b,c;
        a=b=c=false;
        for (auto x:triplets) {
            if (x[0]<=target[0] && x[1]<=target[1] && x[2]<=target[2]) {
                if (x[0]==target[0]) a=true;
                if (x[1]==target[1]) b=true;
                if (x[2]==target[2]) c=true;
            }
        }
        return a&&b&&c;
    }
};
