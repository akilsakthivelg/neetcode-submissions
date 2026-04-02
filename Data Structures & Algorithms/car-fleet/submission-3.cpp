class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n=pos.size();
        for (int i=0;i<n;i++) {
            cars.push_back({pos[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());

        stack<int> stk;

        for (int i=0;i<n;i++) {
            if (!stk.empty()) {
                double curr_t = 1.0*(target-cars[i].first)/cars[i].second;
                double prev_t = 1.0*(target-cars[stk.top()].first)/cars[stk.top()].second;
                if (curr_t > prev_t) stk.push(i);
            }
            else stk.push(i);
        }
        return stk.size();
    }
};
