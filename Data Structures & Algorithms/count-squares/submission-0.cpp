class CountSquares {
public:

    unordered_map<int,unordered_map<int,int>> a;

    CountSquares() {}
    
    void add(vector<int> point) {
        a[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0];
        int y1 = point[1];
        for (auto &[y2,cnt]:a[x1]) {
            int side = y2-y1;
            if (side==0) continue;
            int x3 = x1-side;
            int x4 = x1+side;
            res+=cnt*a[x3][y2]*a[x3][y1];
            res+=cnt*a[x4][y2]*a[x4][y1];
        }
        return res;
    }
};
