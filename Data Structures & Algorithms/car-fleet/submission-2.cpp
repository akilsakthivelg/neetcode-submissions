class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();
        stack<int> stk;
        vector<pair<int,int>> cars;
        for (int i=0;i<n;i++) {
            cars.push_back({pos[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        for (int i=0;i<n;i++) {
            if (!stk.empty()) {
                double t = 1.0*(target - cars[i].first)/cars[i].second;
                double pt= 1.0*(target - cars[stk.top()].first)/cars[stk.top()].second;
                if (t > pt) stk.push(i);
            } else {
                stk.push(i);
            }
        }
        return stk.size();
    }
};
